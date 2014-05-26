/* @Heintze, Darrell R.
6544 GSU
*/
//an interface for a doubly-linked list structure
//each object has pointers to the previous & next nodes
typedef struct _node{
  int value;
  struct _node *next;
  struct _node *prev;
  } node;
typedef node *pNode;

void init(int elements,node *list);
void sort(node *p);
void print(node *p);
