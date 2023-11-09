#include "Random.h"


// Generating random numbers for coordinates
int randomNum(int maxCoordinatesValue)
{
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()) };

	// Setting the generated number to fit the grid
	std::uniform_int_distribution GridLimit{ 1, maxCoordinatesValue };

	return GridLimit(mt);
}


// Generate Random Coordinates for an entity
void randomCoords(Entity& playerInstance, Game& gameInstance, char** grid)
{
	int generatedX{};
	int generatedY{};
	do // Do while to regenerate random coordinates until an empty place on the grid is found
	{
		generatedX = randomNum(gameInstance.cols - 2);
		generatedY = randomNum(gameInstance.rows - 2);
	} while (grid[generatedY][generatedX] != ' ');
	playerInstance.entityX = generatedX;
	playerInstance.entityY = generatedY;

}
