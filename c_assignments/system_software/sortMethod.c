/* @Heintze, Darrell R.
6544 GSU
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef char STRING[20];
STRING test[20];
int m; STRING t;  //temporary variable holders
int test2[]={1,2,3,4,5};
int i,j;  //incrementors

void sort(STRING x[],int y[],int n, int ascending) {
  for(i=0;i<n-1;i++) {
    for(j=0;j<n-i-1;j++) {
      if(ascending==0) {
        if (strcmp(x[j],x[j+1])<0) {
          strcpy(t,x[j]); strcpy(x[j],x[j+1]);strcpy(x[j+1],t);
          m=y[j];y[j]=y[j+1];y[j+1]=m;
        }
      } else {
        if (strcmp(x[j],x[j+1])>0) {
          strcpy(t,x[j]); strcpy(x[j],x[j+1]);strcpy(x[j+1],t);
          m=y[j];y[j]=y[j+1];y[j+1]=m;
        }
      }
    }
  }
}

int main(int argc, char *argv[], char *envp[]) {
  int i;
  strcpy(test[0],"bug");  strcpy(test[1],"aug");  strcpy(test[2],"dug");  strcpy(test[3],"cug");
  strcpy(test[4],"mug");
  sort(test,test2,5,1);
  for(i=0;i<5;i++) printf("%s %d\n",test[i],test2[i]);
  sort(test,test2,5,0);
  for(i=0;i<5;i++) printf("%s %d\n",test[i],test2[i]);
  return 0;
}
