#ifndef FRUIT_H
#define FRUIT_H

class Fruit 
{
public:
	Fruit();
	void generateCoordinates(int rows, int cols);
	void putOnGrid(char** grid);
	void removeFromGrid(int X, int Y, char** grid);
	int fruitX{}, fruitY{}, isAlive{};


private:

};

#endif
