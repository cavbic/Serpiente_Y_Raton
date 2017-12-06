// Underground.cpp: implementation of the Underground class 
//////////////////////////////////////////////////////////////////////

#include "Underground.h"

//////////////////////////////////////////////////////////////////////




Underground::Underground() :MAXHOLES(3), holes_(MAXHOLES)
{}

Hole Underground::get_hole_no(int no) const {
	assert (is_valid_hole_number(no));	//precondition: valid hole number
	return holes_.at(no);
}
void Underground::set_hole_no_at_position(int no, int x, int y) {
	assert (is_valid_hole_number(no));	//precondition: valid hole number
	Hole h(x, y);
	switch (no) {
	case 0: holes_.at(0) = h; break;
	case 1: holes_.at(1) = h; break;
	case 2: holes_.at(2) = h; break;
	}
}
bool Underground::is_valid_hole_number(int no) const {
	return (no >= 0) && (no < holes_.size()); 
}

int Underground::getHolesSize() const
{
	return static_cast<int>(holes_.size());
}
