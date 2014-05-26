/* @Heintze, Darrell R.
6544 GSU
*/
//A program demonstrating one way of traversing IP address, useful for any type of ip scanning
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sectionMax 255

int main(int argc, char *argv[], char *envp[]) {
	if (argc!=3) {  //handles the case of no argument
    printf("Usage: Scan x.x.x.x x.x.x.x\nScan start end\n");
    return 0;
	}
	int a,b,c,d;  //start IP split into 4 ints
	int af,bf,cf,df;  //end IP split into 4 ints
	
	char start[15]; char end[15];  //set our inputs to strings, making them easier to work with
  strcpy(start,argv[1]); strcpy(end,argv[2]);

  char * token=strtok(start,"."" ");  //splits start & end IPs into sections, assigning each to an int
  a=atoi(token); token=strtok(NULL,"."" ");
  b=atoi(token); token=strtok(NULL,"."" ");
  c=atoi(token); token=strtok(NULL,"."" ");
  d=atoi(token); token=strtok(NULL,"."" ");  
  token=strtok(end,"."" ");
  af=atoi(token); token=strtok(NULL,"."" ");
  bf=atoi(token); token=strtok(NULL,"."" ");
  cf=atoi(token); token=strtok(NULL,"."" ");
  df=atoi(token); token=strtok(NULL,"."" ");

  if(a>sectionMax||b>sectionMax||c>sectionMax||d>sectionMax||
  af>sectionMax||bf>sectionMax||cf>sectionMax||df>sectionMax) {
    printf("Improper ip address, please use 0-%d for each section range:\n0-%d.0-%d.0-%d.0-%d\n"
    ,sectionMax,sectionMax,sectionMax,sectionMax,sectionMax); return 0;
  }

//***algo taken from stackoverflow.com using shift operators***//
  unsigned int itr;
  int ipStart[]={a,b,c,d};
  int ipEnd[]={af,bf,cf,df};
  unsigned int startIP=(ipStart[0]<<24|ipStart[1]<<16|ipStart[2]<<8|ipStart[3]);
  unsigned int endIP=(ipEnd[0]<<24|ipEnd[1]<<16|ipEnd[2]<<8|ipEnd[3]);
  
  for(itr=startIP;itr<endIP;itr++) {
  printf("Scanning: %d.%d.%d.%d\n",
  (itr & 0xFF000000)>>24,(itr & 0x00FF0000)>>16,
  (itr & 0x0000FF00)>>8, (itr & 0x000000FF));
  }
  return 0;
}
