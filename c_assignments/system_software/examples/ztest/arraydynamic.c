#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double * adScanf(char format[], int *N /*out*/) {
	//returns count of values read
	//returns 0 for end-of-data
	double *values;
	int i, n;
	values = (double *)calloc(5, sizeof(double));
	assert( values != NULL);
	n = 5;
	for (i=0;  ; i++) {
		if (scanf(format, &values[i]) != 1) {
			break;
		} /*if*/
		if (i == n-1) { //need more?
			values = (double *)realloc(values, sizeof(double)*(n+5));
			assert(values != NULL);
			n+=5;
		} /*if*/
	} /*for*/
	if (i < n) {
		values = (double *)realloc(values, sizeof(double)*i);
		assert(values != NULL);
	} /*if*/
	*N = i;
	return values;
}

void adPrintf(char format[], double values[], int N) {
	//format is applied to each element
	int i;
	for (i=0; i<N; i++) {
		printf(format, values[i]);
	} /*for*/
}

int main(void) {
	double *array;
	int size;
	array = adScanf("%lg", &size);
	adPrintf("%lg ", array, size);
printf("\n");
if (size!=0) free(array);
}
