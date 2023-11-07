#ifndef SNAKE_H
#define SNAKE_H

class Snake
{
public:
	Snake();
	void generateCoordinates(int rows, int cols);
	void putOnGrid(char** grid);
	void stepForward(char** grid);
	void removeFromGrid(int X, int Y, char** grid);
	int snakeX{}, snakeY{}, score{}, direction{};
	bool isAlive{};



private:

};

#endif
