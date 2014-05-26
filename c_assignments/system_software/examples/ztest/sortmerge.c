#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 16 //POWER OF TWO
typedef enum {READ2,READRIGHT,READLEFT} Choices;
int main(void)
{
	char input[64], temp1[64], temp2[64];
	FILE *f, *ft1, *ft2;
	int i,j,k,t,m,n,o1,o2;
	Choices c;
	tmpnam(input);
	tmpnam(temp1);
	tmpnam(temp2);
	printf("\nwriting %s\n", input);
	printf("temp1= %s\n", temp1);
	printf("temp2= %s\n", temp2);
	
	f = fopen(input, "w+");
	assert(f!=NULL);
	ft1 = fopen(temp1, "w+");
	assert(ft1!=NULL);
	ft2 = fopen(temp2, "w+");
	assert(ft2!=NULL);
	//	GENERATE N NUMBERS TO SORT
	for (i=0; i<N; i++) {
		j = rand()%N;
		printf("%d ",j);
		j = fwrite(&j, sizeof(int), 1, f);
		assert(j>0);
	} /*for*/
	
	n=1;
	while (n<=N/2) { //REPEAT UNTIL ONLY 2 RUNS
		
		assert(fseek(f, 0, SEEK_SET)>=0);
		assert(fseek(ft1, 0, SEEK_SET)>=0);
		assert(fseek(ft2, 0, SEEK_SET)>=0);
		printf("N=%d\n",n);
		//	COPY RUNS OF N TO ALTERNATE FILES
		for ( ;; ) {
			for (k=0; k<n; k++) {
				if (fread(&j, sizeof(int), 1, f)<=0) { goto exit; }
				fwrite(&j, sizeof(int), 1, ft1);
			} /*for*/
			for (k=0; k<n; k++) {
				if (fread(&j, sizeof(int), 1, f)<=0) { goto exit; }
				fwrite(&j, sizeof(int), 1, ft2);
			} /*for*/
		} /*for*/
	exit:
		
		assert(fseek(f, 0, SEEK_SET)>=0);
		assert(fseek(ft1, 0, SEEK_SET)>=0);
		assert(fseek(ft2, 0, SEEK_SET)>=0);
		i=n; m=n;
		c=READ2;
		for ( ;; ) {
			switch (c) {
				case READ2:
					if (fread(&j, sizeof(int), 1, ft1)<=0) { goto exit2; }
				case READRIGHT:
					if (fread(&k, sizeof(int), 1, ft2)<=0) { goto exit2; }
				xxx:
					o1=j; o2=k;
					if (k<j) { o1=k; m--; c=READRIGHT; }
					else { i--; c=READLEFT; }
					fwrite(&o1, sizeof(int), 1, f);
					break;
				case READLEFT:
					if (fread(&j, sizeof(int), 1, ft1)<=0) { goto exit2; }
					goto xxx;
				default: assert(0);
			} /*switch*/
			if (i&&m) { continue; }
			// REPEAT ABOVE UNTIL ONE RUN IS EMPTY
			// THEN COPY THE OTHER RUN
			if (c==READRIGHT) { fwrite(&j, sizeof(int), 1, f); i--; }
			while (--i>=0) {
				if (fread(&j, sizeof(int), 1, ft1)<=0) { goto exit2; }
				fwrite(&j, sizeof(int), 1, f);
			} /*while*/
			if (c==READLEFT) { fwrite(&k, sizeof(int), 1, f); m--; }
			while (--m>=0) {
				if (fread(&j, sizeof(int), 1, ft2)<=0) { goto exit2; }
				fwrite(&j, sizeof(int), 1, f);
			} /*while*/
			//START NEXT PAIR OF RUNS
			i=n; m=n; c=READ2;
		} /*for*/
		
	exit2:
//		// RUN SIZE DOUBLES DUE TO MERGE
		n+=n;
		assert(fseek(f, 0, SEEK_SET)>=0);
		// PRINT CURRENT RUNS
		for (i=0; i<N; i++) {
			assert(fread(&j, sizeof(int), 1, f)>0);
			printf("%d ",j);
		} /*for*/
		printf("\n");
} /*while*/

fclose(f);
fclose(ft1);
fclose(ft2);
remove(input);
remove(temp1);
remove(temp2);
}