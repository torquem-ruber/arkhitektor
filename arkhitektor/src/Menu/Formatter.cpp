#include "Formatter.h"
#include "OS/Interface.h"

namespace Ark
{
	int GetLineCount(const char* text)
	{
        char current = text[0];
        if (current == '\0') return 0;

        int w, h;
        Ark::GetTerminalSize(&w, &h);

        int lines = 1;
        int index = 0;
        int xIndex = 0;
        while (current != '\0')
        {
            if (xIndex > w-1)
            {
                lines++;
                xIndex = 0;
                index--;
            }
            else
            {
                xIndex++;
                if (current == '\n') 
                {
                    lines++;
                    xIndex = 0;
                }
            }

            index++;
            current = text[index];
        }

        return lines;
	}
}