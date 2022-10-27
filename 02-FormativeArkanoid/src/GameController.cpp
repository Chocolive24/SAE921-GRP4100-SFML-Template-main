#include "GameController.h"

#include <iostream>

void GameController::Init()
{
    _window.create(sf::VideoMode(1000, 800), "Arkanoid", sf::Style::Close);

    _window.setVerticalSyncEnabled(true);
    _window.setFramerateLimit(30);
}

int GameController::GameLoop()
{
    while (_window.isOpen())
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            _player.Move(sf::Vector2f(1, 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  
        {
            _player.Move(sf::Vector2f(-1, 0));
        }

        sf::Event event;

        while (_window.pollEvent(event))
        {

            switch (event.type)
            {
            case sf::Event::Closed:
                _window.close();
                break;

            case sf::Event::KeyPressed:
				switch (event.key.code)
				{
	            case sf::Keyboard::Space:
                    _launch = true;
                    break;
				}

            default:
                break;
            }
        }

        if (_launch)
        {
            _player.Launch(_ball);
        }

        _ball.Bounce(sf::Vector2f(_window.getSize().x, _window.getSize().y), _player.GetBar().GetBounds());

        _window.clear(sf::Color::Black);

        _window.draw(_player);
        _window.draw(_ball);

        _window.display();
    }

    return EXIT_SUCCESS;
}