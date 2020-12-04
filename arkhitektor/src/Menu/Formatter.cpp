#include "Formatter.h"
#include "OS/Interface.h"

namespace Ark
{
	int GetLineCount(const char* text)
	{
        char current = text[0];
        if (current == '\0') return 0;

        int w;
        Ark::GetTerminalSize(&w, nullptr);

        int lines = 1, index = 0;
        while (current != '\0')
        {
            if ((index+1)-((lines-1)*w) > w) { lines++; }
            else if (current == '\n')    { lines++; }

            current = text[index++];
        }

        return lines;
	}

    bool FitsConsole(const char* text)
    {
        int w;
        Ark::GetTerminalSize(&w, nullptr);

        int index = 0;
        int xIndex = 0;
        char current = text[0];
        while (current != '\0')
        {
            if (xIndex > w) return false;
            if (current == '\n') xIndex = 0;

            xIndex++;
            current = text[index++];
        }
        return true;
    }
}