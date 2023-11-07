#ifndef GAME_H
#define GAME_H


class Game 
{
public:
	Game();
	void run();

private:
	int rows{}, cols{}, gameSpeed{};
	bool runGame{};
};


void sleep_ms(int gameSpeed);

#endif