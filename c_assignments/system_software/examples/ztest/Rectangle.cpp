using namespace std;
#include <iostream>
#include "Rectangle.h"
int Rectangle::count;

void Rectangle::zero() {
  m_red=0; m_green=0; m_blue=0; m_x=0; m_y=0; m_z=0;
  m_width=0; m_height=0;
}
Rectangle::Rectangle() {
  zero();
  cout<<"constructor 1 called\n"<<endl;
}
Rectangle::Rectangle(double width, double height) {
  zero(); m_width=width; m_height=height;
  cout<<"constructor 2 called\n"<<endl;
}
Rectangle::~Rectangle() {cout<<"destructor called\n"<<endl;}
void Rectangle::position(double &x, double &y, double &z) {
	x=m_x;  y=m_y;  z=m_z;
}
void Rectangle::setposition(double x, double y, double z) {
	this->m_x=x; this->m_y=y; this->m_z=z;
}
std::istream& operator>>(std::istream& is, Rectangle& r) {
  cin>>r.m_red>>r.m_green>>r.m_blue;
  cin>>r.m_x>>r.m_y>>r.m_z;
  cin>>r.m_width>>r.m_height;
  return is;
}
std::ostream& operator<<(std::ostream& os, Rectangle r) {
  cout<<r.m_red<<" "<<r.m_green<<" "<<r.m_blue<<" ";
  cout<<r.m_x<<" "<<r.m_y<<" "<<r.m_z<<" ";
  cout<<r.m_width<<" "<<r.m_height<<" ";
  return os;
}
