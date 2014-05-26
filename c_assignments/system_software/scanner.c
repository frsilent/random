/* @Heintze, Darrell R.
6544 GSU
*/
//A program demonstrating one way of traversing IP address, useful for any type of ip scanning
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sectionMax 255

int main(int argc, char *argv[], char *envp[]) {
	if (argc!=3) {  //handles the case of not enough or too many arguments
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
  int iA,iB,iC,iD;
  
  for(iA=a;iA<sectionMax;iA++) {
    a=iA;
    for(iB=b;iB<sectionMax;iB++) {
      b=iB;
      for(iC=c;iC<sectionMax;iC++) {
        c=iC;
        for(iD=d;iD<=sectionMax;iD++) {
          d=iD;
          printf("Scanning: %d.%d.%d.%d\n",a,b,c,d);
          /*Here we add a function to perform across the range, e.g.
          ping a.b.c.d argv[3]; (our port)
          */
          if(a==af && b==bf && c==cf && d==df){ printf("Scan successfully completed.\n"); return 0;}
        }
        d=0;
      }
      c=0;
    }
    b=0;
  }
  return 0;
}
