#include "Rectangle.h"
#include "Utility.h"

// ------------------------------------------------------------------------------------------------------------

void Rectangle::CreateFirstPainting(sf::Vector2f rectSize)
{
    _rectangles.clear();

    // Loop that is activated for each rectangle in width and height
    for (int width = 0; width < 16; width++)
    {
        for (int height = 0; height < 24; height++)
        {
            int randomColor = Utility::GetRandomInt(1, 100);

            sf::RectangleShape rect(rectSize);

            rect.setPosition(rect.getSize().x * width, rect.getSize().y * height);

            // 10% chance that the rect is red
            if (randomColor >= 1 && randomColor <= 10)
            {
                sf::Color red = Utility::GetAColorVariation(Colors::RED);
                rect.setFillColor(red);
            }

            // 5% chance that the rect is orange
            else if (randomColor >= 11 && randomColor <= 15)
            {
                sf::Color orange = Utility::GetAColorVariation(Colors::ORANGE);
                rect.setFillColor(orange);
            }

            // 1% chance that the rect is purple
            else if (randomColor == 16)
            {
                sf::Color purple = Utility::GetAColorVariation(Colors::PURPLE);
                rect.setFillColor(purple);
            }

            // The other rect are pink
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

// ------------------------------------------------------------------------------------------------------------

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

        // Create a shadow rectangle.
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

        // Create the normal rectangles after the shadows ones.
        // Like that they are added to the back of the vector and thus drawn over the shadows.
        else
        {
            // The index is the current index of the "for loop" minus the rect number.
            // Like that each rectangles get the properties of its corresponding shadow rectangle.

            // Get the size of the corresponding shadow rectangle to apply it to the normal one.
            auto size = _rectangles[idxRect - rectNbr].getSize();
            rect.setSize(size);

            // Get the position of the corresponding shadow rectangle and change it a little bit
            // to create the shadow effect.
            auto position = _rectangles[idxRect - rectNbr].getPosition();
            rect.setPosition(position.x - 10, position.y - 20);

            rect.setOutlineColor(sf::Color(50, 50, 50));

            _rectangles.emplace_back(rect);
        }
    }
}

// ------------------------------------------------------------------------------------------------------------

void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& rect : _rectangles)
    {
        target.draw(rect, states);
    }
}

// ------------------------------------------------------------------------------------------------------------