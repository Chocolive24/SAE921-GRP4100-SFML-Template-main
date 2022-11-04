#include "Brick.h"

// -----------------------------------------------------------------------------------------------------------

Brick::Brick(sf::Vector2f size)
{
	_shape.setSize(size);

	_shape.setFillColor(sf::Color(200, 200, 255));

	_shape.setOutlineThickness(-1.0f);
	_shape.setOutlineColor(sf::Color::Black);
}

// -----------------------------------------------------------------------------------------------------------

void Brick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_shape, states);
}

// -----------------------------------------------------------------------------------------------------------