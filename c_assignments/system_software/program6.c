/* @Heintze, Darrell R.
6544  GSU
*/
#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[]) {
  int line=1;
  char buffer[100];
  char searchingfor[] = " hello ";

  if (argc==1) {printf("You must choose a file to search.\n"); return 0;}

  FILE *fileCall = fopen(argv[1],"r");
  if(fileCall != NULL) {
    while(fgets(buffer,sizeof(buffer),fileCall)) {
      if(strstr(buffer,searchingfor)) {
        printf("Search term '%s' found at line: %d\n",searchingfor,line);
      }
      ++line;
    }
  }
  fclose(fileCall);
  return 0;
}
