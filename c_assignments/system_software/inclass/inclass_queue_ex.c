#include<iostream>
#include<sstream>
#include<string>
#include<cassert>
using namespace std;

typedef struct _Q {
  int head, tail;
  int store[10];
} Q;

class Queue {
public:
  Q queue;
  int iterator;
  Queue();
  string toString();
  void parse(string input);
  int put(int x);
  int get();
  int size();
  void iterate(int index);
  int next();
  int hasNext();
  ~Queue();
}

Queue::Queue() {
  printf("in\n");
  queue.head=0; queue.tail=0; iterator = -1;
}

Queue::~Queue() {
  printf("out\n");
}

int Queue::size() {
  return queue.tail-queue.head;
}
string Queue::toString() {
  ostringstream o;
  int pos=queue.head;
  while(pos<queue.tail) o<<queue.store[pos++]<<" ";
  return o.str();  
}
int Queue::put(int x) {
  if (queue.tail >= (sizeof(queue.store)/sizeof(int));
  queue.store[queue.tail++]=x;
  return 1;
}
int Queue::get() {
  assert(queue.head<queue.tail);
  return queue.store[queue.head++];
}
void Queue::iterate(int index) {
  iterator=0;
}
int Queue::next() {
  assert(hasNext());
  return queue.store[queue.head+iterator++];
}
int Queue::hasNext() {
  return !(iterator<0 || iterator>=size());
}
int main() {
  Queue q;
  cout<<q.size()<<endl;
  q.put(3); q.put(5); q.put(7);
  cout<<q.toString()<<endl;
  cout<<q.get()<<endl;
  cout<<q.toString()<<endl;
  q.iterate();
  while(q.hasNext()) cout<<q.next()<<endl;
  return 0;
}
