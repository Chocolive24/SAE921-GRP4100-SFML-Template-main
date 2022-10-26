

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"
#include "Link.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML First Window");

    Link link;

    // Basic Setup of the window
    // Vertical sync, framerate
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    while (window.isOpen())
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))  // Permet de ne pas avoir de lag quand on laisse appuyé uen touche.
        {
            link.Move(sf::Vector2f(0, -1));
        }

        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                std::cout << event.key.code << std::endl;

                switch (event.key.code)
                {

                case sf::Keyboard::Down:
                    
                    link.Move(sf::Vector2f(0, 1));

                    break;

                case sf::Keyboard::Left:
                    
                    link.Move(sf::Vector2f(-1, 0));

                    break;

                case sf::Keyboard::Right:
                    link.Move(sf::Vector2f(1, 0));

                    break;
                }

            }
        }

        window.clear(sf::Color::Black);

        // Here we draw
        // Draw the _sprite
        window.draw(link);

        // Draw the shape
        /*window.draw(shape);*/

        // effacement les tampons de couleur/profondeur
        window.display();

    }

    return EXIT_SUCCESS;
}
