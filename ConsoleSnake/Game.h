#ifndef GAME_H
#define GAME_H

#include "GameEntities.h"
#include "Render.h"
#include <string>

class Game
{
public:
	Game(int setRows, int setCols, int setGameSpeed);
	void run(Game& gameInstance);
	int rows{}, cols{}, gameSpeed{}, maxScore{};
	bool runGame{}, saveScore{};

private:
	
	std::string sStart{ "Start" }, sSettings{ "Start" }, sHelp{ "Start" };

};

#endif