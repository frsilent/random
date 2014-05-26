#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
	//int
	printf( "3+4 %d \n", 3 + 4);
	printf( "3-4 %d \n", 3 - 4);
	printf( "3*4 %d \n", 3 * 4);
	printf( "3/4 %d \n", 3 / 4);
	printf( "3%%4 %d \n", 3 % 4);
	printf( "3+4*6 %d \n", 3 + 4 * 6);
	printf( "(3+4)*6 %d \n", (3 + 4) * 6);
	//long
	printf( "9999L*9999L %ld \n", 9999L * 9999L);
	//long long
	printf( "999999LL*999999LL %lld \n",
		   999999LL * 999999LL);
	//double
	printf( "5.6+3.2 %lg \n", 5.6 + 3.2);
	printf( "5.6-3.2 %lg \n", 5.6 - 3.2);
	printf( "5.6*3.2 %lg \n", 5.6 * 3.2);
	printf( "5.6/3.2 %lg \n", 5.6 / 3.2);
	//float
	printf( "5.6E+20f*0.234E+25f %lg \n", 5.6E+20f * 0.234E+25f);
	printf( "5.6E+20*0.234E+25f %lg \n", 5.6E+20 * 0.234E+25f);
}