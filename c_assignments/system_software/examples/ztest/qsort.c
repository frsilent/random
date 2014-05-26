#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int check(const void *left, const void *right) {
	int *pLeft, *pRight;
	pLeft = (int *)left;
	pRight = (int *)right;
	if (*pLeft == *pRight) { return 0; }
	if (*pLeft < *pRight) { return -1; }
	return +1;
}

int main(void) {
	int x[]={9,3,5,8,7,1,6,4,2,0};
	int value=3, *pInt;
	qsort(x, sizeof(x)/sizeof(int), sizeof(int), check);
	aiPrintf("%d ",x, 10);
	printf("\n");
	pInt=bsearch(&value, x, sizeof(x)/sizeof(int), sizeof(int), check);
	assert(pInt != NULL);
	printf("index=%d for 3\n",pInt-x);
}