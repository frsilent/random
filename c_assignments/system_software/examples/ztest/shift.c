#include <stdio.h>
typedef struct {
	unsigned int x:4,y:8,z:16,r:1;
} B;
typedef union {
	int x;
	B y;
} Q;
int main(void) {
	Q z;
	int allbits;
	z.y.x=4; z.y.y=3; z.y.z=2; z.y.r=1;
	allbits = z.x;
	printf("%x\n",allbits);
	printf("x=%d y=%d r=%d\n", (allbits>>0)&0xf, (allbits>>4)&0xff, allbits&0x10000000);
}