
#if !defined(HoleH)
#define HoleH

#include "constants.h"

class Hole {
public:
	//constructors
	Hole();
	Hole& operator =(const Hole&);
	Hole(const int x,const int y);
	//assessors
	static const char get_symbol() ;
private:
	static const char symbol_;
	int x_, y_;
};

#endif