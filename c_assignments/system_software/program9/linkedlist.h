/*Recode Program #7 as a C++ class definition with a
constructor/destructor in a .h file.  Code the implementation
in a separate .cpp file.  Code the test program to a separate
.cpp file.  E-mail the three files and a screenshot of execution
to the Instructor.
///////////////////////////////
class Node {
public:
typedef struct _node{
  int value;
  struct _node *next;
  struct _node *prev;
  } node;
typedef node *pNode;

void init(int elements,node *list);
void sort(node *p);
void print(node *p);*/
class Node {
public:
  int value;
  Node *prev;
  Node *next;
}
/*
Node::Node() {
  cout<<"constructor 1 called\n"<<endl;
}
Rectangle::~Rectangle() {cout<<"destructor called\n"<<endl;}
void Rectangle::position(double &x, double &y, double &z) {
	x=m_x;  y=m_y;  z=m_z;
}*/
