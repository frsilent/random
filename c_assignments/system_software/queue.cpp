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
  Queue();
  string toString();
  void parse(string input);
  int put(int x);
  int get();
  int size();
  ~Queue();
};
Queue::Queue() {    printf("in\n");
  queue.head=0; queue.tail=0;
}
Queue::~Queue() {   printf("out\n");
}
int Queue::size() {
  return queue.head-queue.tail;
}
string Queue::toString() {
  ostringstream o;
  int pos=queue.head;
  while(pos<queue.tail) o<<queue.store[pos]<<" ";
  return o.str();
}
int Queue::put(int x) {
  if(queue.tail >= sizeof(queue.store)/sizeof(int)); return 0;
  queue.store[queue.tail]=x;
  return 1;
}
int Queue::get() {
  assert(queue.head<queue.tail);
  return queue.store[queue.head++];
}

int main() {
  Queue q;
  cout<<q.size()<<endl;
  q.put(3); q.put(5); q.put(7);
  cout<<q.toString()<<endl;
  cout<<q.get()<<endl;
  getchar(); return 0;
}
