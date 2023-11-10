#ifndef GAME_H
#define GAME_H

#include "GameEntities.h"
#include "Render.h"

class Game 
{
public:
	Game();
	void run(Game& gameInstance);
	int rows{}, cols{}, gameSpeed{}, maxScore{};
	bool runGame{};

private:

};

#endif