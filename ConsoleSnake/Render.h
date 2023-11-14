#ifndef RENDER_H
#define RENDER_H

#include "Game.h"

class Game;
void renderGame(Game& gameInstance, char** grid, int score);
void deAllocateGrid(int raws, char** grid);
void buildGrid(Game& gameInstance, char** grid);
void asciiConsoleSnake();

#endif 
