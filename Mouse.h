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

#include "constants.h"
#include "Underground.h"

class Mouse {
	public:
		//constructor
		Mouse::Mouse();
		//assessors
		int get_x() const;
		int get_y() const;
		char get_symbol() const;
		bool is_at_position(const int& x,const int& y)const;
		bool is_alive() const;
		bool has_escaped() const;
		bool has_reached_a_hole(const Underground& ug);
		//mutators
		void die();
		void escape_into_hole();
		void scamper(const char& k);
		
	private:
		//data members
		int  x_, y_;
		char symbol_;
		bool alive_;
		bool escaped_;
		int mouse_dx_;
		int mouse_dy_; 
		//supporting functions 
		void position_in_middle_of_grid();
		void update_position(const int& dx,const int& dy);
};

#endif // !defined(MouseH)
