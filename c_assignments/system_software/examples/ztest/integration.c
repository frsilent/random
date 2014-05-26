#include <stdio.h>
#include <assert.h>

double dIntegrate(double df(double), double x0, double x1) {
	double i, area=0.0;
	assert(x1 > x0);
	for (i=x0; x0<x1; x0+=0.001) {
		/*height*width*/
		area +=   df(x0)*0.001;
	}
	return area;
}

double xcubed(double x) {
	return x*x*x;
}

int main(void) {
	printf("%g\n",dIntegrate(xcubed,2.0,5.0));
}