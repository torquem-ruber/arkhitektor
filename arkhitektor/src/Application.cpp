#include <iostream>
#include "OS/Interface.h";
#include "Menu.h"
#include "Application.h";

int main()
{
    while (true)
    {
        TitleMenuAnimation();

        std::string input;
        std::cin >> input;

        try
        {
            int inputValue = std::stoi(input);
            switch (inputValue)
            {
            case 1: GeneratePlansMenu();  break;
            case 2: AdministerDatabasesMenu();  break;
            case 3: Quit(); return 0;
            default: break;
            }
        }
        catch (...)
        {
            continue;
        }
    }
}

void ClearScreen()
{
    int height;
    Ark::GetTerminalSize(nullptr, &height);
    for (int i = 0; i < height; i++)
        std::cout << "\n";
}

void TitleMenuAnimation()
{
    int height;
    Ark::GetTerminalSize(nullptr, &height);

    for (int i = 0; i < height; i++) 
        std::cout << "\n"; 

    std::cout << banner << "\n\n";
    std::cout << "\t" << "1 - Generate plans" << "\n";
    std::cout << "\t" << "2 - Administer databases" << "\n";
    std::cout << "\t" << "3 - Quit" << "\n";

    for (int i = 0; i < height - 11; i++) { 
        SLEEP(10);
        std::cout << "\n"; 
    }

    std::cout << "> ";;
}

void GeneratePlansMenu()
{
    ClearScreen();
}
void AdministerDatabasesMenu()
{
    ClearScreen();
}
void Quit()
{
    ClearScreen();
}