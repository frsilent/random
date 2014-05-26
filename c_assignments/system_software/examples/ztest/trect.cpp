using namespace std;
#include <iostream>
#include "Rectangle.h"

int main(int argc, char *argv[]) {
  Rectangle r,s(5,6);
  cout<<s<<endl;
  cout<<"Enter red green blue x y z width height: ";
  cin>>r;
  cout<<r<<endl;
  Rectangle::count=55;
  cout<<s.count<<endl;
  return 0;
}
