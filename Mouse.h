// Mouse.h: UserInterface for the Mouse class
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------
// Date       Programmer    Amendments made and justification (if needed)
//---------------------------------------------------------------------
// 
//
//---------------------------------------------------------------------

#if !defined(MouseH)
#define MouseH

#include "Nut.h"
#include "constants.h"
#include "Underground.h"
#include "MoveableGridItem.h"
class Mouse:public MoveableGridItem {
	public:
		//constructor
		Mouse::Mouse();
		//assessors

		bool is_alive() const;
		bool has_escaped() const;
		bool has_reached_a_hole(const Underground& ug);
		//mutators
		void die();
		void escape_into_hole();
		void scamper(const char& k);
		
	private:
		//data members
		bool alive_;
		bool escaped_;
		//supporting functions 
		void position_in_middle_of_grid();

};

#endif // !defined(MouseH)
