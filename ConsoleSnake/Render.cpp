#include <iostream>
#include <cstdlib>

// Adjust the clearing console command for either Linux or Windows
#ifdef _WIN32
#include <windows.h>
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif


// Update the intial state of the grid
void buildGrid(int rows, int cols, char** grid)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			// Generate Walls
			if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
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
void render(int rows, int cols, char** grid) 
{
	system(CLEAR_COMMAND);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << grid[i][j];
		}
		std::cout << std::endl;
	}
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

