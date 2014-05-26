/* @Heintze, Darrell R.
6544 GSU
*/

/* Sums up 100 random ints*/
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main(int argc, char *argv[], char *envp[]) {
  srand((unsigned int)time(NULL));
  int i=0;  //common incrementor
  int x=0;  //to hold random int
  int sum=0;  //our sum to print
  for(i=0;i<100;i++) {
    x=rand() % 50;
    printf("%d.Adding %d to sum, %d\n",i+1,x,sum);
    sum+=x;  //add random int to sum
  }
  printf("The final sum is: %d\n",sum);
}
