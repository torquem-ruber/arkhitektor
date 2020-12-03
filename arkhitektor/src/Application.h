#pragma once
#include "Menu/Menu.h"

const char* banner = R"(
          __              ___  ___      ___  __   __  
     /\  |__) |__/ |__| |  |  |__  |__/  |  /  \ |__) 
    /~~\ |  \ |  \ |  | |  |  |___ |  \  |  \__/ |  \ 
_________________________________________________________
)";

Ark::Menu* startMenu = new Ark::Menu(banner, true);
Ark::Menu* planMenu = new Ark::Menu("\n\tAdminister Plans", false);
Ark::Menu* databaseMenu = new Ark::Menu("\n\tAdminister Databases", false);
Ark::Menu* settingsMenu = new Ark::Menu("\n\tSettings", false);

namespace Application
{
    void EnterMenu(Ark::Menu* menu);
    void ClearScreen();
    void InvalidInput(char**);
    void Quit();
}

Ark::Menu* quitMenu = new Ark::Menu(Application::Quit);