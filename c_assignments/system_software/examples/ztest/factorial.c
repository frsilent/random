#include <stdio.h>

//Prototype, heading with ;
int factorial(int f);

int main(void) {
	int i, f=1;
	printf("%d! = %d\n",5,factorial(5));
	for (i=1; i<=5; i++) {
		f *= i;
	} /*for*/
	printf("%d! = %d\n",5,factorial(5));
}

//Definition occurs after use!
int factorial(int f) {
	//returns factorial of f
	if (f < 2) {
		return 1;
	} /*if*/
	return f*factorial(f-1);
}