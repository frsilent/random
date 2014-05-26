#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 100

int main(void) {
	char tmp[64];
	FILE *f;
	int i,j,k,exchange;
	
//	GENERATE A FILE OF RANDOM VALUES
	
	tmpnam(tmp);
	f = fopen(tmp, "w+");
	assert(f!=NULL);
	printf("writing %s\n", tmp);
	for (i=0; i<N; i++) {
		j = rand()%N;
		j = fwrite(&j, sizeof(int), 1, f);
		assert(j>0);
	}
	
//	LOOP UNTIL NO MORE EXCHANGES
	
	exchange = 1;
	while (exchange) {
		fseek(f, 0, SEEK_SET);
		exchange=0;
		for (;;) {
			if (fread(&j, sizeof(int), 1, f)<=0) { break; }
			if (fread(&k, sizeof(int), 1, f)<=0) { break; }
			if (j > k) {
				exchange = 1;
				fseek(f, -2*sizeof(int), SEEK_CUR);
				assert(fwrite(&k, sizeof(int), 1, f)>0);
				assert(fwrite(&j, sizeof(int), 1, f)>0);
			} /*if*/
			fseek(f, -1*sizeof(int), SEEK_CUR);
		} /*for*/
	} /*while*/
	fclose(f);
	
//	WRITE SORTED OUTPUT, DELETE TEMP FILE
	
	f = fopen(tmp, "r");
	assert(f!=NULL);
	for (i=0; i<N; i++) {
		assert(fread(&j, sizeof(int), 1, f)>0);
		printf("%d ",j);
}
printf("\n");
fclose(f);
remove(tmp);
}
