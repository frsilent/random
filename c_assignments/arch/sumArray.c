/* @Heintze, Darrell R.
6544 GSU
*/

/* Adds 100 random ints to an array, then finds the sum of those elements*/
#define arraySize 100
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
  int i=0;  //common incrementor
  int ourArray[arraySize];
  int sum=0;  //our sum to print
  
  for(i=0;i<arraySize;i++) {  //fill in our array
    ourArray[i] = rand() % 50;
  }
  
	printf("Elements:\n");  //print out our array
	for(i=0;i<arraySize-1;i++) {
		printf("%d->",ourArray[i]);
	}
	printf("%d\n",ourArray[arraySize]);
  
  for(i=0;i<arraySize;i++) {  //sum all elements
    sum+=ourArray[i];
  }  

  printf("The sum of these is: %d\n",sum);
}
