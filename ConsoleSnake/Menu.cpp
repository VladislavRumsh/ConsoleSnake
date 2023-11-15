#include "Menu.h"
#include "Help.h"
#include "Settings.h"
#include "Input.h"
#include <thread>
#include <windows.h>

Menu::Menu()
{
	selected = 0;
}



void Menu::run()
{


	// Create instance of the Input object and run it on another thread to ensure responsive controls
	Input inputInstance;

	// Run the Input object in another thread
	std::thread inputThread(&Input::runMenu, &inputInstance, &selected); // Enabling Input

	int rows{ 12 }, cols{ 18 }, speed{ 120 }; // Initializing the variables for grid's width and height which can be later assigned via the settings screen

	while (true)
	{

		asciiConsoleSnake();

		std::cout << "Menu:\n";

		printSelection();


		if (selected == 5)
		{
			// Create instance of the Game Object and run the game loop
			Game gameInstance(rows, cols, speed); // Passing Rows and Collomns for grid size, should be set in the menu
			gameInstance.run(gameInstance);

			selected = 0;
		}
		if (selected == 6)
		{
			Settings settingsInstance;
			settingsInstance.run(&rows, &cols, &speed);

			selected = 0;

		}
		if (selected == 7)
		{
			Help helpInstance;
			helpInstance.run();

			selected = 0;

		}
		Sleep(50);
		system("cls");

	}


	std::cin.get();
	// Detach input thread
	inputThread.join();
	return;

}

void Menu::printSelection()
{
	switch (selected)
	{
	case 0:
		std::cout << "-->START\n";
		std::cout << "   SETTINGS\n";
		std::cout << "   HELP\n";
		break;
	case 1:
		std::cout << "   START \n";
		std::cout << "-->SETTINGS\n";
		std::cout << "   HELP\n";
		break;
	case 2:
		std::cout << "   START\n";
		std::cout << "   SETTINGS\n";
		std::cout << "-->HELP\n";
		break;
	default:
		break;
	}
	return;
}