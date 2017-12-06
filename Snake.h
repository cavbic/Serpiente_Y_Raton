// Snake.h: UserInterface for the Snake class 
//////////////////////////////////////////////////////////////////////
#if !defined(SnakeH)
#define SnakeH

#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include "constants.h"

class Snake {
	public:
		Snake();
		~Snake();
		bool is_at_position(const int& x, const int& y) const;  
		bool has_caught_mouse()const ;
		void spot_mouse(Mouse* p_mouse);
		void chase_mouse();
		void set_direction(int& dx, int& dy);
		void position_at_random();
		void update_position(const int& dx, const int& dy);
		int get_X() const;
		int get_Y() const;
		char get_Symbol() const;

	private:
		int x_, y_;
		const char symbol_ ;
		static RandomNumberGenerator rng_;
		Mouse* p_mouse_;
};

#endif // !defined(SnakeH)
