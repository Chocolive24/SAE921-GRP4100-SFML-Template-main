#include "GameController.h"

#include <iostream>

void GameController::Init()
{
    _window.create(sf::VideoMode(1000, 800), "Arkanoid", sf::Style::Close);

    _window.setVerticalSyncEnabled(true);
    _window.setFramerateLimit(60);

    _brick.CreateBricks();
}

void GameController::CheckInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
    	_player.MoveRight();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
    	_player.MoveLeft();
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
                _launched = true;
                break;
            }

        default:
            break;
        }
    }
}

void GameController::Update()
{
	_ball.Bounce(sf::Vector2f(_window.getSize().x, _window.getSize().y));

    _ball.CollideBounce(_player.GetBar().GetBounds());

    for (auto& brick : _brick.GetBricks())
    {
        if (_ball.isColliding(brick.getGlobalBounds()))
        {
            _ball.CollideBounce(brick.getGlobalBounds());
            _brick.Break(brick);
        }
    }
}

int GameController::GameLoop()
{
    while (_window.isOpen())
    {
        CheckInput();

        if (_launched)
        {
            _player.Launch(_ball);
        }

        _window.clear(sf::Color::Black);

        Update();

        //std::cout << _ball.GetPosition().x << " "<<  _ball.GetPosition().y << std::endl;

        _window.draw(_player);
        _window.draw(_ball);
        _window.draw(_brick);

        _window.display();
    }

    return EXIT_SUCCESS;
}
