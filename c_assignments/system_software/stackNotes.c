//toSTring method is the toughest
#define MAX 50
int stack[MAX],top;
push(int x) {
if!top>MAX
stack[++top]=x;}

int pop() { return stack[top--]};

void toString(char output[],int n) {
int i; char buffer[15]; buffer[0]=0;
  for(i=top;i>=0;i--) {
  sprintf(buffer,"%d, ",stack[i]);
  if(strlen(output)+strlen(buffer)<n) { strcat(output,buffer);}
  }
  output[strlen(output)-2]=0;
}

/*!implement a stack with a structure, shouldn't be too hard
instead of top, pass a pointer to every method
pass in address, this structure's member...is this
accessing members of structures
*/

Stack:: Stack(){ top=-1}
Stack::~Stack(){}

Stack *s=new Stack();
s->push(1);
s->toString(output,50);
cout<<outpout<<endl;
