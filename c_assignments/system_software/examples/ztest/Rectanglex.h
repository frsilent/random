#ifndef __RECTANGLE__
#define __RECTANGLE__
#include <iostream>

class Rectangle {
private:
  double m_red, m_green, m_blue;
  double m_x, m_y, m_z;
  double m_width, m_height;
public:
  static int count;
  Rectangle();
  Rectangle(double width, double height);
  ~Rectangle();
  void position(double &x, double &y, double &z);
  void setposition(double x, double y, double z);
  void zero();
  friend std::istream& operator>>(std::istream& is, Rectangle& r);
  friend std::ostream& operator<<(std::ostream& os, Rectangle r); 
};
#endif
