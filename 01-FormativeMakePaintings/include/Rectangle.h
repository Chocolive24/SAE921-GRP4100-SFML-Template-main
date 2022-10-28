#pragma once

#include "SFML/Graphics.hpp"

class Rectangle : public sf::Drawable
{
private:
	std::vector<sf::RectangleShape> _rectangles;

public:
	void CreateFirstPainting(sf::Vector2f rectSize);
	void CreateSecondPainting();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};