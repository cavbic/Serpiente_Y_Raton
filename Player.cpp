#include "Player.h"

Player::Player(string& name) : name_(name)
{}

const string Player::get_name() {
	return name_;
}
const int Player::get_score_amount() {
	return score_.get_amount();
}
void Player::update_score_amount(int amount) {
	score_.update_amount(amount);
}