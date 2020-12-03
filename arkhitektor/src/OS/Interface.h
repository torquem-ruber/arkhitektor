#pragma once

#ifdef __linux__
	#warning Linux functionality is untested
	#include "LinuxTerminal.h"

#elif _WIN32
	#include "WindowsTerminal.h"
#else
	#error Only windows and linux supported!
#endif