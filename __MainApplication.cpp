//--------------------------------
//include standard libraries
#include <iostream>		//for output and input
#include <string>		//for string
#include <sstream>		//for streamstring
using namespace std;

//include class modules
#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "UserInterface.h"
#include "Game.h"





//using OO approach
//---------------------------------
UserInterface ui;

int main()
{
	Game game;

	game.set_up(&ui);
	game.run();

	ui.hold_window();
	return 0;
}