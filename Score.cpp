#include "Score.h"

Score::Score() : amount_(0)
{}

int Score::get_amount() {
	return amount_;
}
void Score::update_amount(int& amount) {
	amount_ += amount;
}