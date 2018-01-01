#pragma once

#include <string>
#include "Score.h"
using namespace std;

class Player {
public:
	Player(string&);
	const string get_name();
	const int get_score_amount();
	void update_score_amount(int);
private:
	const string name_;
	Score score_;
};
