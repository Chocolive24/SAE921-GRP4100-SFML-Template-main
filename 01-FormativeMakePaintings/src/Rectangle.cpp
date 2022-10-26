#include "Rectangle.h"
#include "Utility.h"

void Rectangle::CreateFirstPainting(sf::Vector2f rectSize)
{
    _rectangles.clear();

    for (int width = 0; width < 16; width++)
    {
        for (int height = 0; height < 24; height++)
        {
            int randomColor = Utility::GetRandomInt(1, 100);

            sf::RectangleShape rect(rectSize);

            rect.setPosition(rect.getSize().x * width, rect.getSize().y * height);

            if (randomColor >= 1 && randomColor <= 10)
            {
                sf::Color red = Utility::GetAColorVariation(Colors::RED);
                rect.setFillColor(red);
            }

            else if (randomColor >= 11 && randomColor <= 15)
            {
                sf::Color orange = Utility::GetAColorVariation(Colors::ORANGE);
                rect.setFillColor(orange);
            }

            else if (randomColor == 16)
            {
                sf::Color purple = Utility::GetAColorVariation(Colors::PURPLE);
                rect.setFillColor(purple);
            }

            else
            {
                sf::Color pink = Utility::GetAColorVariation(Colors::PINK);
                rect.setFillColor(pink);
            }

            rect.setOutlineThickness(2.0f);
            rect.setOutlineColor(sf::Color(0, 0, 0));

            _rectangles.emplace_back(rect);
        }
    }
}

void Rectangle::CreateSecondPainting()
{
    _rectangles.clear();

    int rectNbr = 8;

    // The real rect number is the number of rect wanted multiplied by 2
    // because there is a shadow rect for each rect.
    int realRectNbr = rectNbr * 2;

    for (int idxRect = 0; idxRect < realRectNbr; idxRect++)
    {
        sf::RectangleShape rect;

        rect.setFillColor(sf::Color(0, 0, 0, 0));

        rect.setOutlineThickness(5.0f);

        if (_rectangles.size() < rectNbr)
        {
            int width = Utility::GetRandomInt(50, 350);
            int height = Utility::GetRandomInt(width - 50, width + 50);

            rect.setSize(sf::Vector2f(width, height));

            int x = Utility::GetRandomInt(50, 250);
            int y = Utility::GetRandomInt(200, 300);

            rect.setPosition(x, y);

            rect.setOutlineColor(sf::Color(110, 110, 110));

            _rectangles.emplace_back(rect);

        }

        else
        {
            auto size = _rectangles[idxRect - rectNbr].getSize();
            rect.setSize(size);

            auto position = _rectangles[idxRect - rectNbr].getPosition();
            rect.setPosition(position.x - 10, position.y - 20);

            rect.setOutlineColor(sf::Color(50, 50, 50));

            _rectangles.emplace_back(rect);
        }
    }
}

void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& rect : _rectangles)
    {
        target.draw(rect, states);
    }
}