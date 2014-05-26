#include <stdio.h>
int main(void) {
	//output table heading
	printf("x\tx^2\tx^3\n"); 
	//output table values
	printf("%d\t%d\t%d\n", 1, (1*1), (1*1*1));
	printf("%d\t%d\t%d\n", 2, (2*2), (2*2*2));
	printf("%d\t%d\t%d\n", 3, (3*3), (3*3*3));
	printf("%d\t%d\t%d\n", 4, (4*4), (4*4*4));
	printf("%d\t%d\t%d\n", 5, (5*5), (5*5*5));
}