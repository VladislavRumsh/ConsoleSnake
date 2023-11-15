#ifndef INPUT_H
#define INPUT_H
#include "Entity.h"
#include "Menu.h"
class Input 
{
public:
	Input();
	void runGame(Entity& playerInstance);
	void runMenu(int* selected);
	void runSettings(int* selected, int* rows, int* cols, int* speed);
private:
	int* direction{};
};

void gameInput(Entity& playerInstance);
void menuInput(int* selected);
void settingsInput(int* selected, int* rows, int* cols, int* speed);

#endif