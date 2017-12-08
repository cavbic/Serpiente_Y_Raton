
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
Hole::Hole(const int x, const int y) {
	x_ = x;
	y_ = y;
	
}
const char Hole::get_symbol() {
	return symbol_;
}