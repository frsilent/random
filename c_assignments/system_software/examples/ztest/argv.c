#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[], char *envp[]) { //convert C to F
	double dCentigrade;
	
	dCentigrade = atof(argv[1]);
	printf("%g\n", (1.8*dCentigrade+32.0));
}