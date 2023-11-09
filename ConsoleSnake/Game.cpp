#include "ConsoleSnake.h"
#include <thread> // For reading the Input in another thread and not disturb the game loop
#include <windows.h>
#include "Input.h"

// Initialize Game variables
Game::Game() 
{
	rows = 17; // Set grid's heigth
	cols = 17; // Set grid's width
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
		for (int i = 0; i < playerInstance.body.size(); i)
		{
			playerInstance.body[i].stepForward(playerInstance.body[i], grid);
			playerInstance.body[i].oldDirection = playerInstance.body[i].direction;
			playerInstance.body[i].putOnGrid(grid);
			if (i == 0)
			{
				playerInstance.body[i].direction = playerInstance.oldDirection;

			}
			else
			{
				playerInstance.body[i].direction = playerInstance.body[i-1].oldDirection;
			}
			i++;
		}

		



		// Check for collision with a Wall
		collisionClass.collisionWithWall(playerInstance, fruitInstance, gameInstance);
		
		// Check for collision with a Fruit
		collisionClass.collisionWithFruit(playerInstance, fruitInstance, gameInstance, grid); 

		
		// Grow body when fruit collected, must run after the check with collision in the same iteration of the game loop.
		if (playerInstance.growBodyCheck)
		{
			// Initialize first body object
			// First part of the body is attaching to the head, and the rest of the body attaches to the first body part, this might change in the future or be used to extra game mecahnics
			playerInstance.growBody();
			playerInstance.body.back().putOnGrid(grid);
			playerInstance.growBodyCheck = false;
		}

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