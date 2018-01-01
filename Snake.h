// Snake.h: UserInterface for the Snake class 
//////////////////////////////////////////////////////////////////////
#if !defined(SnakeH)
#define SnakeH

#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include "MoveableGridItem.h"
#include "TailItem.h"
#include <vector>
class Snake: public MoveableGridItem{
	public:
		Snake();
		bool has_caught_mouse()const ;
		void spot_mouse(Mouse* p_mouse);
		void chase_mouse();
		void set_direction(int& dx, int& dy);
		static void position_at_random();
		void tail_Move();
		const bool is_Tail_Here(const int x, const int y);
	private:
		static RandomNumberGenerator rng_;
		Mouse* p_mouse_;
		vector<TailItem> tail_;
};

#endif // !defined(SnakeH)
