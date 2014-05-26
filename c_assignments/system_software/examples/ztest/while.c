#include <stdio.h>
int main(int argc, char *argv[], char *envp[]) { //cubes 5-50
	int iNumber=5;
	while (iNumber <= 50) {
		printf("%d\t%d\n", iNumber, iNumber*iNumber*iNumber);
		iNumber += 5;
	} /*while*/
}