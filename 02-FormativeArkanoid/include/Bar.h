#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

class Bar : public sf::Drawable
{
private:
	sf::RectangleShape _shape;

public:
	Bar();

	auto GetSIze() { return _shape.getSize(); }

	auto GetPosition() { return _shape.getPosition(); }

	void Move(const sf::Vector2f& direction, float speed);

	sf::FloatRect GetBounds()
	{
		return _shape.getGlobalBounds();
	}

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};