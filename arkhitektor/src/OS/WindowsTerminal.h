#pragma once
#include <windows.h>

// DEFINES
#define SLEEP(x) Sleep(x)


namespace Ark
{
	static void GetTerminalSize(int* w, int* h)
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		if(w) *w = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		if(h) *h = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	}
	static void ClearScreen()
	{
		system("cls");
	}
}