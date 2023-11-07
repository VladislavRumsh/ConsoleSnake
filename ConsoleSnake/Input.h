#ifndef INPUT_H
#define INPUT_H


class Input 
{
public:
	Input();
	void run(int* directions);
private:
	int* direction{};
};
#endif