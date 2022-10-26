#include "MainController.h"

MainController::MainController()
{
	
}

void MainController::Init()
{
    _window.create(sf::VideoMode(600, 800), "Formative Make Paintings");

    _window.setVerticalSyncEnabled(true);
    _window.setFramerateLimit(30);
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

                    _rect.CreateFirstPainting(sf::Vector2f(_window.getSize().x / 16.0f,
                        _window.getSize().y / 24.0f));

                    //// Graphical Region
                    //_window.clear(sf::Color::Black);

                    ////window.draw(something to draw);
                    //window.draw(rect);

                    //window.display();

                    break;

                case sf::Mouse::Right:

                    _rect.CreateSecondPainting();

                    //_window.clear(sf::Color(150, 150, 150));

                    /*window.draw(rect);

                    window.display();*/
                    break;

                }

            default:
                break;
            }

        }

        _window.clear(sf::Color(150, 150, 150));

        _window.draw(_rect);

        _window.display();
    }

    return EXIT_SUCCESS;
}