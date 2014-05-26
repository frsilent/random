#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) { //convert C to F
	char * sTarget; int iTarget=1;
	double dCentigrade;
	
	for ( ; argc > 1; argc=argc-1,iTarget=iTarget+1) {
		sTarget = argv[iTarget];
		
		dCentigrade = atof(sTarget);
		printf("%g\n", (1.8*dCentigrade+32.0));
		
} /*for*/
}