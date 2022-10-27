#pragma once

#include "SFML/Graphics.hpp"

class Ball : public sf::Drawable, sf::Transformable
{
private:
	sf::CircleShape _shape;

	float _radius;

	sf::Vector2f _direction;

	float _speed;

	sf::Vector2f _velocity;

public:
	Ball();

	void Move(sf::Vector2f direction);

	void Bounce(sf::Vector2f wallNormal, sf::FloatRect bounds);

	auto GetPosition() { return getPosition(); }

	bool isColliding(sf::FloatRect bounds);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
};