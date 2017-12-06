// Underground.cpp: implementation of the Underground class 
//////////////////////////////////////////////////////////////////////

#include "Underground.h"

//////////////////////////////////////////////////////////////////////




Underground::Underground() :MAXHOLES(3), holes_(MAXHOLES)
{}

char Underground::get_Hole_Symbol() const
{
	return Hole::get_symbol();
}

//	assert (is_valid_hole_number(no));	//precondition: valid hole number
//	return holes_.at(no);
//}
void Underground::set_hole_no_at_position(const int& no,const int& x, const int& y) {        
	assert (is_valid_hole_number(no));	//precondition: valid hole number
	Hole h(x, y);
	switch (no) {
	case 0: holes_.at(0) = h; break;
	case 1: holes_.at(1) = h; break;
	case 2: holes_.at(2) = h; break;
	}
}
bool Underground::is_valid_hole_number(const int& no) const {
	return (no >= 0) && (no < holes_.size()); 
}

int Underground::get_Holes_Size() const
{
	return static_cast<int>(holes_.size());
}
int Underground::find_hole_number_at_position(const int& x, const int& y) {
	for (int h_no(0); h_no < get_Holes_Size(); ++h_no)
		if (holes_.at(h_no).is_at_position(x, y))
			return h_no;		//number of the hole
	return -1;				//not a hole
}
int Underground::get_Hole_x(const int& holeNum) const 
{
	return holes_.at(holeNum).get_x();
}
int Underground::get_Hole_y(const int& holeNum) const
{
	return holes_.at(holeNum).get_y();
}