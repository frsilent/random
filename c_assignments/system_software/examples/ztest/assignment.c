#include <stdio.h> 
int main(void) {
	int x, y=3+4, Z;
	long L = 8765L;
	double PI = 3.14, E = 2.78;
	char ch = 'M';
	
	x = y;
	L = 8765L;
	PI = PI * E;
	ch = 'M';
	printf("x=%d L=%ld PI=%lg ch=%c\n", x, L, PI, ch);
}