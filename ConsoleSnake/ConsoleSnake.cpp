#include "game.h"
#include <windows.h>

// Entry point
int main()
{

	while (true)
	{

	
	std::cout << "Welcome to the main menu of Console Snake!!! \n ---PRESS ENTER TO BEGIN THE GAME---";
	std::cin.get();

	// Create instance of the Game Object and run the game loop
	Game gameInstance;
	gameInstance.run(gameInstance);

	std::cout << "Press enter to restart the application\n";
	std::cin.get();
	system("cls");

	}
	return 0;
}