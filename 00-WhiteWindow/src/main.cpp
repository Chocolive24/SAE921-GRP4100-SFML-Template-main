

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML First Window");

    sf::Texture up;
    sf::Texture down;
    sf::Texture right;
    sf::Texture left;

    up.loadFromFile("data/sprites/up.png");
    down.loadFromFile("data/sprites/down.png");
    right.loadFromFile("data/sprites/right.png");
    left.loadFromFile("data/sprites/left.png");

    sf::Sprite sprite;
    sprite.setTexture(up);
    sprite.setOrigin(up.getSize().x / 2.0f, up.getSize().y / 2.0f);
    const auto center = window.getSize();
    sprite.setPosition(center.x / 2.0f, center.y / 2.0f);

    // Basic Setup of the window
    // Vertical sync, framerate
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    // Loading a file as texture
    /*wall.loadFromFile("data/sprites/wall.jpg");*/

    // Using a sprite
    // https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Sprite.php
    /*sf::Sprite sprite;
    sprite.setTexture(wall);
    sprite.setOrigin(wall.getSize().x / 2.0f, wall.getSize().y / 2.0f);*/
    //const auto center = window.getSize();
    /*sprite.setPosition(center.x / 2.0f, center.y / 2.0f);*/

    const float speed = 10.0f;


    while (window.isOpen())
    {
        window.clear(sf::Color::Black);

        auto& spritePosition = sprite.getPosition(); 

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))  // Permet de ne pas avoir de lag quand on laisse appuyé uen touche.
        {
            sprite.setTexture(down);

            sprite.setPosition(spritePosition.x, spritePosition.y - speed);
        }
        sf::Vector2i pos = sf::Mouse::getPosition(window);

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

                //case sf::Keyboard::Up:
                //    sprite.setTexture(down); // C'est le up mais les images ont les noms inversés

                //    sprite.setPosition(spritePosition.x, spritePosition.y - speed);

                //    //sprite.setPosition(pos.x, pos.y);   // test avec la souris

                //    break;

                case sf::Keyboard::Down:
                    sprite.setTexture(up); // C'est le down

                    sprite.setPosition(spritePosition.x, spritePosition.y + speed);

                    break;

                case sf::Keyboard::Left:
                    sprite.setTexture(left);

                    sprite.setPosition(spritePosition.x - speed, spritePosition.y);

                    break;

                case sf::Keyboard::Right:
                    sprite.setTexture(right);

                    sprite.setPosition(spritePosition.x + speed, spritePosition.y);

                    break;
                }

            }
        }

        // Here we draw
        // Draw the sprite
        window.draw(sprite);

        // Draw the shape
        /*window.draw(shape);*/

        // effacement les tampons de couleur/profondeur
        window.display();

    }

    return EXIT_SUCCESS;
}
