/*(Counts as Program 8)
Take Program #7 and move the init, sort, print methods to 3 separate files. 
Use the gcc -c option to generate .o files for the three methods plus a .o for
the test program.  Then use gcc to link the four files into an executable.
It "recognizes" the .o arguments and invokes the linker. E-mail the programs
(concatenated into one file) and a screenshot (showing gcc command line and
ls *.o and program output) to the Instructor.
*/
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <time.h>
int main(int argc, char *argv[]) {
  node *myList;
  myList = (node*)malloc(sizeof(node));
  printf("list created\n");
  init(10,myList);
  printf("list initialized\n");
  print(myList);
  sort(myList);
  printf("\nlist sorted\n");
  print(myList);
  printf("\n");
  return 0;
}
