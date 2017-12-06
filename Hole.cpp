
#include "Hole.h"


Hole::Hole()
{}
Hole::Hole(int x, int y) {
	symbol_ = HOLE;
	x_ = x;
	y_ = y;
}
int Hole::get_x() const{
	return x_;
}
int Hole::get_y() const{
	return y_;
}
char Hole::get_symbol() const {
	return symbol_;
}
bool Hole::is_at_position(int x, int y) {
	return (x_ == x) && (y_ == y);
}