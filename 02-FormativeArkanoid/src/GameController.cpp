#include "GameController.h"

#include <iostream>

// TODO méthodes pour load les sounds

void GameController::CreateBricks()
{
    for (int width = 2; width < 10; width++)
    {
        for (int height = 2; height < 8; height++)
        {
            Brick brick(sf::Vector2f(50, 30));

            brick.SetPosition(brick.GetSize().x * width, brick.GetSize().y * height);

            _bricks.emplace_back(brick);
        }
    }
}

void GameController::DeleteBrick()
{
    // Delete bricks that are broken
    _bricks.erase(std::remove_if(_bricks.begin(), _bricks.end(), [](Brick& brick)
        {
            return brick.IsBroken();
        }
    ), _bricks.end());
}

void GameController::Init()
{
    if (!_isWindowCreated)
    {
        _window.create(sf::VideoMode(600, 800), "Arkanoid", sf::Style::Close);

        _window.setVerticalSyncEnabled(true);
        _window.setFramerateLimit(60);
        _isWindowCreated = true;
    }

    sf::Vector2f windowCenter(_window.getSize().x / 2.0f, _window.getSize().y / 2.0f);

    CreateBricks();
    
    _ball.SetPosition(windowCenter.x, _window.getSize().y - _ball.GetRadius() - 25);
    _ball.SetVelocity(sf::Vector2f(_ball.GetSpeed() / 2.0f, -(_ball.GetSpeed()) ));

    _player.SetPosition(windowCenter.x, _window.getSize().y - _player.GetGlobalBounds().height / 2);

    _displayControls->SetPosition(windowCenter.x, windowCenter.y + _window.getSize().y / 8.0f);
    _restartText->SetPosition(windowCenter.x, windowCenter.y + _window.getSize().y / 8.0f);

    if (!_mainTheme.openFromFile("data/sound/main_theme.wav"))
    {
        return; // error
    }

    _mainTheme.setVolume(50.0f);
    _mainTheme.play();
    _mainTheme.setLoop(true);

    if (!_breakBuffer.loadFromFile("data/sound/break_brick.wav"))
    {
        return;
    }

    _breakSound.setBuffer(_breakBuffer);

    if (!_gameOverTheme.openFromFile("data/sound/game_over.wav"))
    {
        return;
    }

    _gameOverTheme.setVolume(50.0f);
}

void GameController::CheckInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
    	_player.MoveRight(_ball);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
    	_player.MoveLeft(_ball);
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

	        case sf::Keyboard::Enter:
                if (_lost)
                {
                    _bricks.clear();
                    _gameOverTheme.stop();
                    _lost = false;
                    _launched = false;
                    Init();
                }

                else if (_bricks.empty())
                {
                    // _winTheme.stop();
                    _launched = false;
                    Init();
                }

            	break;
            }

        default:
            break;
        }
    }
}

void GameController::CheckWinAndLose()
{
    if (_ball.GetTop().y > _window.getSize().y && !_lost)
    {
        _lost = true;
        _mainTheme.stop();
        _gameOverTheme.play();
        _ball.SetVelocity(sf::Vector2f(0, 0));
    }

    if (_bricks.empty() && !_lost)
    {
        _mainTheme.stop();
        // play music win
        _ball.SetVelocity(sf::Vector2f(0, 0));
    }
}

void GameController::UpdateObjects()
{
    if (!_launched)
    {
        _ball.SetPosition(_player.GetPosition().x, 
					    _player.GetPosition().y - _ball.GetGlobalBounds().height);
    }

    else
    {
        _ball.Move();

        _ball.Bounce(sf::Vector2f(_window.getSize().x, _window.getSize().y));

        if (_ball.isColliding(_player.GetGlobalBounds()))
        {
            _ball.BarCollision(_player.GetBar());
        }

        for (auto& brick : _bricks)
        {
            if (_ball.isColliding(brick.GetGlobalBounds()))
            {
                _ball.BrickCollision(brick);
                _breakSound.play();
                brick.Break();
                DeleteBrick();
            }
        }

        CheckWinAndLose();
    }
}

void GameController::DrawObjects()
{
    _window.clear(sf::Color::Black);

    _window.draw(_player);
    _window.draw(_ball);

    for (auto& brick : _bricks)
    {
        _window.draw(brick);
    }

    if (!_launched)
    {
        _window.draw(*_startText);
        _window.draw(*_displayControls);
    }

    if (_bricks.empty())
    {
        _window.draw(*_winText);
    }

    if (_lost)
    {
        _window.draw(*_gameOverText);
        _window.draw(*_restartText);
    }

}

int GameController::GameLoop()
{
    while (_window.isOpen())
    {
        CheckInput();

        UpdateObjects();

        DrawObjects();

        _window.display();
    }
    return EXIT_SUCCESS;
}
