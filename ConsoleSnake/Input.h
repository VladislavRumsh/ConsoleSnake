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
private:
	int* direction{};
};

void gameInput(Entity& playerInstance);
void menuInput(int* selected);

#endif