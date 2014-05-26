#include <stdio.h>
#include <stdarg.h>

int ivSum(int count, ...) {
	va_list argp;
	int sum;
	sum=0;
	va_start(argp, count);
	while (count--) {
		sum += va_arg(argp,int);
	} /*for*/
	va_end(argp);
	return sum;
}

int main(void) {
	printf("%d %d\n",ivSum(3,9,5,12),ivSum(2,-8,-7));
}