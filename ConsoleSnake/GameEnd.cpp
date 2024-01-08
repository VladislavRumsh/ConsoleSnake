#include "GameEnd.h"
#include "Input.h"
#include <windows.h> // remove if close menu is removed from here
#undef min //undefining for std::streamsize :: max
#undef max
#include <thread>
#include <limits>

GameEnd::GameEnd()
{
	selected = 0;
	uploadScore = false;
}

void GameEnd::run(int rows, int cols, int speed, int score, bool haveWon)
{


	// Create instance of the Input object and run it on another thread to ensure responsive controls
	Input inputInstance;

	// Run the Input object in another thread
	std::thread inputThread(&Input::runGameEnd, &inputInstance, &selected, &uploadScore); // Enabling Input

	
	while (selected!= 5)
	{
		system("cls");// print game over
		asciiConsoleSnake();

		if (haveWon)
			std::cout << "YOU WON!!!\n";
		else
			std::cout << "GAME OVER!\n";

		std::cout << "YOUR SCORE IS: " << score << std::endl;
		std::cout << "Would you like to save your score to the online scoreboard?\n";

		//sendHTTPScore(L"Test Name", playerInstance.score, std::to_wstring(rows) + L"x" + std::to_wstring(gameInstance.cols), gameInstance.gameSpeed
		GameEnd::printSelection();
	Sleep(50);
	}

	if (uploadScore == true)
	{

		// Displaying a screen to take the name from the user in case he wanted to upload his score		    
		// Check if the input is empty and assign "Guest" if it is
		std::wstring tempName, gridSize;
		std::wstringstream gridSizeStream; // since i can't use the << operator to write rows and cols into wstring I first do it with wstringstream and then write that into wstring gridSize
    if (tempName.empty()) {
		tempName = L"Guest";
    }
	gridSizeStream << rows << L" x " << cols;

	gridSize = gridSizeStream.str();
	
	sendHTTPScore(tempName, score, gridSize, speed);


	}

	system("cls");
	

	// Detach input thread
	inputThread.join();

	return;
}

void GameEnd::printSelection()
{
	switch (selected)
	{
	case 0:
		std::cout << "-->Yes\n";
		std::cout << "   No\n";
		break;
	case 1:
		std::cout << "   Yes\n";
		std::cout << "-->No\n";
		break;
	default:
		break;
	}
}