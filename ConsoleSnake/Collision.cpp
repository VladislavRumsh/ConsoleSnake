#include "Collision.h"


void Collision::collisionWithWall(Entity& playerInstance, Entity& fruitInstance, Game& gameInstance)
{
	if (playerInstance.entityX == 0 || playerInstance.entityX == gameInstance.cols - 1 || playerInstance.entityY == 0 || playerInstance.entityY == gameInstance.rows - 1) // Check collision with walls/borders
	{
		playerInstance.isAlive = false;
		return;
	}
}

void Collision::collisionWithFruit(Entity& playerInstance, Entity& fruitInstance, Game& gameInstance, char** grid)
{

	if ((playerInstance.entityX == fruitInstance.entityX && playerInstance.entityY == fruitInstance.entityY)) // Check collision with Snake and Fruit
	{
		// Initialize first body object
		// First part of the body is attaching to the head, and the rest of the body attaches to the first body part, this might change in the future or be used to extra game mecahnics
		if (playerInstance.score != 0)
		{
			playerInstance.body.back().growBody();
			playerInstance.body.back().putOnGrid(grid);
		}
		else
		{
		playerInstance.growBody();
		playerInstance.body.back().putOnGrid(grid);
		}


		fruitInstance.generateCoordinates(fruitInstance, gameInstance, grid);
		++playerInstance.score;
	}
	return;

}

void Collision::collisionWithBody()
{
	return;
}