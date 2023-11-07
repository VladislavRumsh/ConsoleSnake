#ifndef FRUIT_H
#define FRUIT_H

class Fruit {
public:
	Fruit();
	void generateCoordinates(int rows, int cols);
	void putOnGrid(char** grid);
	int fruitX{}, fruitY{}, score{}, direction{};
	bool isAlive{};


private:

};

#endif
