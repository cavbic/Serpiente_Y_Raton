// Mouse.cpp: implementation of the Mouse class
//////////////////////////////////////////////////////////////////////

#include "Mouse.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Mouse::Mouse(): symbol_(MOUSE), x_(0), y_(0),    
                alive_(true), escaped_(false), 
				mouse_dx_(0), mouse_dy_(0) {
	position_in_middle_of_grid(); 
}

//////////////////////////////////////////////////////////////////////
// Public functions
//////////////////////////////////////////////////////////////////////

int Mouse::get_x() {
	return x_;
}
int Mouse::get_y() {
	return y_;
}
char Mouse::get_symbol() const {
	return symbol_;
}
bool Mouse::is_at_position(int x, int y) {
	return (x_ == x) && (y_ == y);
}
bool Mouse::is_alive() const {
	return alive_;
}
bool Mouse::has_escaped() const {
	return escaped_;
}
bool Mouse::has_reached_a_hole(Underground ug) {
	for (int h_no(0); h_no < ug.holes_.size(); ++h_no)
	{
		Hole h = ug.get_hole_no(h_no);
		if (is_at_position(h.get_x(), h.get_y()))
			return true;
	}
	return false;
}
void Mouse::die() {
	alive_ = false;
}
void Mouse::escape_into_hole() 
{
	escaped_ = true;
}
void Mouse::scamper(char k) { //move mouse in required direction
  //pre: Key is an arrow representing the direction in which the mouse moves
	//find direction indicated by key
	switch(k)               //...depending on the selected key...
	{
		case LEFT:           //when LEFT arrow pressed...
			mouse_dx_ = -1;    //decrease the X coordinate
			mouse_dy_ = 0;
			break;
		case RIGHT:          //when RIGHT arrow pressed...
			mouse_dx_ = +1;    //increase the X coordinate
			mouse_dy_ = 0;
			break;
		case UP:             //when UP arrow pressed...
			mouse_dx_ = 0;
			mouse_dy_ = -1;    //decrease the Y coordinate
			break;
		case DOWN:           //when DOWN arrow pressed...
			mouse_dx_ = 0;
			mouse_dy_ = +1;    //increase the Y coordinate
			break;
	}
	//update mouse coordinates if move is possible
	if (((x_ + mouse_dx_) >= 1) && ((x_ + mouse_dx_) <= SIZE) &&
		 ((y_ + mouse_dy_) >= 1) && ((y_ + mouse_dy_) <= SIZE) )
	{
		update_position(mouse_dx_, mouse_dy_);		//go in that direction
	}
}

//////////////////////////////////////////////////////////////////////
// Private functions
//////////////////////////////////////////////////////////////////////

void Mouse::update_position(int dx, int dy) {
	x_ += dx; 
	y_ += dy;
}
void Mouse::position_in_middle_of_grid() {
	x_ = SIZE /2;
	y_ = SIZE /2;
}