#include "ConsoleSnake.h"
#include <thread> // For reading the Input in another thread and not disturb the game loop
#include <windows.h>
#include "Input.h"

// Initialize Game variables
Game::Game() 
{
	rows = 9; // Set grid's heigth
	cols = 9; // Set grid's width
	runGame = true;
	gameSpeed = 250; // Set to 500 for 2 frames per second

}

// Start of the game instance
void Game::run(Game& gameInstance)
{
		// Allocate memory for the game grid which sercves the role as visual represintation of the game's state which is printed in the console
	char** grid = new char* [rows];
	for (int i = 0; i < rows; i++) {
		grid[i] = new char[cols];
	}

	// Build the initial Grid State
	buildGrid(gameInstance, grid);

	Entity playerInstance; // Generating Snake instance
	playerInstance.entityId = 0; // set playerInstance to Player's Snake entity
	playerInstance.generateCoordinates(playerInstance, gameInstance, grid); // Generating coordinates for the Player

	Entity fruitInstance; // Generating Fruit instance
	fruitInstance.entityId = 1; // set fruitInstance to Fruit

	fruitInstance.generateCoordinates(fruitInstance, gameInstance, grid);

	// Create instance of the Input object and run it on another thread to ensure responsive controls
	Input inputInstance;

	// Run the Input object in another thread
	std::thread inputThread(&Input::run, &inputInstance, std::ref(playerInstance));


	Collision collisionClass; // Generate Collision class for collision funtions




	// Put the Snake to it's current coordinations on the grid
	playerInstance.putOnGrid(grid);


	// Main game loop
	do
	{



		// Check if snake has died, later to be moved in a seperate function
		if (!playerInstance.isAlive)
		{
			break; // temporary using break to end the end in case of collision with a wall
			// print game over
			// press r to restart press m to return to main menu
		}




		


		// Put the Snake to it's current coordinations on the grid
		playerInstance.stepForward(playerInstance, grid);
		playerInstance.oldDirection = playerInstance.direction;
		playerInstance.putOnGrid(grid);


		// Call stepForward the first body part and the others.
		for (Entity& bodyStart : playerInstance.body) {
			bodyStart.stepForward(bodyStart, grid);
			bodyStart.oldDirection = bodyStart.direction;
			bodyStart.putOnGrid(grid);
			bodyStart.direction = playerInstance.oldDirection;

			// Call stepForward on the rest of the body
			for (Entity& bodyPart : bodyStart.body) {
				bodyPart.stepForward(bodyPart, grid);
				bodyPart.oldDirection = bodyPart.direction;
				bodyPart.putOnGrid(grid);
				bodyPart.direction = bodyStart.oldDirection;
			}

		}




		// Check for collision with a Wall
		collisionClass.collisionWithWall(playerInstance, fruitInstance, gameInstance);
		
		// Check for collision with a Fruit
		collisionClass.collisionWithFruit(playerInstance, fruitInstance, gameInstance, grid); // Creating a new body part inside this function


		//void collisionWithFruit(int snakeX, int snakeY, int* score, int fruitX, int fruitY);

		// Put the Fruit to it's current coordinations
		fruitInstance.putOnGrid(grid);

		render(gameInstance, grid, playerInstance.score); // Rendering the grid on the screen


		Sleep(gameSpeed); // set Game Speed
	} while (runGame);

	// De-allocating the memory reseved for the grid
    deAllocateGrid(rows, grid);
	return;
}












// ========================= remove old coordinates of the body part so it doesnt stay and change it's direction ================