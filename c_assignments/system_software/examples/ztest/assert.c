#include <stdio.h>
#include <assert.h>
int main(void) {
	int x, n;
	printf("type a # from 1 to 10>");
	n = scanf("%d", &x);
	assert(n == 1);
	assert((x >= 1) && (x <= 10));
	printf("thank you\n");
}