#include <stdio.h>
int main(void) {
	double x, stop, increment; 
	//stop must be bigger than start
	//change 11.0 to the desired start value
	x = 11.0;
	//change 51.0 to the stopping point
	stop = 51.0;
	//change 10.0 to the table increment 
	increment = 10.0; 
	//output table heading
	printf("C\tF\n");
	for ( ; x<=stop; x = x+increment) { 
		// table values
		printf("%lg\t%lg\n", x, (1.8*x+32.0)); 
	} /*for*/
} /*main*/