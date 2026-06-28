#include "input.h"
#include <iostream>

void ProcessInput(sf::RenderWindow& window)
{
    while (auto event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }

        else if (event->is<sf::Event::MouseButtonPressed>())
        {
            auto mouse = event->getIf<sf::Event::MouseButtonPressed>();

            std::cout
                << "Mouse: "
                << mouse->position.x
                << ", "
                << mouse->position.y
                << std::endl;
        }
    }
}