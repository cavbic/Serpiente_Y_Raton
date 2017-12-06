// Nut.h: UserInterface for the Nut class
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------
// Date       Programmer    Amendments made and justification (if needed)
//---------------------------------------------------------------------
// 
//
//---------------------------------------------------------------------

#if !defined(NutH)
#define NutH

#include "constants.h"
#include "Underground.h"

class Nut {
public:
	//constructors
	Nut();
	//assessors
	int get_x();
	int get_y();
	char get_symbol() const;
	bool is_at_position(int x, int y);
	bool has_been_collected() const;
	void disappears();
private:
	//data members
	char symbol_;
	int  x_, y_;
	bool collected_;
};

#endif // !defined(NutH)	
#pragma once
