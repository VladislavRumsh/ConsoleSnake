#ifndef INPUT_H
#define INPUT_H
#include "Entity.h"

class Input 
{
public:
	Input();
	void run(Entity& playerInstance);
private:
	int* direction{};
};
#endif