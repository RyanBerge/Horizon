#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "spritesheet.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Horizon");

    Spritesheet main_title{"MainTitle"};

    while (window.isOpen())
    {
        sf::Event event;

        window.clear(sf::Color::Black);
        main_title.Draw(window);
        window.display();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }

    return 0;
}
