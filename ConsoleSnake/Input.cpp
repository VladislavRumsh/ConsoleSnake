#include "Input.h"
#include "Game.h"
#include <windows.h> // For GetAsyncKeyState


// Initialize Input variables
Input::Input()
{

}

// Start of the Game Input instance
void Input::runGame(Entity& playerInstance)
{
	gameInput(playerInstance);
	
	return;
}

// Start of the Menu Input instance
void Input::runMenu(int* selected)
{
	menuInput(selected);
	
	return;
}

// Start of the Menu Input instance
void Input::runSettings(int* selected, int* rows, int* cols, int* speed)
{
	settingsInput(selected, rows, cols, speed);
	
	return;
}


void gameInput(Entity& playerInstance)
{
	while ((playerInstance.isAlive && !playerInstance.hasWon) || playerInstance.direction != 0) // Check whenever the Snake is alive and if you haven't won yet, otherwise finish the function and have the thread detached
	{
		if ((GetAsyncKeyState(VK_UP) & 0x8000) && playerInstance.oldDirection != 2) // Set direction up
		{
			playerInstance.direction = 1;
		}
		else if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && playerInstance.oldDirection != 1) // Set direction down
		{
			playerInstance.direction = 2;
		}
		else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && playerInstance.oldDirection != 4) // Set direction left
		{
			playerInstance.direction = 3;
		}
		else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && playerInstance.oldDirection != 3) // Set direction right
		{
			playerInstance.direction = 4;
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000 && (playerInstance.isAlive == false || playerInstance.hasWon == true ))
		{
			while (GetAsyncKeyState(VK_RETURN) & 0x8000) // wait for ENTER to be released
			{
				Sleep(50);
			}
			playerInstance.direction = 0; // Re using the variable for the check after loosing/winning screen to continue

		}
	}
	return;
}

void menuInput(int* selected)
{
	// Flags ensure a single click isn't registered mutliple times	
	bool wasDownPressed = false;
	bool wasUpPressed = false;

	while (true)  // true for testing, this thread should be closed once the menu is closed, ig when u select something it  will set selected to 5 to close the thread and revert to 0 later for next opening
	{
		// Check if DOWN key is currently pressed
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			if (!wasDownPressed) // Check if this is a new key press
			{
				wasDownPressed = true; // Update the state

				if (*selected == 2)
				{
					*selected = 0;
				}
				else
				{
					(*selected)++;
				}
			}
		}
		else
		{
			wasDownPressed = false; // Reset the state if key is not pressed
		}

		// Check if UP key is currently pressed
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			if (!wasUpPressed) // Check if this is a new key press
			{
				wasUpPressed = true; // Update the state

				if (*selected == 0)
				{
					*selected = 2;
				}
				else
				{
					(*selected)--;
				}
			}
		}
		else
		{
			wasUpPressed = false; // Reset the state if key is not pressed
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) // temporary use END to exit the menu and start the game, will change with updates
		{
			switch (*selected)
			{
			case 0: // Start
				*selected = 5; // settubg selected to 5 will cause the selected menu item to initialize and start it's class
				break;			
			case 1: // Setting
				*selected = 6;
				break;			
			case 2: // Help
				*selected = 7;
				break;
			default:
				break;
			}
		}

		// Adding a small delay to prevent CPU overuse
		Sleep(50);
	}
	return;
}





void settingsInput(int* selected, int* rows, int* cols, int*  speed)
{
	// Flags ensure a single click isn't registered mutliple times	
	bool wasDownPressed = false;
	bool wasUpPressed = false;
	bool wasLeftPressed = false;
	bool wasRightPressed = false;

	while (*selected != 5)  // true for testing, this thread should be closed once the menu is closed, ig when u select something it  will set selected to 5 to close the thread and revert to 0 later for next opening
	{



		// Check if DOWN key is currently pressed
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			if (!wasDownPressed) // Check if this is a new key press
			{
				wasDownPressed = true; // Update the state

				if (*selected == 3)
				{
					*selected = 0;
				}
				else
				{
					(*selected)++;
				}
			}
		}
		else
		{
			wasDownPressed = false; // Reset the state if key is not pressed
		}

		// Check if UP key is currently pressed
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			if (!wasUpPressed) // Check if this is a new key press
			{
				wasUpPressed = true; // Update the state

				if (*selected == 0)
				{
					*selected = 3;
				}
				else
				{
					(*selected)--;
				}
			}
		}
		else
		{
			wasUpPressed = false; // Reset the state if key is not pressed
		}

		// Check if UP key is currently pressed
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			if (!wasLeftPressed) // Check if this is a new key press
			{
				wasLeftPressed = true; // Update the state

				switch (*selected)
				{
				case 0:
					(*rows) -= 2;
					break;
				case 1:
					(*cols) -= 2;
					break;
				case 2:
					*speed -= 5;
					break;
				default:
					break;
				}
			}
		}
		else
		{
			wasLeftPressed = false; // Reset the state if key is not pressed
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			if (!wasRightPressed) // Check if this is a new key press
			{
			wasRightPressed = true; // Update the state

				switch (*selected)
				{
				case 0:
					(*rows) += 2;
					break;
				case 1:
					(*cols) += 2;
					break;
				case 2:
					*speed += 5;
					break;
				default:
					break;
				}
			}
		}
		else
		{
			wasRightPressed = false; // Reset the state if key is not pressed
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			if (*selected == 3)
			{
				while ((GetAsyncKeyState(VK_RETURN) & 0x8000)) // wait until release of Enter to metigate bugs
				{
				}
				*selected = 5; // In the settings.cpp there is a check that uses sleceted = 5 to close the settings windows
			}
		}
	}
	return;
}