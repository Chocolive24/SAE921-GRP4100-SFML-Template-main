#include "GameText.h"

GameText::GameText(std::string string, int characterSize, sf::Color color, sf::Text::Style style)
{
    if (!_font.loadFromFile("data/font/arial.ttf"))
    {
        return; // error
    }

    _text.setFont(_font);

    _text.setString(string);
    _text.setCharacterSize(characterSize);
    _text.setFillColor(color);
    _text.setStyle(style);

    _text.setOrigin(_text.getLocalBounds().width / 2, _text.getLocalBounds().height / 2);
    _text.setPosition(600 / 2.0f, (800 / 2.0f) - _text.getOrigin().y);
}

void GameText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_text, states);
}
