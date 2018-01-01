#pragma once

class Score {
public:
	Score();
	const int get_amount();
	void update_amount(int);
private:
	int amount_;
};