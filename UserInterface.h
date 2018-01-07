#if !defined(UserInterfaceH)
#define UserInterfaceH

//include standard libraries
#include <iostream>		//for output and input: cout << and cin >>
#include <string>		//for string
using namespace std;

class UserInterface {
public:
	int get_keypress_from_user() const;
	void draw_grid_on_screen(const string& grid_data) const;
	void show_results_on_screen(const string& message) const;
	void hold_window() const;
	void display_stats(const string&, const int) const;
	string entry_screen();
	void cheat_message(bool& cheat_) const;
	char play_again();
private:
	string username_;
	char input_;
};

#endif // !defined(UserInterfaceH)