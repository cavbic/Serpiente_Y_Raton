using namespace std;

//include class modules
#include "UserInterface.h"
#include "Game.h"
#include "Player.h"

//using OO approach
//---------------------------------

int main()
{
	UserInterface ui;
	Player player_(ui.entry_screen());

	do
	{
		Game game;
		game.set_up(&ui, player_);	
		game.run();
	} while (ui.play_again() == 'Y');

	cout << "\nEND";

	ui.hold_window();
	return 0;
}