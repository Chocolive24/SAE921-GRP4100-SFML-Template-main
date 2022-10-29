#include "Ball.h"

#include <iostream>

Ball::Ball()
{
	_radius = 10.0f;
	_shape.setRadius(_radius);

	
	_shape.setPosition(500, 800 - 15 - _radius - 50);
	_shape.setOrigin(_shape.getGlobalBounds().width / 2.0f, _shape.getGlobalBounds().height / 2.0f);

	_speed = 10.0f;

	_velocity.x = _speed / 2.0f;
	/*_velocity.y = - (_speed);*/
	/*_velocity.x = 0;*/
	_velocity.y = 0;

}

void Ball::Move(sf::Vector2f direction)
{
	auto position = _shape.getPosition();
	position += _velocity;
	_shape.setPosition(position);
}



void Ball::Bounce(sf::Vector2f wallNormal)
{
	if (_shape.getPosition().y - _radius <= 0 || _shape.getPosition().y >= 800)
	{
		_velocity.y = -_velocity.y;
	}

	if (_shape.getPosition().x - _radius <= 0 || _shape.getPosition().x + _radius >= wallNormal.x)
	{
		_velocity.x = -_velocity.x;
	}

}

void Ball::CollideBounce(sf::FloatRect bounds)
{
	if (isColliding(bounds))
	{
		// TODO checker les GetTop etc. pour changer les bonnes vitesses -> GetTop -> vitesse.x = -vitesse.x
		std::cout << "LOL";
		_velocity.x = -_velocity.x;
	}
}

bool Ball::isColliding(sf::FloatRect bounds)
{
	if (bounds.contains(GetTop())  || bounds.contains(GetBottom()) ||
		bounds.contains(GetLeft()) || bounds.contains(GetRight()))
	{
		return true;
	}

	return false;
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//states.transform *= getTransform();

	target.draw(_shape, states);
}