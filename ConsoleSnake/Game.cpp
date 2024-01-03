#include "ConsoleSnake.h"
#include "Input.h"
#include <thread> // For reading the Input in another thread and not disturb the game loop
#include <windows.h>
#include <iostream>


// Initialize Game variables
Game::Game(int setRows, int setCols, int setGameSpeed)
{
	rows = setRows; // Set grid's heigth
	cols = setCols; // Set grid's width
	runGame = true;
	gameSpeed = setGameSpeed; // Set to 500 for 2 frames per second
	saveScore = 1;

}

// Start of the game instance
void Game::run(Game& gameInstance)
{
	// Calculate maximal possible score for current grid size
	Game::maxScore = ((rows - 2) * (cols - 2));

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

	playerInstance.putOnGrid(grid); // spawning the snake on the grid so the check for whenever the grid is empty or not before spawning the fruit is met

	Entity fruitInstance; // Generating Fruit instance
	fruitInstance.entityId = 1; // set fruitInstance to Fruit

	fruitInstance.generateCoordinates(fruitInstance, gameInstance, grid);

	// Create instance of the Input object and run it on another thread to ensure responsive controls
	Input inputInstance;

	// Run the Input object in another thread
	std::thread inputThread(&Input::runGame, &inputInstance, std::ref(playerInstance));


	Collision collisionClass; // Generate Collision class for collision funtions




	// Put the Snake to it's current coordinations on the grid
	playerInstance.putOnGrid(grid);


	// Main game loop
	do
	{

		// later move this to check flags function or class
		 // _______________  I think this part of is alive and has won should be moved to some function laters __________________
		// Check if snake has won, later to be moved in a seperate function
		if (playerInstance.hasWon)
		{
			playerInstance.isAlive = false;
		}

		// Check if snake has died, later to be moved in a seperate function
		if (!playerInstance.isAlive)
		{
			GameEnd gameEndInstance;  // Declare gameEndInstance
		    gameEndInstance.run(rows, cols, gameSpeed, playerInstance.score, playerInstance.hasWon);
			system("cls");
			break;
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
			collisionClass.collisionWithBody(playerInstance, playerInstance.body[i], grid);
			i++;
		}

		

		// Check for collision with a Fruit
		collisionClass.collisionWithFruit(playerInstance, fruitInstance, gameInstance, grid);


		// Check for collision with a Wall
		collisionClass.collisionWithWall(playerInstance, fruitInstance, gameInstance);
		

		
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

		renderGame(gameInstance, grid, playerInstance.score); // Rendering the Game screen



		Sleep(gameSpeed); // set Game Speed
	} while (runGame);

	// De-allocating the memory reseved for the grid
    deAllocateGrid(rows, grid);
	// Detach input thread
	inputThread.join();
	return;
}
