#include "ConsoleSnake.h"


// Initialize Game variables
Game::Game() 
{
	rows = 15; // Set grid's heigth
	cols = 25; // Set grid's width
	runGame = true;
	gameSpeed = 500; // Set to 500 for 2 frames per second
}

// Start of the game instance
void Game::run() 
{

	Snake playerInstance;
	playerInstance.generateCoordinates(rows, cols);

	Fruit fruitInstance;
	fruitInstance.generateCoordinates(rows, cols);

	// Allocate memory for the game grid which sercves the role as visual represintation of the game's state which is printed in the console
	char** grid = new char* [rows];
	for (int i = 0; i < rows; i++) {
		grid[i] = new char[cols];
	}

	// Build the initial Grid State
	buildGrid(rows, cols, grid);

	// Put the Snake to it's current coordinations on the grid




	// ==================================================================== add input handling here =================================================================================

	playerInstance.putOnGrid(grid);

	// Set snakes direction. will be removed when input functionality is implemented.
	playerInstance.direction = 1;  // Snake's direction: 1 - UP 2 - DOWN 3 - LEFT 4 - RIGHT

	// Main game loop
	do
	{

		// Put the Snake to it's current coordinations on the grid
		playerInstance.stepForward(grid);
		playerInstance.putOnGrid(grid);
		// Put the Fruit to it's current coordinations
		do 
		{
			fruitInstance.putOnGrid(grid);
		} while (playerInstance.snakeX == fruitInstance.fruitX && playerInstance.snakeY == fruitInstance.fruitY); // Loop to ensure the Fruit doesn't spawn on the Snake
		
		
		render(rows, cols, grid); // Rendering the grid on the screen


		sleep_ms(gameSpeed);
	} while (runGame);

	// De-allocating the memory reseved for the grid
    deAllocateGrid(rows, grid);
	return;
}


// Adjust the sleep_ms function for either Linux or Windows
#ifdef _WIN32 // Windows function that takes mulliseconds
#include <windows.h>
void sleep_ms(int gameSpeed) {
	Sleep(gameSpeed);
}
#else // Linux function that takes seconds
#include <unistd.h>
void sleep_ms(int gameSpeed) {
	usleep(gameSpeed * 1000); // Since usleep() on Linux unline sleep on WIndows uses microseconds and not milliseconds passed value is multiplied by 1000
}
#endif

