#include "Input.h"
#include <windows.h> // For GetAsyncKeyState


// Initialize Input variables
Input::Input()
{

}

// Start of the Input instance
void Input::run(Entity& playerInstance)
{

	while (true)
	{
		if ((GetAsyncKeyState(VK_UP) & 0x8000) && playerInstance.oldDirection != 2)
		{
			playerInstance.direction = 1;
		}
		else if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && playerInstance.oldDirection != 1)
		{
			playerInstance.direction = 2;
		}
		else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && playerInstance.oldDirection != 4)
		{
			playerInstance.direction  = 3;
		}
		else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && playerInstance.oldDirection != 3)
		{
			playerInstance.direction = 4;
		}		
		else if (GetAsyncKeyState(VK_END) & 0x8000) 
		{
			
		}
	}
	return;
}

