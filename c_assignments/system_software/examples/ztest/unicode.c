#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

int main(void) {
	int i;
	char narrow[] = "Ã¯Ã*Ã½\n";
	wchar_t wide[] = L"\u0222Ã¯Ã*Ã½\n";
	setlocale(LC_ALL, "");
	printf("printf narrow: %s\n", narrow);
	printf("narrow bytes:\n");
	for (i = 0; i< 5; ++i) {
		printf("%3d: %02X\n", i, narrow[i]);
	} /*for*/
	printf("fwide=%d\n", fwide (stdout, 1));
	
	wprintf(L"wprintf wide: %ls\n", wide);
	wprintf(L"wprintf narrow: %s\n", narrow);
	printf("printf wide: %ls\n", wide);
	printf("wide bytes:\n");
	for (i = 0; i< 8; ++i) {
		printf("%3d: %02X\n", i, *((unsigned char *)wide+i));
	} /*for*/
}