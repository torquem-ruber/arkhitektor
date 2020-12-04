#include <iostream>
#include <string>

#include "Application.h"
#include "Menu/Menu.h"
#include "Menu/Formatter.h"
#include "OS/Interface.h"

int main()
{
    Application::InitMenus();
    Application::EnterMenu(startMenu);
    return 0;
}

void Application::EnterMenu(Ark::Menu* menu)
{
    bool animate = menu->m_Animate;

    while (true)
    {
        if (menu->m_Event != nullptr)
            menu->m_Event();

        int height;
        Ark::GetTerminalSize(nullptr, &height);
        for (int i = 0; i < height; i++)
            std::cout << "\n";

        const char* title = menu->m_Title;
        int menuSize = Ark::GetLineCount(title);
        std::cout << "\n" << title;
        std::cout << "\n\n"; menuSize += 3;

        size_t size = 0;
        const char** labels = menu->GetItemLabels(size);
        menuSize += size;

        for (size_t i = 0; i < size; i++)
            std::cout << "\t" << labels[i] << "\n";

        for (int i = 0; i < (height - menuSize); i++)
        {
            if(animate) WAIT(10);
            std::cout << "\n";
        }
        std::cout << "> ";

        char* input = new char();
        std::cin >> input;

        Ark::Menu* target = menu->CheckInput(input);
        if (target == nullptr)
        {
            Application::InvalidInput(&input);
            animate = false;
            continue;
        }

        animate = target->m_Animate;
        menu = target;
    }
}

void Application::ClearScreen()
{
    int height;
    Ark::GetTerminalSize(nullptr, &height);
    for (int i = 0; i < height; i++)
        std::cout << "\n";
}

void Application::InvalidInput(char** input)
{
    int height;
    Ark::GetTerminalSize(nullptr, &height);
    for (int i = 0; i < height; i++)
        std::cout << "\n";

    std::cout << "\t\"" << *input << "\"" << " is not a valid input...";

    for (int i = 0; i < height - 2; i++)
        std::cout << "\n";

    WAIT(1000);
}

void Application::Quit()
{
    exit(0);
}

void Application::InitMenus()
{
    startMenu->AddItem("1 - Generate Plans", "1", planMenu);
    startMenu->AddItem("2 - Administer Databases", "2", nullptr);
    startMenu->AddItem("3 - Settings", "3", nullptr);
    startMenu->AddItem("", "0", nullptr);
    startMenu->AddItem("q - Quit", "q", quitMenu);

    planMenu->AddItem("1 - Option A", "1", nullptr);
    planMenu->AddItem("2 - Option B", "2", nullptr);
    planMenu->AddItem("3 - Option C", "3", nullptr);
    planMenu->AddItem("4 - Option D", "4", nullptr);
    planMenu->AddItem("", "0", nullptr);
    planMenu->AddItem("q - Back", "q", startMenu);
}