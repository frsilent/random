#include <stdio.h>
#include <assert.h>
double dX1, dY1, dX2, dY2, dX3, dY3;

int main(void) {
	int n;
	printf("type 6 X-Y points>");
	n = scanf("%lg%lg%lg%lg%lg%lg", &dX1, &dY1, &dX2, &dY2, &dX3, &dY3);
	assert(n == 6);
	//3 points must be disjoint
	assert((dX1 != dX2) || (dY1 != dY2));
	assert((dX1 != dX3) || (dY1 != dY3));
	assert((dX2 != dX3) || (dY2 != dY3));
	//2 of 3 points must have the
	//  same Y coordinate to be a vertical line
	//3rd point must have same X coordinate
	//  with one of other two to be horizontal
	if (dY1 == dY2) { //vertical?
		assert((dX1 == dX3) || (dX2 == dX3));
	} else if (dY2 == dY3) { //vertical?
		assert((dX2 == dX1) || (dX3 == dX1));
	} else if (1) {
		assert(dY1 == dY3); //must be true
		assert((dX1 == dX2) || (dX3 == dX2));
} /*if*/
}