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
#include "MoveableGridItem.h"
class Nut: public MoveableGridItem {
public:
	Nut();
	bool has_been_collected() const;
	void disappears();
private:
	bool collected_;
};

#endif // !defined(NutH)	
#pragma once
