
using namespace std;

//include class modules
#include "UserInterface.h"
#include "Game.h"

//using OO approach
//---------------------------------

int main()
{
	Game game;
	UserInterface ui;

	game.set_up(&ui);
	game.run();

	ui.hold_window();
	return 0;
}