/* @Heintze, Darrell R.
6544 GSU
*/
#define arraySize 1000
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
	int i=0,j=0,m=0,t=0;							//basic incrementer variables
	int x = 0;						//index in our arrays, last element
	int elements[arraySize];				//two arrays, the indices need to stay the same
	int frequency[arraySize];				//so the frequency of elements[i] is frequency[i]

	void add(int newElement) {							//quick function to add an element, checks to see if it already exists
		for(i=0;i<=x;i++) {										//if it does exist, frequency at the index is increased by 1
			if (newElement==elements[i]) {frequency[i]++; return;}		//HITTING AN INFINITE LOOP HERE, WHEN A DUPLICATE IS ADDED
		}
		elements[x] = newElement; frequency[x] = 1; x++;
	}

	void sort() {     //sorting function
		for(i=0;i<x-1;i++) {
			for(j=0;j<x-i-1;j++) {
				if(elements[j]>elements[j+1]) {
					t=elements[j];elements[j]=elements[j+1];elements[j+1]=t;
					t=frequency[j];frequency[j]=frequency[j+1];frequency[j+1]=t;
			}	}
	}	}
	
	for (m=1;m<argc;m++) {
		if(atoi(argv[m])==0) {						//handles the case for an argument of type string
			FILE *fileCall = fopen(argv[m], "r");				//presumed to be a txt file
				while(fscanf(fileCall,"%d",&j) != EOF) {
					add(j);
				}
			fclose(fileCall);
		}	else {
				add(atoi(argv[m]));
			}
	}

	if (argc==1) {											//this if block handles the case of no argument
		while(scanf("%d\n", &j)!=EOF) {
				add(j);
			}
	}
	sort();
	printf("Elements:\tFrequency:\n");
	for(i=0;i<x;i++) {
		printf("%d\t\t%d\n",elements[i],frequency[i]);
	}
	return 0;
}
