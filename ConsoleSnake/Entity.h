#pragma once
#ifndef ENTITY_H
#define ENTITY_H


#include "Random.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>

class Entity
{
public:
	Entity();
	void generateCoordinates(Entity& playerInstance, Game& gameInstance);
	void putOnGrid(char** grid);
	void stepForward(Entity& playerInstance, char** grid);
	void removeFromGrid(Entity& playerInstance, char** grid);
	int entityX{}, entityY{}, score{}, direction{}, oldDirection{};
	bool isAlive{};
	int entityId{}; // 1 - Snake's head, 2 - Fruit

private:


};

#endif
