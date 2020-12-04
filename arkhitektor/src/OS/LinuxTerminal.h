#pragma once
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

// DEFINES
#define WAIT(x) usleep(x/1000)


namespace Ark
{
	static void GetTerminalSize(int* w, int* h)
	{
		struct winsize win;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
		if (w) *w = win.ws_col;
		if (h) *h = win.ws_row;
	}
	static void ClearScreen()
	{
		system("clear");
	}
}