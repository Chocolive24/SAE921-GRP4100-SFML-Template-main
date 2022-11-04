#pragma once

#include <SFML/Audio.hpp>
#include "SFML/Graphics.hpp"

class Brick : public sf::Drawable
{
private:
	sf::RectangleShape _shape;

	bool _isBroken = false;

public:
	Brick(sf::Vector2f size);

	// --------------------------------------------------------------------------------------
	// Getters and Setters.

	void SetPosition(float x, float y) { _shape.setPosition(x, y); }

	auto GetSize() { return _shape.getSize(); }
	auto GetGlobalBounds() { return _shape.getGlobalBounds(); }
	bool IsBroken() { return _isBroken; }
	void Break() { _isBroken = true; }

	// --------------------------------------------------------------------------------------

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};