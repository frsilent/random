#include <stdio.h>
typedef struct _temperature {
	double temp;
	char kind;
} Temperature;
Temperature cent;
struct _temperature fahr;

char * temperature_sprintf(Temperature t/*in*/, char output[] /*out*/, int maxBytes) {
	char s[50];
	sprintf(s, "%lg%c", t.temp, t.kind);
	if (strlen(s) >= maxBytes) { return NULL; }
	strcpy(output, s);
	return output;
}
void temperature_open(struct _temperature t/*out*/, double temp, char system) {
	t.temp = temp;
	t.kind = system;
}

int main(void) {
	char s[30];
	temperature_open(cent, 100.0, 'C');
	temperature_open(fahr, 212.0, 'F');
	printf("%s\n", temperature_sprintf(cent,s,sizeof(s)));
	printf("%s\n", temperature_sprintf(fahr,s,sizeof(s)));
}