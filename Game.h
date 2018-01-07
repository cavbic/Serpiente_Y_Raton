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
	void set_up(const UserInterface* pui, Player& player_);
	void run();
	friend ofstream& operator <<(ofstream& fout, Game& game);
	friend ifstream& operator >>(ifstream& fin, Game& game);
private:
	Mouse mouse_;
	Snake snake_;
	Nut nut_;
	Underground underground_;
	const UserInterface* p_ui;
	Player* p_p;
	int key_;
	char input_;
	bool cheat_;
	int cheatCount_;
	string importedGameData;
	bool is_arrow_key_code(const int keycode) const;
	bool has_ended(const char& key) const;
	void apply_rules();
	string prepare_end_message() const;
	string prepare_grid();
	bool is_cheat_key_pressed(const char& key) const;
	bool cheat_check(bool cheat_);
};