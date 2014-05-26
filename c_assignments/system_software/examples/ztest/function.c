#include <stdio.h>
int x;
int xPlusOne() {
	x++;
	return x+1;
}

int main(void) {
	int a,b,c;
	x = 5;
	a = xPlusOne();
	b = xPlusOne();
	c = xPlusOne();
	printf("a,b,c = %d,%d,%d\n", a,b,c);
}