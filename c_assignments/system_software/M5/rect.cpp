using namespace std;
#include<iostream>
#include"rect.h"

int Rect::count=0;

void Rect::zero() {
	m_red=0;m_green=0;m_blue=0;m_x=0;m_y=0;m_z=0;m_width=0;m_height=0;
}
Rect::Rect() {zero();}
Rect::Rect(double width,double height) {
	zero(); m_width=width; m_height=height;
}
Rect::~Rect() {}
void Rect::setposition(double x, double y, double z) {
	this->m_x=x;this->m_y=y;this->m_z=z;
}
