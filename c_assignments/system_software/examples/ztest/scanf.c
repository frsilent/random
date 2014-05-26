#include <stdio.h>
int main(void) { //convert C to F
	
	double dCentigrade;
	
	printf("enter a Centigrade number (Enter): ");
	scanf("%lg", &dCentigrade);
	printf("C\tF\n");
	printf("%lg\t%lg\n", dCentigrade, (1.8*dCentigrade+32.0));
}