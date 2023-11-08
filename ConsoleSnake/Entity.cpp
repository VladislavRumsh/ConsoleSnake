#include "Entity.h"


Entity::Entity()
{
	isAlive = true;
	entityId = 0; // 1 - Snake's head, 2 - Fruit
	direction = 0; // Snake's direction: 1 - UP 2 - DOWN 3 - LEFT 4 - RIGHT
}

// Generating New Coordinates for the Snake entity
void Entity::generateCoordinates(Entity& playerInstance, Game& gameInstance)
{
	randomCoords(playerInstance, gameInstance);
	return;
}

// Puts the entity of the fruit class on the array in it's coordinates
void Entity::putOnGrid(char** grid)
{
	if (entityId == 0)
	{
		switch (direction)
		{
		case 0:
			grid[entityY][entityX] = 'S';;
			return;
		case 1:
			grid[entityY][entityX] = '^';
			return;
		case 2:
			grid[entityY][entityX] = 'V';
			return;
		case 3:
			grid[entityY][entityX] = '<';
			return;
		case 4:
			grid[entityY][entityX] = '>';
			return;
		}

	}
	else if (entityId == 1)
	{
		grid[entityY][entityX] = 'F';
	}

	return;
}

// Makes the Snake entity move 1 step with each iteration of the game loop
void Entity::stepForward(Entity& playerInstance, char** grid)
{

	removeFromGrid(playerInstance, grid); // Clear old coordinates on the grid

	// Check the direction in which the snake is set to go
	// 1 - UP 2 - DOWN 3 - LEFT 4 - RIGHT
	switch (direction)
	{
	case 1:
		--entityY;
		return;
	case 2:
		++entityY;
		return;
	case 3:
		--entityX;
		return;
	case 4:
		++entityX;
		return;
	default:
		return;
	}

	return;
}

// Cleans the location on the grid that is no more used by the Snake
void Entity::removeFromGrid(Entity& playerInstance, char** grid)
{
	grid[entityY][entityX] = ' ';
	return;
}