#include "MainController.h"

void MainController::Init()
{
    _window.create(sf::VideoMode(600, 800), 
				  "Formative Make Paintings", sf::Style::Close);
    _window.setVerticalSyncEnabled(true);
    _window.setFramerateLimit(30);
    _windowCenter.x = _window.getSize().x / 2.0f;
	_windowCenter.y = _window.getSize().y / 2.0f;

    _font.loadFromFile("data/font/arial.ttf");
    _text.setFont(_font);
    _text.setString("Left click   : colorful painting \nRight click : grey painting");
    _text.setCharacterSize(24); 
    _text.setFillColor(sf::Color::Black);
    _text.setStyle(sf::Text::Bold);

    _text.setOrigin(_text.getLocalBounds().width / 2, _text.getLocalBounds().height / 2);
    _text.setPosition(_windowCenter.x, (_windowCenter.y - _text.getOrigin().y));
}

int MainController::MainLoop()
{
    while (_window.isOpen())
    {
        // on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
        sf::Event event;

        while (_window.pollEvent(event))
        {
            switch (event.type)
            {
                // �v�nement "fermeture demand�e" : on ferme la fen�tre
            case sf::Event::Closed:
                _window.close();
                break;

            case sf::Event::MouseButtonPressed:

                switch (event.mouseButton.button)
                {
                case sf::Mouse::Left:

                    _startScreen = false;

                    _rect.CreateFirstPainting(sf::Vector2f(
                        _window.getSize().x / 16.0f,
                        _window.getSize().y / 24.0f));

                    break;

                case sf::Mouse::Right:

                    _startScreen = false;

                    _rect.CreateSecondPainting();

                    break;
                }

            default:
                break;
            }
        }

        _window.clear(sf::Color(150, 150, 150));

        if (_startScreen)
        {
            _window.clear(sf::Color(150, 200, 255));
            _window.draw(_text);
        }
        
        _window.draw(_rect);

        _window.display();
    }

    return EXIT_SUCCESS;
}