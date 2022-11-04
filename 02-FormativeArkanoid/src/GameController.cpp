#include "GameController.h"

// -------------------------------------------------------------------------------------------------------------

void GameController::Init()
{
    // --------------------------------------------------------------------------------------------------
    // Window init part.

    if (!_isWindowCreated)
    {
        _window.create(sf::VideoMode(600, 800), "Arkanoid", sf::Style::Close);

        _window.setVerticalSyncEnabled(true);
        _window.setFramerateLimit(60);
        _isWindowCreated = true;
    }

    sf::Vector2f windowCenter(_window.getSize().x / 2.0f, _window.getSize().y / 2.0f);

    // --------------------------------------------------------------------------------------------------
    // Game Objects init part.

    _ball.SetPosition(windowCenter.x, _window.getSize().y - _ball.GetRadius() - 25);
    _ball.SetVelocity(sf::Vector2f(_ball.GetSpeed() / 2.0f, -(_ball.GetSpeed())));

    _player.SetPosition(windowCenter.x, _window.getSize().y - _player.GetGlobalBounds().height / 2);

    BricksInit();

    // --------------------------------------------------------------------------------------------------
    // Texts init part.

    _displayControls->SetPosition(windowCenter.x, windowCenter.y + _window.getSize().y / 8.0f);
    _restartText->SetPosition(windowCenter.x, windowCenter.y + _window.getSize().y / 8.0f);

    // --------------------------------------------------------------------------------------------------
    // Music and Sounds init part.

    MusicsAndSoundsInit();

    // --------------------------------------------------------------------------------------------------
}

// -------------------------------------------------------------------------------------------------------------

void GameController::BricksInit()
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

// -------------------------------------------------------------------------------------------------------------

void GameController::DeleteBrick()
{
    // Delete bricks that are broken
    _bricks.erase(std::remove_if(_bricks.begin(), _bricks.end(), [](Brick& brick)
        {
            return brick.IsBroken();
        }
    ), _bricks.end());
}

// -------------------------------------------------------------------------------------------------------------

void GameController::MusicsAndSoundsInit()
{
    // ----------------------------------------------------------------------------------
    // Musics load part.

    if (!_mainTheme.openFromFile("data/sound/main_theme.wav"))
    {
        return; // error
    }

    if (!_gameOverTheme.openFromFile("data/sound/game_over.wav"))
    {
        return; // error
    }

    if (!_winTheme.openFromFile("data/sound/win_theme.wav"))
    {
        return; // error
    }

    // ----------------------------------------------------------------------------------
    // Musics management.

    _mainTheme.play();
    _mainTheme.setLoop(true);
    _mainTheme.setVolume(50.0f);

    _gameOverTheme.setVolume(50.0f);
    _winTheme.setVolume(50.0f);

    // ----------------------------------------------------------------------------------
    // Sounds load part.

    if (!_breakBuffer.loadFromFile("data/sound/break_brick.wav"))
    {
        return; // error
    }

    // ----------------------------------------------------------------------------------
    // Sounds management.

    _breakSound.setBuffer(_breakBuffer);
}

// -------------------------------------------------------------------------------------------------------------

void GameController::CheckInput()
{
    // ------------------------------------------------------------------------------
    // Player's movements inputs.

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
    	_player.MoveRight(_ball);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
    	_player.MoveLeft(_ball);
    }

    // ------------------------------------------------------------------------------
    // Game Management inputs.

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
                    _winTheme.stop();
                    _won = false;
                    _launched = false;
                    Init();
                }

            	break;
            }

        default:
            break;
        }
    }

    // ------------------------------------------------------------------------------
}

// -------------------------------------------------------------------------------------------------------------

void GameController::CheckWinAndLose()
{
    // Lose -> the ball fell to the bottom of the screen
    if (_ball.GetTop().y > _window.getSize().y && !_lost)
    {
        _lost = true;
        _mainTheme.stop();
        _gameOverTheme.play();
        _ball.SetVelocity(sf::Vector2f(0, 0));
    }

    // Win -> all the bricks are broken.
    if (_bricks.empty() && !_won)
    {
        _won = true;
        _mainTheme.stop();
        _winTheme.play();
        _ball.SetVelocity(sf::Vector2f(0, 0));
    }
}

// -------------------------------------------------------------------------------------------------------------

void GameController::UpdateObjects()
{
    // If the ball isn't launched, only the player's movements
    // and the ball's default position are updated.

    if (!_launched)
    {
        // The ball's default position is on the top of the player's bar and follow it until
        // the ball is launched.
        _ball.SetPosition(_player.GetPosition().x, 
					    _player.GetPosition().y - _ball.GetGlobalBounds().height);
    }

    // The ball is launched, the game starts and all objects are updated.
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

// -------------------------------------------------------------------------------------------------------------

void GameController::DrawObjects()
{
    // Clear the screen.
    _window.clear(sf::Color::Black);

    // ------------------------------------------------------------------
    // Draw Game Objects.
    _window.draw(_player);
    _window.draw(_ball);

    for (auto& brick : _bricks)
    {
        _window.draw(brick);
    }

    // ------------------------------------------------------------------
    // Draw Game Texts.

    if (!_launched)
    {
        _window.draw(*_startText);
        _window.draw(*_displayControls);
    }

    if (_won)
    {
        _window.draw(*_winText);
        _restartText->SetFillColor(sf::Color::Cyan);
        _window.draw(*_restartText);
    }

    if (_lost)
    {
        _window.draw(*_gameOverText);
        _restartText->SetFillColor(sf::Color::Red);
        _window.draw(*_restartText);
    }

    // ------------------------------------------------------------------
}

// -------------------------------------------------------------------------------------------------------------

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

// -------------------------------------------------------------------------------------------------------------