#pragma once

#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "UserInterface.h"
#include "Nut.h"
#include "Player.h"
#include <sstream>		
#include <fstream>
#include <iostream>

class Game
{
public:
	void set_up(UserInterface* pui, Player& player_);
	void run();
	string prepare_grid();
	bool is_arrow_key_code(const int keycode) const;
	void apply_rules();
	bool has_ended(const char& key) const;
	string prepare_end_message() const;
private:
	Mouse mouse_;
	Snake snake_;
	Nut nut_;
	Underground underground_;
	UserInterface* p_ui;
	Player* p_p;
	int key_;
	char input_;
};