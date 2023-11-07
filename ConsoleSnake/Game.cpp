#include "ConsoleSnake.h"
#include <thread> // For reading the Input in another thread and not disturb the game loop

// Initialize Game variables
Game::Game() 
{
	rows = 10; // Set grid's heigth
	cols = 15; // Set grid's width
	runGame = true;
	gameSpeed = 250; // Set to 500 for 2 frames per second
}

// Start of the game instance
void Game::run() 
{



	Snake playerInstance; // Generating Snake instance
	playerInstance.generateCoordinates(rows, cols); // Generating coordinates for the Snake

	Fruit fruitInstance; // Generating Fruit instance
	fruitInstance.generateCoordinates(rows, cols);

	// Create instance of the Input object and run it on another thread to ensure responsive controls
	Input inputInstance;

	// Run the Input object in another thread
	std::thread inputThread(&Input::run, &inputInstance, &playerInstance.direction);


	// Allocate memory for the game grid which sercves the role as visual represintation of the game's state which is printed in the console
	char** grid = new char* [rows];
	for (int i = 0; i < rows; i++) {
		grid[i] = new char[cols];
	}

	// Build the initial Grid State
	buildGrid(rows, cols, grid);

	// Put the Snake to it's current coordinations on the grid
	playerInstance.putOnGrid(grid);


	// Main game loop
	do
	{

		// Put the Snake to it's current coordinations on the grid
		playerInstance.stepForward(grid);
		playerInstance.putOnGrid(grid);

		if ( playerInstance.snakeX == 0 || playerInstance.snakeX == cols - 1 || playerInstance.snakeY == 0 || playerInstance.snakeY == rows - 1 ) // Check collision with walls/borders
		{
			break;
		}

		if ((playerInstance.snakeX == fruitInstance.fruitX && playerInstance.snakeY == fruitInstance.fruitY)) // Check collision with Snake and Fruit
		{
			fruitInstance.generateCoordinates(rows, cols);
			playerInstance.score++;
		}


				// Put the Fruit to it's current coordinations
					fruitInstance.putOnGrid(grid);




		render(rows, cols, grid, playerInstance.score); // Rendering the grid on the screen


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

