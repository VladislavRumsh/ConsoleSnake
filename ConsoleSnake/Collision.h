#ifndef COLLISION_H
#define COLLISION_H

#include "GameEntities.h"

class Collision
{
public:
	void collisionWithWall(Entity& playerInstance, Entity& fruitInstance, Game& gameInstance);
	void collisionWithFruit(Entity& playerInstance, Entity& fruitInstance, Game& gameInstance, char** grid);
	void collisionWithBody();
private:

};

#endif