#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "UserInterface.h"
#include "Nut.h"
#include <sstream>		//for streamstring

class Game
{
public:
	Mouse mouse_;
	Snake snake_;
	Nut nut_;
	Underground underground_;
	UserInterface* p_ui;

	int key_;
	void set_up(UserInterface* pui);
	void run();
	string prepare_grid();
	bool is_arrow_key_code(int keycode);
	void apply_rules();
	int find_hole_number_at_position(int x, int y);
	bool has_ended(char key);
	string prepare_end_message();
};