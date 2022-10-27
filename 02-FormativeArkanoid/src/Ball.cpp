#include "Ball.h"

#include <iostream>

Ball::Ball()
{
	_radius = 10.0f;
	_shape.setRadius(_radius);

	
	setPosition(500, 800 - 15 - _radius - 50);
	setOrigin(_shape.getGlobalBounds().width / 2.0f, _shape.getGlobalBounds().height / 2.0f);

	_speed = 10.0f;

	_velocity.x = _speed;
	_velocity.y = - (_speed);
}

void Ball::Move(sf::Vector2f direction)
{
	auto position = getPosition();
	position += _velocity;
	setPosition(position);
}

void Ball::Bounce(sf::Vector2f wallNormal, sf::FloatRect bounds)
{
	if (getPosition().y - _radius <= 0)
	{
		_velocity.y = -_velocity.y;
	}

	if (getPosition().x - _radius <= 0 || getPosition().x + _radius >= wallNormal.x)
	{
		_velocity.x = -_velocity.x;
	}

	if (isColliding(bounds))
	{
		_velocity.y = -_velocity.y;
	}

}

bool Ball::isColliding(sf::FloatRect bounds)
{
	if (bounds.contains(getPosition().x, getPosition().y + _radius))
	{
		return true;
	}

	return false;
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(_shape, states);
}
