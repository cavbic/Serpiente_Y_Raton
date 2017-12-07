// Snake.h: UserInterface for the Snake class 
//////////////////////////////////////////////////////////////////////
#if !defined(SnakeH)
#define SnakeH

#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include "MoveableGridItem.h"
class Snake: public MoveableGridItem{
	public:
		Snake();
		bool has_caught_mouse()const ;
		void spot_mouse(Mouse* p_mouse);
		void chase_mouse();
		void set_direction(int dx, int dy);
		static void position_at_random();

	private:
		static RandomNumberGenerator rng_;
		Mouse* p_mouse_;
};

#endif // !defined(SnakeH)
