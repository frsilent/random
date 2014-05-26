#include <stdio.h>
int x;
void xPlusOne() {
	x = x+1;
	return;
}

int main(void) {
	x = 5;
	xPlusOne();
	xPlusOne();
	xPlusOne();
	printf("x = %d\n", x);
}