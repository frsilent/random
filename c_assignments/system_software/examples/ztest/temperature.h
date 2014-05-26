#if defined(__TEMPERATURE__)
#define __TEMPERATURE__
typedef struct _temperature {
	double temp;
	char kind;
} Temperature;
typedef Temperature *pTemperature;

char * temperature_sprintf(pTemperature t/*in*/, char output[] /*out*/, int maxBytes);

void temperature_open(pTemperature t/*out*/, double temperature, char system/*KCF*/);
#endif