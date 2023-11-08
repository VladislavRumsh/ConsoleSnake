#include "Render.h"


// Update the intial state of the grid
void buildGrid(Game& gameInstance, char** grid)
{
	for (int i = 0; i < gameInstance.rows; i++)
	{
		for (int j = 0; j < gameInstance.cols; j++)
		{
			// Generate Walls
			if (i == 0 || i == gameInstance.rows - 1 || j == 0 || j == gameInstance.cols - 1)
			{
				grid[i][j] = '#';
			}
			else
			{
				grid[i][j] = ' ';
			}
		}
	}
	return;
}


// clear the console for the new frame and print the grid in the console
void render(Game& gameInstance, char** grid, int score)
{
	system("cls");
	// Game state
	for (int i = 0; i < gameInstance.rows; ++i)
	{
		for (int j = 0; j < gameInstance.cols; ++j)
		{
			std::cout << grid[i][j];
		}
		std::cout << std::endl;
	}
	// Score
	std::cout << score << std::endl;

	return;
}

// Delete each inner array (columns) and then delete the outer array (rows)
void deAllocateGrid(int rows, char** grid) 
{
	for (int i = 0; i < rows; i++) {
		delete[] grid[i];
	}
	delete[] grid;
	return;
}

