#include "GameEnd.h"
#include "Input.h"
#include <windows.h> // remove if close menu is removed from here
#include <thread>

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
		sendHTTPScore(L"Name", score, L"grid size in text", speed);
	}

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
		std::cout << "Unexpected value: " << selected << "\n"; // for debugging purposes, needs to be deleted later
		break;
	}
}