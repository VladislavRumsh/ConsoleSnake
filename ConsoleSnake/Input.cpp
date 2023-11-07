#include "Input.h"
#include <windows.h> // For GetAsyncKeyState



// Initialize Input variables
Input::Input()
{

}

// Start of the Input instance
void Input::run(int* directions) 
{

	int direction = *directions;

	while (true)
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			*directions = 1;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			*directions = 2;
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			*directions = 3;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			*directions = 4;
		}		
		else if (GetAsyncKeyState(VK_END) & 0x8000) 
		{
			
		}
	}
	return;
}

