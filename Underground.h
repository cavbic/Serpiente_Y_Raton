// Underground.h: UserInterface for the Underground class 
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------
// Date       Programmer    Amendments made & justification (if needed)
//---------------------------------------------------------------------
// 1.11.17   Pascale		TODO: Need to be amended for Assignment 1 [Q1 to 4 and 8]
//                          TODO: Declare class data and function members private where possible.
//                          TODO: Declare const instances, parameters and class functions (wherever possible).
//                          TODO: Create constructors with their initialisation list in same order as declaration list
//                          TODO: Place code in separate module
//                   		TODO: Check design and implementation of relationships to other classes
//                   		TODO: Follow UML design.
//							TODO: etc.
//---------------------------------------------------------------------

#if !defined(UndergroundH)
#define UndergroundH

#include <cassert>
#include <vector>
using namespace std;

#include "constants.h"
#include "Hole.h"
#include "Nut.h"


class Underground {
public:
	Underground();
	//Hole get_hole_no(int no) const;
	char get_Hole_Symbol() const;
	void add_hole_at_position(const int& x, const int& y);
	int get_Holes_Size() const;
	int find_hole_number_at_position(const int& x,const int& y);
	int get_Hole_x(const int& holeNum) const;
	int get_Hole_y(const int& holeNum) const;
private:
	const int MAXHOLES; //number of holes in underground
	vector<Hole> holes_;

};

#endif // !defined(UndergroundH) 
