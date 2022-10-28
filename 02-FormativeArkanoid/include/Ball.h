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

	void Bounce(sf::Vector2f wallNormal, sf::FloatRect bounds, bool isCollidingBrick);

	auto GetPosition() { return getPosition(); }

	sf::Vector2f GetTop() { return sf::Vector2f(getPosition().x, getPosition().y - _radius); }
	sf::Vector2f GetBottom() { return sf::Vector2f(getPosition().x, getPosition().y + _radius); }
	sf::Vector2f GetLeft() { return sf::Vector2f(getPosition().x - _radius, getPosition().y); }
	sf::Vector2f GetRight() { return sf::Vector2f(getPosition().x + _radius, getPosition().y); }


	float GetRadius() { return _radius; }

	bool isColliding(sf::FloatRect bounds);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
};