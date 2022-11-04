#pragma once

#include "SFML/Graphics.hpp"

class Bar : public sf::Drawable
{
private:
	sf::RectangleShape _shape;

public:
	Bar();

	// -----------------------------------------------------------------------------------------------
	// Getters and Setters

	auto GetSize() { return _shape.getSize(); }

	auto GetPosition() { return _shape.getPosition(); }
	auto SetPosition(float x, float y) { _shape.setPosition(x, y); }

	sf::FloatRect GetGlobalBounds() { return _shape.getGlobalBounds(); }

	auto GetMiddle() { return sf::Vector2f(_shape.getPosition().x, 
											        _shape.getPosition().y); }

	auto GetRightCorner() { return sf::Vector2f(
									_shape.getPosition().x + _shape.getSize().x / 2.0f, 
									_shape.getPosition().y - _shape.getSize().y / 2); }

	auto GetLeftCorner() { return sf::Vector2f(
									_shape.getPosition().x - _shape.getSize().x / 2.0f,
									_shape.getPosition().y - _shape.getSize().y / 2); }

	// -----------------------------------------------------------------------------------------------

	void Move(const sf::Vector2f& direction, float speed);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};