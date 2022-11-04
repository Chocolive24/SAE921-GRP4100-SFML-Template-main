#pragma once

#include <SFML/Graphics.hpp>

class GameText : public sf::Drawable
{
private:
	sf::Font _font;
	sf::Text _text;

public:

	GameText(std::string string, int characterSize, sf::Color color, sf::Text::Style style);

	// ----------------------------------------------------------------------------------------------
	// Getters and Setters.

	void SetPosition(float x, float y) { _text.setPosition(x, y); }
	void SetFillColor(sf::Color newColor) { _text.setFillColor(newColor); }

	// ----------------------------------------------------------------------------------------------

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};