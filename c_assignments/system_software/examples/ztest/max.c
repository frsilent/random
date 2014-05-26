#include <stdio.h>
int max(int a, int b) {
	//returns maximum of a or b
	if (a >= b) {
		return a;
	} /*if*/
	return b;
}

int main(void) {
	printf("%d %d\n",max(5,6),max(3,-12));
}