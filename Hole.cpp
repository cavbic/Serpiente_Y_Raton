
#include "Hole.h"


const char Hole::symbol_(HOLE);
Hole::Hole()
{}
Hole& Hole::operator=(const Hole& hole)
{
	this->x_ = hole.x_;
	this->y_ = hole.y_;
	return *this;
}
Hole::Hole(const int& x, const int& y) {
	x_ = x;
	y_ = y;
	
}
int Hole::get_x() const{
	return x_;
}
int Hole::get_y() const{
	return y_;
}
const char Hole::get_symbol() {
	return symbol_;
}
bool Hole::is_at_position(const int& x,const int& y) const {
	return (x_ == x) && (y_ == y);
}