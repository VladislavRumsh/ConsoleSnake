#pragma once
#ifndef ENTITY_H
#define ENTITY_H


#include "Random.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <vector>

class Entity
{
public:
	Entity();
	void generateCoordinates(Entity& playerInstance, Game& gameInstance, char** grid);
	void putOnGrid(char** grid);
	void stepForward(Entity& playerInstance, char** grid);
	void removeFromGrid(Entity& playerInstance, char** grid);
	void growBody();
	int entityX{}, entityY{}, score{}, direction{}, oldDirection{};
	bool isAlive{}, growBodyCheck{}, hasWon{};
	int entityId{}; // 1 - Snake's Head/Body, 2 - Fruit
	std::vector<Entity> body;


private:


};

#endif
