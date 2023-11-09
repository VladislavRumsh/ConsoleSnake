#ifndef RANDOM_H
#define RANDOM_H

#include "GameEntities.h"
#include <random>
#include <chrono>

class Snake;  // Forward declaration
class Entity;  // Forward declaration
class Fruit;  // Forward declaration
class Game;   // Forward declaration

int randomNum(int num);
void randomCoords(Entity& playerInstance, Game& gameInstance, char** grid);

#endif