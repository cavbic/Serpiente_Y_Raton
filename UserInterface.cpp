#include "UserInterface.h" 
#include "Player.h"
#include "Game.h"
#include <conio.h>		//for _getch()


int UserInterface::get_keypress_from_user() const {
	//get key or command selected by user
	//read in the selected arrow key or command letter
	int key_pressed(_getch());
	//ignore symbol following cursor key
	while (key_pressed == 224)
		key_pressed = _getch();
	//return the key in uppercase
	return(toupper(key_pressed));
}

void UserInterface::draw_grid_on_screen(const string& grid_data) const {
	system("cls"); //clear screen
	cout << grid_data;
}

void UserInterface::show_results_on_screen(const string& message) const {
	cout << message;
}

void UserInterface::hold_window() const {
	cout << "\n\n";
	system("pause");
}

void UserInterface::display_stats(const string& name, const int score) const {
	cout << "\nUsername: " << name << "\nScore: " << score << "\nHit 'C' to activate cheat mode.\n";

}

void UserInterface::cheat_message(bool& cheat_) const
{
	if (cheat_ == true)
		cout << "\nCHEAT MODE ACTIVATED!";
}

string UserInterface::entry_screen() {
	cout << "\n\n\n\n\n\t\t\t";
	cout << "Enter Your Name: ";
	cin >> username_;
	return (username_);
}

char UserInterface::play_again() {
	cout << "\n\nWould you like to play again?\nType 'Y' for Yes: ";
	cin >> input_;
	return(toupper(input_));
}

