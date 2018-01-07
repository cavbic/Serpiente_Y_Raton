// Mouse.cpp: implementation of the Mouse class
//////////////////////////////////////////////////////////////////////
#include "Mouse.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Mouse::Mouse():MoveableGridItem(SIZE / 2, SIZE / 2,MOUSE), alive_(true), escaped_(false)
{
	
}

//////////////////////////////////////////////////////////////////////
// Public functions
//////////////////////////////////////////////////////////////////////

bool Mouse::is_alive() const {
	return alive_;
}
bool Mouse::has_escaped() const {
	return escaped_;
}
bool Mouse::has_reached_a_hole(const Underground& ug) const {
	for (int h_no(0); h_no < ug.get_Holes_Size(); ++h_no)
	{
		if (is_at_position(ug.get_Hole_x(h_no), ug.get_Hole_y(h_no)))
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
void Mouse::scamper(const char& k) { //move mouse in required direction
  //pre: Key is an arrow representing the direction in which the mouse moves
	//find direction indicated by key
	int mouse_dx_;
	int mouse_dy_;
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
	if (((get_x() + mouse_dx_) >= 1) && ((get_x() + mouse_dx_) <= SIZE) &&
		 ((get_y() + mouse_dy_) >= 1) && ((get_y() + mouse_dy_) <= SIZE) )
	{
		update_position(mouse_dx_, mouse_dy_);		//go in that direction
	}
}