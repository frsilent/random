#define SIZE 3
#include <stdio.h>
#include "test.h"
int main(int argc, char *argv[]) {
	int i, a[SIZE];
	for (i=0;i<SIZE;i++) a[i]=i*SIZE;
	#ifdef DEBUG
		for (i=0;i<SIZE;i++) printf("a[%d] = %d\n", i, a[i]);
	#endif
	printf("Power of 4 for 3 = %d, 1 = %d, 3 = %d\n", POWER4(2+1), POWER4(1), POWER4(3));
	return 0;
}
