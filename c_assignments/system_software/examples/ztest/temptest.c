#include "temperature.h"
#include <stdio.h>
int main(void) {
	char s[30];
	Temperature cent, fahr;
	
	temperature_open(&cent, 100.0, 'C');
	temperature_open(&fahr, 212.0, 'F');
	printf("%s\n", temperature_sprintf(&cent,s,sizeof(s)));
	printf("%s\n", temperature_sprintf(&fahr,s,sizeof(s)));
}