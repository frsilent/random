#include<iostream>

class Rect {
private:
	double m_red, m_green, m_blue;
	double m_x, m_y, m_z;
	double m_width, m_height;
public:
	static int count;
	Rect();
	Rect(double width,double height);
	~Rect();

void position(double &x, double &y, double &z);
void setposition(double x, double y, double z);
void zero();
}
