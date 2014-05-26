#include <iostream>
using namespace std;

template <class T, int N>
class myarray {
  public:
    T mem[N];
    T& operator[] (int x);
};

template <class T, int N>
T& myarray<T,N>::operator[] (int x) {
  if ((x<0)||(x>=N)) throw 99; /*declare a class*/
  return mem[x];
}
int i=-1;
int main () {
  myarray <int,5> x;
  try {
  x[3]=99;
  cout<<x[3]<<endl;
  x[i]=52;
  } catch (...) {
   cout<<"subscript error"<<endl;
  }
  return 0;
}
