#ifndef GAME_H
#define GAME_H


class Game {
public:
	Game();
	void run();
	void generateRndCoords(int* x, int* y);

private:
	int rows{}, cols{};
	bool runGame{};
};



#endif