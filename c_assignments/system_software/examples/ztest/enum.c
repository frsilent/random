#include <stdio.h>
typedef enum {Red,Orange=5,Yellow,Green=3,Blue=-5} Color;
int main(void)
{
	Color pants, shirt, tie;
	pants=Red; shirt=Yellow; tie=Green;
	printf("pants=%d shirt=%d tie=%d\n",pants,shirt,tie);
}