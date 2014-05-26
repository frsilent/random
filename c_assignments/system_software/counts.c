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

	//printf("%d\n",strcmp(elements[0],elements[1]));//1 with dog first,-1 if cat is first
  void sort() {
    for(i=0;i<x-1;i++) {
      for(j=0;j<x-i-1;j++) {
        if (strcmp(elements[j],elements[j+1])<0) {
          strcpy(t,elements[j]); strcpy(elements[j],elements[j+1]);strcpy(elements[j+1],t);
          m=frequency[j];frequency[j]=frequency[j+1];frequency[j+1]=m;
      } }
    } }
  
	while(scanf("%s",s)==1) {
		add(s);
	}
  sort();
	printf("Elements:\tFrequency:\n");
	for(i=0;i<x;i++) {
		printf("%s\t\t%d\n",elements[i],frequency[i]);
	}
	return 0;
}
