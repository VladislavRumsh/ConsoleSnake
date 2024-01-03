#include "Settings.h"
#include "Input.h"
#include <windows.h> // remove if close menu is removed from here
#include <thread>

Settings::Settings()
{
	selected = 0;
}

void Settings::run(int* rows, int* cols, int* speed)
{

	// Create instance of the Input object and run it on another thread to ensure responsive controls
	Input inputInstance;

	// Run the Input object in another thread
	std::thread inputThread(&Input::runSettings, &inputInstance, &selected, rows, cols, speed); // Enabling Input by starting a new thread for it

	while (selected != 5)
	{
	system("cls");

	asciiConsoleSnake();

	std::cout << "Settings:\n";

	printSelection(rows, cols, speed);

	Sleep(40);
	}

	// Close menu


	// Detach input thread
	inputThread.join();
	return;
}

void Settings::printSelection(int* rows, int* cols, int* speed)
{
	switch (selected)
	{
	case 0:
		std::cout << "   Height/Rows                                 -->" << *rows << std::endl;
		std::cout << "   Width/Cols                                     " << *cols << std::endl;
		std::cout << "   Speed ( 500 for 2 ticks per second )           " << *speed << std::endl;
		std::cout << "   Exit settings" << std::endl;
		break;
	case 1:
		std::cout << "   Height/Rows                                    " << *rows << std::endl;
		std::cout << "   Width/Cols                                  -->" << *cols << std::endl;
		std::cout << "   Speed ( 500 for 2 ticks per second )           " << *speed << std::endl;
		std::cout << "   Exit settings" << std::endl;
		break;
	case 2:
		std::cout << "   Height/Rows                                    " << *rows << std::endl;
		std::cout << "   Width/Cols                                     " << *cols << std::endl;
		std::cout << "   Speed ( 500 for 2 ticks per second )        -->" << *speed << std::endl;
		std::cout << "   Exit settings" << std::endl;
		break;	
	case 3:
		std::cout << "   Height/Rows                                    " << *rows << std::endl;
		std::cout << "   Width/Cols                                     " << *cols << std::endl;
		std::cout << "   Speed ( 500 for 2 ticks per second )           " << *speed << std::endl;
		std::cout << "-->Exit settings" << std::endl;
		break;
	default:
		break;
	}
}