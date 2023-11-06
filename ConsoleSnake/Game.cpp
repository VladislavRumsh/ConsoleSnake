#include "ConsoleSnake.h"

// Initialize Game variables
Game::Game() {
	rows = 5;
	cols = 5;
	runGame = true;
}

// Start of the game instance
void Game::run() {


	// Allocate memory for the game grid which sercves the role as visual represintation of the game's state which is then printed in the console
	char** grid = new char* [rows];
	for (int i = 0; i < rows; i++) {
		grid[i] = new char[cols];
	}

	// Main game loop
	while (runGame)
	{
		buildGriDAndRender(rows, cols, grid);



	}

	// De-allocating the memory reseved for the grid
    deAllocateGrid(rows, grid);
	return;
}