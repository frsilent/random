#include <stdio.h>

void aiPrintf(char format[], int values[], int N) {
	//format is applied to each element
	int i;
	for (i=0; i<N; i++) {
		printf(format, values[i]);
	} /*for*/
}

int aiScanf(char format[], int values[], int N) {
	//returns count of values read
	//returns -1 for end-of-data unless N==0
	int i;
	for (i=0; i<N; i++) {
		if (scanf(format, &values[i]) != 1) {
			break;
		}
	} /*for*/
	if (i!=0) {
		return i;
	} /*if*/
	return -(N!=0);
}

int main(void) {
	int x[10];
	int nX;
	printf("enter 0 to 10 integers>");
	nX = aiScanf("%d", x, sizeof(x)/sizeof(int));
	if (nX < 0) {
		printf("no data"); nX=0;
	} /*if*/
	aiPrintf("%d ", x, nX);
printf("\n");
}
