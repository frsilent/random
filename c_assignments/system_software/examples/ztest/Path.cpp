using namespace std;
#include <iostream>
#include "Path.h"

Path::Path(double x, double y, double z, int steps, double increment) {
	m_start_x = x;  m_start_y = y;  m_start_z = z; m_steps = steps; m_increment = increment;
	m_current_step = 0;	
}
Path::~Path(){ cout<<"Path destructor called"<<endl; };
void Path::zero() {
	m_current_step = 0;
}
bool Path::next(double &x, double &y, double &z) { //returns false on end-of-path
	if (m_current_step >= m_steps) return false;
	x = m_start_x+m_increment*(double)m_current_step;
	y = m_start_y+m_increment*(double)m_current_step;
	z = m_start_z+m_increment*(double)m_current_step;
	m_current_step++;
	return true;
}
std::istream& operator>>(std::istream& is, Path& r) {
  cin>>r.m_start_x>>r.m_start_y>>r.m_start_z;
  cin>>r.m_steps>>r.m_increment;
  return is;
}
std::ostream& operator<<(std::ostream& os, Path r) {
  cout<<r.m_start_x<<" "<<r.m_start_y<<" "<<r.m_start_z<<" ";
  cout<<r.m_steps<<" "<<r.m_increment<<" ";
  return os;
}
