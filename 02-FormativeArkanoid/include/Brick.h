#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>

class Brick : public sf::Drawable
{
private:
	sf::RectangleShape _shape;

	bool _isBroken = false;

public:
	Brick(sf::Vector2f size);

	void SetPosition(float x, float y) { _shape.setPosition(x, y); }

	auto GetSize() { return _shape.getSize(); }
	auto GetGlobalBounds() { return _shape.getGlobalBounds(); }
	bool IsBroken() { return _isBroken; }

	void Break();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};