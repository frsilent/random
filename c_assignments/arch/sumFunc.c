/* @Heintze, Darrell R.
6544 GSU
*/

/* Adds 100 random ints to an array, then finds the sum of those elements*/
#define arraySize 100
#include <stdio.h>
#include <stdlib.h>

int sumArray(int anArray[], int anArraySize);

int main(int argc, char *argv[], char *envp[]) {
  int i=0;  //common incrementor
  int ourArray[arraySize];
  
  for(i=0;i<arraySize;i++) {  //fill in our array
    ourArray[i] = rand() % 50;
  }
  
	printf("Elements:\n");  //print out our array
	for(i=0;i<arraySize-1;i++) {
		printf("%d->",ourArray[i]);
	}
	printf("%d\n",ourArray[arraySize]);
  printf("The sum is: %d\n",sumArray(ourArray,arraySize));

}

int sumArray(int anArray[], int anArraySize) {
  int sum=0; int i;
  for(i=0;i<anArraySize;i++) {sum+=anArray[i];}
  return sum;
}
