/* @Heintze, Darrell R.
6544 GSU
*/
#define arraySize 1000
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef char STRING[20];

int main(int argc, char *argv[], char *envp[]) {
	int i=0,j=0,m=0;							//basic incrementer variables
	int x = 0;						//index in our arrays, last element
	STRING elements[arraySize];				//two arrays, the indices need to stay the same
	int frequency[arraySize]; 				//so the frequency of elements[i] is frequency[i]
  STRING s,t;
  
	void add(STRING newElement) {							//quick function to add an element, checks to see if it already exists
		for(i=0;i<=x;i++) {										//if it does exist, frequency at the index is increased by 1
			if (!strcmp(newElement,elements[i])) {frequency[i]++; return;}
		}
		strcpy(elements[x],newElement); frequency[x] = 1; x++;
	}

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
  
	while(scanf("%s",s)==1) {
		add(s);
	}
  sort(elements,frequency,x,1);
	printf("Elements:\tFrequency:\n");
	for(i=0;i<x;i++) {
		printf("%s\t\t%d\n",elements[i],frequency[i]);
	}
	return 0;
}
