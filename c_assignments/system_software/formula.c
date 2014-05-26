#include <stdio.h>
int main(void) { double x, stop, increment;
x=11.0; stop=51.0; increment=10.0;
printf("C\tF\n");
for (; x <= stop; x=x+increment) {
	printf("%lg\t%lg\n", x, (1.8*x + 32.0));
}
}
