#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int *imMultiply(int *A /*inout*/, int aM, int aN, int *B /*in*/, int bM, int bN) {
	//B must be aNx?
	//result is aMxbN
	int i,j,k,temp;
	int *C;
	C = (int *)calloc(sizeof(int),aM*bN);
	assert(C!=NULL);
	assert(aN==bM);
	for (i=0; i<aM; i++) {
		for (j=0; j<bN; j++) {
			temp = 0;
			for (k=0; k<aN; k++) {
				temp += *(A+i*aN+k) * *(B+k*bN+j);
			} /*for*/
			*(C+i*bN+j) = temp;
		} /*for*/
	} /*for*/
	return C;
}

void imPrintf(char format[], int *A /*in*/, int aM, int aN) {
	int i,j;
	for (i=0; i<aM; i++) {
		for (j=0; j<aN; j++) {
			printf(format, *(A+i*aN+j));
		} /*for*/
		printf("\n");
	} /*for*/
}

int main(void) {
	int x[3][4]={1,2,3,4,5,6,7,8,9,1,2,3};
	int y[4][3]={9,8,7,6,5,4,3,2,1,9,8,7};
	int *z;
	imPrintf("%d\t",&x[0][0],3,4);
	imPrintf("%d\t",&y[0][0],4,3);
	z=imMultiply(&x[0][0],3,4,&y[0][0],4,3);
imPrintf("%d\t",z,3,3);
free(z);
}