#include <stdio.h>
typedef struct {
	int x:4;
	unsigned int y:8;
	unsigned int z:16;
} B;
typedef union {
	int x;
	B y;
} Q;
int main(void) {
	Q z;
	z.x=0x12345678;
	printf("%x %x %x \n",z.y.x,z.y.y,z.y.z);
}