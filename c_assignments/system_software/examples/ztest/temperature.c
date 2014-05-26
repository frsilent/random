#include "temperature.h"
#include <stdio.h>
char * temperature_sprintf(pTemperature t/*in*/, char output[] /*out*/, int maxBytes) {
	char s[50];
	sprintf(s, "%lg%c", t->temp, (*t).kind);
	if (strlen(s) >= maxBytes) { return NULL; }
	strcpy(output, s);
	return output;
}
void temperature_open(pTemperature t/*out*/, double temp, char system) {
	t->temp = temp;
	(*t).kind = system;
}