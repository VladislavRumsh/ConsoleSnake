#include "Snake.h"
#include "Random.h"
Snake::Snake() 
{
	isAlive = true;
	direction = 0; // Snake's direction: 1 - UP 2 - DOWN 3 - LEFT 4 - RIGHT
}

// Generating New Coordinates for the Snake entity
void Snake::generateCoordinates(int rows, int cols) 
{
	randomCoords(&snakeX, &snakeY, --rows, --cols);
	return;
}

// Puts the entity of the fruit class on the array in it's coordinates
void Snake::putOnGrid(char** grid) {
	grid[snakeY][snakeX] = 'S';
	return;
}

// Makes the Snake entity move 1 step with each iteration of the game loop
void Snake::stepForward(char **grid) {

	removeFromGrid(snakeX, snakeY, grid); // Clear old coordinates on the grid

	// Check the direction in which the snake is set to go
	// 1 - UP 2 - DOWN 3 - LEFT 4 - RIGHT
	switch (direction)
	{
	case 1:
		--snakeY;
		return;
	case 2:
		++snakeY;
		return;
	case 3:
		--snakeX;
		return;
	case 4:
		++snakeX;
		return;
	default:
		return;
	}

	return;
}

// Cleans the location on the grid that is no more used by the Snake
void Snake::removeFromGrid(int X, int Y, char** grid) {
	grid[snakeY][snakeX] = ' ';
	return;
}