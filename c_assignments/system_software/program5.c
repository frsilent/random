/* @Heintze, Darrell R.
					GSU
*/
#define arraySize 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[], char *envp[]) {
	int i=0,j=0,x=0,t=0;							//basic incrementer variables
	int elements[arraySize];
  srand((unsigned int)time(NULL));
  
	void sort() {     //sorting function
		for(i=0;i<x-1;i++) {
			for(j=0;j<x-i-1;j++) {
				if(elements[j]>elements[j+1]) {
					t = elements[j]; elements[j] = elements[j+1]; elements[j+1] = t;
			}	}
	}	for(i=0;i<x-1;i++) {
			if(elements[i]>elements[i+i]) {printf("Array is not yet sorted\n"); return;
			} else {printf("Array is sorted\n"); return;
		}	}
	} //EO sort
  
  for(i=0;i<arraySize-1;i++) {
    elements[i] = rand() % 50;
    x++;
  }
  
	sort();
	printf("Elements:\n");
	for(i=0;i<x;i++) {
		printf("%d\n",elements[i]);
	}
	return 0;
}
