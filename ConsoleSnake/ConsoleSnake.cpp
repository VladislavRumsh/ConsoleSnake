#include "game.h"
#include "Menu.h"
#include <windows.h>


// Entry point
int main()
{



	while (true)
	{

	// write "Console Snake" on top in ascii art
	Menu menuInstance; // Starting the menu to configure the game still in developemtn
	menuInstance.run();



	// Create instance of the Game Object and run the game loop
	Game gameInstance(16, 30, 40); // Passing Rows and Collomns for grid size, should be set in the menu
	gameInstance.run(gameInstance);


	}

	return 0;
}

