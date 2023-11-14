#include "Entity.h"



Entity::Entity()
{
	isAlive = true;
	hasWon = false;
	growBodyCheck= false;
	entityId = 0; // 1 - Snake's head, 2 - Fruit
	direction = 0; // Snake's direction: 1 - UP 2 - DOWN 3 - LEFT 4 - RIGHT
}

// Generating New Coordinates for the Snake entity
void Entity::generateCoordinates(Entity& playerInstance, Game& gameInstance, char** grid)
{
	randomCoords(playerInstance, gameInstance, grid);
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
		default:
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


	removeFromGrid(playerInstance, grid);

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

// This function generates new an object for each snake's body segments 
void Entity::growBody()
{
	// Initialize temporary variables to operate with Data set the function operate either with Snake's head for the first segment or the last segment of it's body
	int newSegmentX{}, newSegmentY{}, directionForNewSegment{};

		if (body.empty())
		{
			newSegmentX = entityX;
			newSegmentY = entityY;
			directionForNewSegment = oldDirection;
		} 
		else
		{
			newSegmentX = body.back().entityX;
			newSegmentY = body.back().entityY;
			directionForNewSegment = body.back().oldDirection;
		}

		// Adjust to the correct swapn location
		switch (directionForNewSegment) {
		case 1:
			newSegmentY += 1;
			break;
		case 2:
			newSegmentY -= 1;
			break;
		case 3:
			newSegmentX += 1;
			break;
		case 4:
			newSegmentX -= 1;
			break;
		}

		Entity newBodySegment;
		newBodySegment.entityX = newSegmentX;
		newBodySegment.entityY = newSegmentY;
		newBodySegment.entityId = 0;
		newBodySegment.direction = directionForNewSegment;

		body.push_back(newBodySegment);
	
}