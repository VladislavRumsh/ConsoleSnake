#include "Render.h"
#include <sstream>


// Update the intial state of the grid
void buildGrid(Game& gameInstance, char** grid)
{
	for (int i = 0; i < gameInstance.rows; i++)
	{
		for (int j = 0; j < gameInstance.cols; j++)
		{
			// Generate Walls
			if (i == 0 || i == gameInstance.rows - 1 || j == 0 || j == gameInstance.cols - 1)
			{
				grid[i][j] = '#';
			}
			else
			{
				grid[i][j] = ' ';
			}
		}
	}
	return;
}


// clear the console for the new frame and print the grid in the console
void renderGame(Game& gameInstance, char** grid, int score)
{
	system("cls");

	// Write "Console Snake"
	asciiConsoleSnake();

	// Score
	std::cout << "Your Score is: " << score << std::endl;
	std::cout << "Max Score is:  " << gameInstance.maxScore << std::endl;

	// Put the array in a single stringstream variable to print it with one std::cout function call
	std::stringstream ss;

	for (int i = 0; i < gameInstance.rows; ++i) {
		for (int j = 0; j < gameInstance.cols; ++j) {
			ss << grid[i][j];
		}
		ss << "\n";  // Add a newline at the end of each row
	}

	std::cout << ss.str();  // Print the game grid as one element and not array

	return;
}

// Delete each inner array (columns) and then delete the outer array (rows)
void deAllocateGrid(int rows, char** grid) 
{
	for (int i = 0; i < rows; i++) {
		delete[] grid[i];
	}
	delete[] grid;
	return;
}

void asciiConsoleSnake() 
{
	std::cout <<
		"--------------------------------------------------------\n"
		"  _____                   __      ____          __      \n"
		" / ___/__  ___  ___ ___  / /__   / __/__  ___ _/ /_____ \n"
		"/ /__/ _ \\/ _ \\(_-</ _ \\/ / -_) _\\ \\/ _ \\/ _ `/  '_/ -_)\n"
		"\\___/\\___/_//_/___/\\___/_/\\__/ /___/_//_/\\_,_/_/\\_\\\\__/ \n"
		"                                                         \n"
		"--------------------------------------------------------\n\n";
	return;
}
