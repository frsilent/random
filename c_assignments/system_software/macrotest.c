#include "maxmin.h"
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
	int x = 5*max(3,4);
	int y = 5*min(3,4);
	printf("%d * 5 = %d\n", max(3,4), x); //This should read 4 * 5 = 20
	printf("%d * 5 = %d\n", min(3,4), x); //This should read 3 * 5 = 15
}
