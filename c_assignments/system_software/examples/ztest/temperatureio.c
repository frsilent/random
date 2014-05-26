#include <stdio.h>
#include <string.h>
double temperature;
char convention; //KFC

char * temperature_sprintf(char output[] /*out*/, int maxBytes) {
	char s[50];
	sprintf(s, "%lg%c", temperature, convention);
	if (strlen(s) >= maxBytes) { return NULL; }
	strcpy(output, s);
	return output;
}

int temperature_sscanf(char input[]) {
	int i;
	i = sscanf(input, "%lg%c", &temperature, &convention);
	if (i != 2) { return -1; }
	return 1;
}

int main(void) {
	char s[]="   38.6F";
	printf("%d\n", temperature_sscanf(s));
	printf("%s\n", temperature_sprintf(s, sizeof(s)));
}