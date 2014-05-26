#include<iostream>
#include<cassert>
#include<pthread.h>
using namespace std;
#define SIZE 1000

int sum(int array[],int N) {
	int sum=0;
	for(;--N>=0;) sum += array[N];
	return sum;
}

typedef struct _args {
	int result;
	int N;
	int *array;
}	Args;

void *thread(void * arg) {
	Args *p=(Args *)arg;
	p->result=sum(p->array,0,p->N);
	cout<<"threat in"<<endl;
	return NULL;
}

int sum_p(int array[], int N) {
	pthread_t t[2];
	void *out;
	Args x[2];
	x[0].N=N/2;	x[0].array=&array[0];
	pthread_create(&t[0],NULL,thread,(void *)&x[0]);
	x[1].N=N/2;	x[1].array=&array[N/2];
	pthread_create(&t[1],NULL,thread,(void *)&x[1]);
	pthread_join(t[0],&out);
	pthread_join(t[1],&out);
	cout<<"thread out"<<endl;
	return x[0].result+x[1].result;
}

int main(int argc, char *argv[]) {
	int x[SIZE];
	int i;
	for (i=0;i<SIZE;i++) {x[i] = i+1;}
	assert(sum(x,0,SIZE) == (SIZE*(SIZE+1)/2));
	cout<<sum(x,0,SIZE)<<endl;
	assert(sum_p(x,SIZE)==(SIZE*(SIZE+1)/2));
}
