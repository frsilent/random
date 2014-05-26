#include<stdio.h>
#include<pthread.h>

void *p(void *arg) {
	printf("arg=%d\n",(int)arg);
	pthread_exit((void *)99);
}

int main() {
	pthread_t x;
	void *r;
	pthread_create(&x,NULL,p,(void *)34);
	pthread_join(x,&r);
	printf("result=%d\n", (int)r);
	return 0;
}
