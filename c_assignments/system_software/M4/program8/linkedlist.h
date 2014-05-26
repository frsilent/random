/*(Counts as Program 8)
Take Program #7 and move the init, sort, print methods to 3 separate files. 
Use the gcc -c option to generate .o files for the three methods plus a .o for
the test program.  Then use gcc to link the four files into an executable.
It "recognizes" the .o arguments and invokes the linker. E-mail the programs
(concatenated into one file) and a screenshot (showing gcc command line and
ls *.o and program output) to the Instructor.
*/
typedef struct _node{
  int value;
  struct _node *next;
  struct _node *prev;
  } node;
typedef node *pNode;

void init(int elements,node *list);
void sort(node *p);
void print(node *p);
