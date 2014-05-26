#include <stdio.h>
int main (int argc, char *argv[], char *envp[]) {
	char firstDigit = '6';
	printf("%c\n", firstDigit);
	short shortVar = 6544;
	printf("%i\n", shortVar);
	unsigned short uShortVar = 6544;
	printf("%u\n", uShortVar);
	int normalInt = 6544;
	printf("%i\n", normalInt);
	int longInt = 6544;
	printf("%ld\n", longInt);
	char* SIDstring = "ABCD";
	printf("%c+%c-%c*%c/2'%8\n",SIDstring[0],SIDstring[1],SIDstring[2],SIDstring[3]);
	printf("%c&%c|%c^%c\n",SIDstring[0],SIDstring[1],SIDstring[2],SIDstring[3]);
	printf("%c<<%c+%c>>%c\n",SIDstring[0],SIDstring[1],SIDstring[2],SIDstring[3]);
	SIDstring = "6544";
	int A, B, C, D;
	A = scanf(&SIDstring[0]);
	printf("%i\n",A);
}
