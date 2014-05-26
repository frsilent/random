/* @Heintze, Darrell R.
					GSU
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
	int i = 0;
	int sum = 0;
	int x = 0;

	for (i=1;i<argc;i++) {
		if(atoi(argv[i])==0) {						//handles the case for an argument of type string
			FILE *fileCall = fopen(argv[i], "r");				//presumed to be a txt file
				while(fscanf(fileCall,"%d",&x) != EOF) {
					sum += x;
				}
				fclose(fileCall);
		}
	 	else {
				sum += atoi(argv[i]);
		}
	}	
	if (argc==1) {											//this if block handles the case of no argument
		while(scanf("%d\n", &x)!=EOF) {
				sum += x; 
			}
	}
	printf("The sum is: %d\n",sum);
	return 0;
}
