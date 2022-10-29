#pragma once

#include "SFML/Graphics.hpp"

class Ball : public sf::Drawable
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

	void Bounce(sf::Vector2f wallNormal);

	void CollideBounce(sf::FloatRect bounds);

	auto GetPosition() { return _shape.getPosition(); }

	sf::Vector2f GetTop() { return sf::Vector2f(_shape.getPosition().x, _shape.getPosition().y - _radius); }
	sf::Vector2f GetBottom() { return sf::Vector2f(_shape.getPosition().x, _shape.getPosition().y + _radius); }
	sf::Vector2f GetLeft() { return sf::Vector2f(_shape.getPosition().x - _radius, _shape.getPosition().y); }
	sf::Vector2f GetRight() { return sf::Vector2f(_shape.getPosition().x + _radius, _shape.getPosition().y); }


	float GetRadius() { return _radius; }

	bool isColliding(sf::FloatRect bounds);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
};