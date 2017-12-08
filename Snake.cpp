// Snake.cpp: implementation of the Snake class
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////

#include "Snake.h"
RandomNumberGenerator Snake::rng_;

Snake::Snake():MoveableGridItem(rng_.get_random_value(SIZE), rng_.get_random_value(SIZE), SNAKEHEAD), tail_()
{
	position_at_random();
	p_mouse_ = nullptr; //to make the pointer is safe before the snake spots the mouse
	for (int i = 0; i < 3; i++) {
		TailItem t(this->get_x(), this->get_y());
		tail_.push_back(t);
	}
}

bool Snake::has_caught_mouse() const{
	return is_at_position(p_mouse_->get_x(), p_mouse_->get_y());
}

void Snake::spot_mouse(Mouse* p_mouse) {
	assert(p_mouse != nullptr);	 //Pre-condition: The mouse needs to exist 
	p_mouse_ = p_mouse;
}
void Snake::chase_mouse() {	 
	int snake_dx, snake_dy;
	//identify direction of travel
	set_direction(snake_dx, snake_dy);
	//go in that direction
	update_position(snake_dx, snake_dy);
}
void Snake::set_direction(int& dx, int& dy)
{
	assert(p_mouse_ != nullptr);  //Pre-condition: The snake needs to know where the mouse is 
	//assume snake only move when necessary
	dx = 0; dy = 0;
		//update coordinate if necessary
	if (get_x() < p_mouse_->get_x())      //if snake on left of mouse
		dx = 1;							  //snake should move right
	else                                  //otherwise
		if (get_x() > p_mouse_->get_x())  //if snake on left of mouse
			dx = -1;                      //snake should move left
	if (get_y() < p_mouse_->get_y())      //if snake is above mouse
		dy = 1;                           //snake should move down
	else                                  //otherwise
		if (get_y() > p_mouse_->get_y())  //if snake is below mouse
			dy = -1;                      //snake should move up
}

void Snake::position_at_random() {
	//spawn_x_ = rng_.get_random_value(SIZE);        //WARNING: may fall on mouse
	//spawn_y_ = rng_.get_random_value(SIZE);
}

void Snake::tail_Move()
{
	TailItem tFront(this->get_x(), this->get_y());	//this snkae objects current position
	tail_.at(2) = tail_.at(1);
	tail_.at(1) = tail_.at(0);
	tail_.at(0) = tFront;
}

bool Snake::is_Tail_Here(const int x, const int y)
{
	for (int i = 0; i < 3; i++) {
		if (tail_.at(i).get_x() == x &&  tail_.at(i).get_y() == y)
			return true;
	}
	return false;
}




