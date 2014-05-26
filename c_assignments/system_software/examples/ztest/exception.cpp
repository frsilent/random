#include <iostream>
#include <exception>
#include <vector>
using namespace std;

class myexception: public exception {
public:
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;

int main (int argc, char *argv[]) {
int i;
for (;;) {
  cout<<"type 0 1 or 2: ";
  cin>>i;
  if (i==0) exit(0);
  try
  { vector<int> v;
    if (i==1) throw myex;
    if (i==2) cout<<v[12]<<endl;
  }
  catch (myexception& e) {
    cout << e.what() << endl;
  }
  catch (exception& e) {
    cout << e.what() << endl;
  }
  catch (...) {
    cout <<"non C++ exception"<< endl;
  }
} /*for*/
  return 0;
}
