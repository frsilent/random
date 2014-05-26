#include <stdio.h>

int main(void) {
	int A=27;
	int *B = &A;
	printf("B=%lx *B=%d\n", B, *B);
	*B = 99;
	printf("B=%lx *B=%d\n", B, *B);
	B = NULL;
	printf("B=%lx *B=%d\n", B, *B);
}