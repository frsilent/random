#ifndef __PATH__
#define __PATH__
#include <iostream>

class Path {
private:
  double m_start_x, m_start_y, m_start_z;
  double m_steps, m_increment;
  int m_current_step;
public:
  Path(double x, double y, double z, int steps, double increment);
  ~Path();
  void zero();
  bool next(double &x, double &y, double &z); //returns false on end-of-path
  friend std::istream& operator>>(std::istream& is, Path& p);
  friend std::ostream& operator<<(std::ostream& os, Path p); 
};
#endif
