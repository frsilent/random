typedef struct _node{
  int value;
  struct _node *next;
  struct _node *prev;
  } node;

class Node {
public:
  N node;
  Node();
  ~Node();
void init(int elements,Node *list);
void sort(Node *p);
void print(Node *p);
