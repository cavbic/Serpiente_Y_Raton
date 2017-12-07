
#if !defined(HoleH)
#define HoleH

#include "constants.h"

class Hole {
public:
	//constructors
	Hole();
	Hole& operator =(const Hole&);
	Hole(const int& x,const int& y);
	//assessors
	int get_x() const;
	int get_y() const;
	static const char get_symbol() ;
	bool is_at_position(const int& x,const int& y) const;
private:
	static const char symbol_;
	int x_, y_;
};

#endif