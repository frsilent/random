#include <iostream>
#include <string>
using namespace std;
#define virtual /**/

class Object {
public:
  virtual void Draw();
};
void Object::Draw() {
  cout<<"drawing object"<<endl;
}
class Line: public Object {
public:
  virtual void Draw();
};
void Line::Draw() {
  cout<<"drawing line"<<endl;
}
class Circle: public Object {
public:
  virtual void Draw();
};
void Circle::Draw() {
  cout<<"drawing circle"<<endl;
}

#define N 4
int main(int argc, char *argv[]) {
  Object *x[N];
  int i;
  x[0]=new Object(); x[3]=new Object();
  x[1]=new Line();  x[2]=new Circle();
  for (i=0; i<N; i++) x[i]->Draw();
  for (i=0; i<N; i++) delete x[i];
  return 0;
}
