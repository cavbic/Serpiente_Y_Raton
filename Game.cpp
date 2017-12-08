#include "Game.h"

void Game::set_up(UserInterface* pui, Player& player_) {
	//prepare game
	//set up the holes and nut
	underground_.add_hole_at_position(4, 3);
	underground_.add_hole_at_position(15, 10);
	underground_.add_hole_at_position(7, 15);
	//mouse state already set up in its contructor
	//set up snake
	snake_.position_at_random();
	snake_.spot_mouse(&mouse_);

	//set up the UserInterface
	p_ui = pui;
	p_p = &player_;
}
void Game::run() {
	assert(p_ui != nullptr);
	p_ui->draw_grid_on_screen(prepare_grid());
	p_ui->display_stats(p_p->get_name(), p_p->get_score_amount());
	key_ = p_ui->get_keypress_from_user();
	while (!has_ended(key_))
	{
		if (is_arrow_key_code(key_))
		{
			mouse_.scamper(key_);
			snake_.tail_Move();
			snake_.chase_mouse();
			p_ui->draw_grid_on_screen(prepare_grid());
			p_ui->display_stats(p_p->get_name(), p_p->get_score_amount());
			apply_rules();
		}
		key_ = p_ui->get_keypress_from_user();
	}
	p_ui->show_results_on_screen(prepare_end_message());
}
string Game::prepare_grid() {
	//prepare a string that holds the grid information
	ostringstream os;
	for (int row(1); row <= SIZE; ++row)	//for each row (vertically)
	{
		for (int col(1); col <= SIZE; ++col)	//for each column (horizontally)
		{
			if ((row == snake_.get_y()) && (col == snake_.get_x()))
				os << snake_.get_Symbol();	//show snake
			else
				if ((snake_.is_Tail_Here(col, row)))
					os << SNAKETAIL;
				else {
					if ((row == mouse_.get_y()) && (col == mouse_.get_x()))
						os << mouse_.get_Symbol();	//show mouse
					else
					{
						const int hole_no(underground_.find_hole_number_at_position(col, row));
						if (hole_no != -1)
							os << underground_.get_Hole_Symbol();	//show hole
						else
						{
							if ((row == nut_.get_y()) && (col == nut_.get_x()) && (nut_.has_been_collected() == false))
								os << nut_.get_Symbol(); //show nut
							else
								os << FREECELL;	//show free grid cell
						}
					}
				}
		} //end of col-loop
		os << endl;
	} //end of row-loop
	return os.str();
} //end prepare_grid

bool Game::is_arrow_key_code(const int keycode) const {
	return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}

void Game::apply_rules() {
	if ((mouse_.is_at_position(nut_.get_x(), nut_.get_y())))
	{
		nut_.disappears();
	}
	if (snake_.has_caught_mouse())
		mouse_.die();
	else
		if ((mouse_.has_reached_a_hole(underground_)) && (nut_.has_been_collected()))
			mouse_.escape_into_hole();

}
bool Game::has_ended(const char& key) const {
	return ((key == 'Q') || (!mouse_.is_alive()) || (mouse_.has_escaped()));
}
string Game::prepare_end_message() const {
	ostringstream os;
	if (mouse_.has_escaped()) {
		p_p->update_score_amount(1);
		os << "\n\nEND OF GAME: THE MOUSE ESCAPED UNDERGROUND!";
		cout << "\nNew Score: " << p_p->get_score_amount();
	}
	else
		if (!mouse_.is_alive()) {
			p_p->update_score_amount(-1);
			os << "\n\nEND OF GAME: THE SNAKE ATE THE MOUSE!";
			cout << "\nNew Score: " << p_p->get_score_amount();
		}
		else
			os << "\n\nEND OF GAME: THE PLAYER ENDED THE GAME!";
	return os.str();
}