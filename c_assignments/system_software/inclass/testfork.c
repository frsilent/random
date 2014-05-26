#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
	int child=fork();
	if(child!=0) printf("%d is parent\n",child);
	else {
		printf("%d is child before\n",child);
		execl("/home/frsilent/cook/inclass/test", "bob", "sally", "bird",NULL);
		printf("after\n");
	}
}
