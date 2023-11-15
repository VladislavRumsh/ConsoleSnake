#ifndef SETTINGS_H
#define SETTINGS_H

#include "Render.h"

class Settings
{
public:
	Settings();
	void run(int* rows, int* cols, int* speed);
	void printSelection(int* rows, int* cols, int* speed);
	int selected{};
private:

};

#endif