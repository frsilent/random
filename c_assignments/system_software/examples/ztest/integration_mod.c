#include <stdio.h>
#include <assert.h>
#include <math.h>

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
double sqrt(double x) {
    return sqrt(x);
    }

/*
Modify to calculate the integral from 0 to N+1
of sqrt(x) where N is the last digit of your student id.
What is the answer?*/
int main(void) {
	printf("%g\n",dIntegrate(sqrt,0.0,5.0));
}
