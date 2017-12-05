#include "UserInterface.h" 
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

void UserInterface::draw_grid_on_screen(const string& grid_data) const  {
	system("cls"); //clear screen
	cout << grid_data;
}

void UserInterface::show_results_on_screen(string message) const {
	cout << message;
}

void UserInterface::hold_window() {
	cout << "\n\n";
	system("pause");
}