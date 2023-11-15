#include "Help.h"
#include "Render.h"
#include <windows.h>

Help::Help()
{

}

void Help::run()
{
	renderHelp();

	while ((GetAsyncKeyState(VK_RETURN) & 0x8000)) // A check that Enter was released from the previous window
	{
	}
	while (!(GetAsyncKeyState(VK_RETURN) & 0x8000)) // Press Enter to close HELP window and return to menu
	{
	}
	while ((GetAsyncKeyState(VK_RETURN) & 0x8000)) // wait until release of Enter
	{
	}
	return;
}