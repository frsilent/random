#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
	//int
	printf( " %d \n", -56);
	//octal int
	printf( " %d \n", 056);
	//hexadecimal int
	printf( " %d \n", 0XCAB);
	//long
	printf( " %ld \n", 123456789L);
	//long long
	printf( " %lld \n", 123456789123456789LL);
	//float
	printf( " %g \n", 5.6f);
	//double
	printf( " %lg \n", 5.6E+56);
	//char
	printf( " %c \n", 'X');
	/* char [ ] or a string */
	printf( " %s \n", "Hello World!!");
	printf( " Hello World!!  \n");
}