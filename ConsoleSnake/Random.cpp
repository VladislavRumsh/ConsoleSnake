#include <random>
#include <chrono>

// Generating random numbers for coordinates
int randomNum(int maxCoordinatesValue)
{
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()) };

	// Setting the generated number to fit the grid
	std::uniform_int_distribution GridLimit{ 1, --maxCoordinatesValue };

	return GridLimit(mt);
}

// Generate Random Coordinates for an entity
void randomCoords(int* X,int* Y, int rows, int cols) 
{
	*X = randomNum(cols);
	*Y = randomNum(rows);
	return;
}

