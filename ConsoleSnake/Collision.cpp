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

		playerInstance.growBodyCheck = true;

		fruitInstance.generateCoordinates(fruitInstance, gameInstance, grid);
		++playerInstance.score;

		// Check if winning condition, which is reaching maximum score is met.
		if (playerInstance.score == gameInstance.maxScore)
		{
			playerInstance.hasWon = true; // For testng this "kills" the snake causing us to loose, later will be added winning flag
		}

	}


	return;

}

void Collision::collisionWithBody(Entity& playerInstance, Entity& bodyInstance, char** grid)
{
	if ((playerInstance.entityX == bodyInstance.entityX && playerInstance.entityY == bodyInstance.entityY))
	{
		playerInstance.isAlive = false;
	}
	return;
}