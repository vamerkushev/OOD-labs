#include "Application.h"
#include "ShapeManager.h"
#include "SFMLDrawer.h"
#include "Config.h"
#include <SFML/Graphics.hpp>

void Application::Run() 
{
    ShapeManager manager;

    if (!manager.LoadFromFile(Config::INPUT_FILE)) 
    {
        return;
    }

    manager.SaveToFile(Config::OUTPUT_FILE);
    manager.PrintToConsole();

    sf::RenderWindow window(sf::VideoMode(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT), Config::WINDOW_TITLE);

    SFMLDrawer drawer(window);
    drawer.Render(manager.GetShapes());
}