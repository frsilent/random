using namespace std;
#include <iostream>
#include "Rectangle.h"
#include "Path.h"

class MovingSquare: public Rectangle, public Path {
public:
	MovingSquare(double side, double x, double y, double z, double increment);
	~MovingSquare();
	void zero();
	bool next();
	friend std::istream& operator>>(std::istream& is, MovingSquare& r);
	friend std::ostream& operator<<(std::ostream& os, MovingSquare r);
};

MovingSquare::MovingSquare(double side, double x, double y, double z, double increment)
	:
	Path(x,y,z,rand()%100,increment),Rectangle(side,side) {
	Rectangle::setposition(x,y,z);
}
MovingSquare::~MovingSquare() { cout<<"MovingSquare destructor called"<<endl;}
void MovingSquare::zero() {
	Path::zero();
}
bool MovingSquare::next() {
	double x,y,z;
	if (!Path::next(x,y,z)) return false;
	Rectangle::setposition(x,y,z);
}
std::istream& operator>>(std::istream& is, MovingSquare& r) {
	cin>>(Rectangle&)r>>(Path&)r;
	return is;
}
std::ostream& operator<<(std::ostream& os, MovingSquare r) {
	cout<<(Rectangle)r<<(Path)r;
	return os;
}

int main(int argc, char *argv[]) {
  MovingSquare s(0.3, 1,1,1, 0.01);
  cout<<s<<endl;
  s.next();   s.next();
  cout<<s<<endl;
  cin>>s;
  cout<<s<<endl;
  return 0;
}
