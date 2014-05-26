#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {
	int j = 0,sum=0;
	int z[] = {1,2,3,4,5,0};

//Hint: x[i]==*(x+i)	
//find the sum
	for(j=0;z[j];j++) sum += *(z+j);
	
//print the array
	for(j=0;j<6;j++) {
		printf("%d\n",z[j]);
	}
	printf("sum:%d\n",sum);
}
