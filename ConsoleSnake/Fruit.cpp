#include "Fruit.h"
#include "Random.h"
Fruit::Fruit()
{

	isAlive = true;
}

// Generating New Coordinates for the Fruit entity
void Fruit::generateCoordinates(int rows, int cols)
{
	randomCoords(&fruitX, &fruitY, --rows, --cols);
	// Draw Initial Fruit Position

}

// Puts the entity of the fruit class on the array in it's coordinates
void Fruit::putOnGrid(char** grid) {
	grid[fruitY][fruitX] = 'F';
}