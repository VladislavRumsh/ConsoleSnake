#ifndef GAMEEND_H
#define GAMEEND_H

#include "HandleHTTP.h"

class GameEnd
{
public:
	GameEnd();
	void run(int rows, int cols, int speed, int score, bool winCondition);
	void printSelection();
	int selected{};
	bool uploadScore{};
private:

};

#endif