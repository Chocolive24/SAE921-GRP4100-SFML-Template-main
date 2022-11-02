#include "Ball.h"

#include <iostream>


Ball::Ball()
{
	_radius = 10.0f;
	_shape.setRadius(_radius);

	_shape.setOrigin(_shape.getGlobalBounds().width / 2.0f, _shape.getGlobalBounds().height / 2.0f);
	//_shape.setPosition(500, 800 - 5);

	_speed = 10.0f;

	/*_velocity.x = _speed / 2.0f;
	_velocity.y = 0;*/
	/*_velocity.x = 0;*/
	/*_velocity.y = 0;*/

	if (!_barBuffer.loadFromFile("data/sound/bar_collision.wav"))
	{
		return;
	}

	_barSound.setBuffer(_barBuffer);
	_barSound.setVolume(50.0f);

	if (!_wallBuffer.loadFromFile("data/sound/wall.wav"))
	{
		return;
	}

	_wallSound.setBuffer(_wallBuffer);
}

void Ball::Move()
{
	auto position = _shape.getPosition();
	position += _velocity;
	_shape.setPosition(position);
}

void Ball::Bounce(sf::Vector2f wallNormal)
{
	if (_shape.getPosition().y - _radius <= 0)
	{
		_barSound.play();
		_velocity.y *= -1;
	}

	if (_shape.getPosition().x - _radius <= 0 || _shape.getPosition().x + _radius >= wallNormal.x)
	{
		_barSound.play();
		_velocity.x *= -1;
	}

}

void Ball::BarCollision(Bar& bar)
{

	auto bounds = bar.GetGlobalBounds();

		_barSound.play();
		_velocity.y *= -1;

	if (GetBottom().x >= bar.GetMiddle().x && GetBottom().x <= bar.GetRightCorner().x)
	{
		if (_velocity.x < 0)
		{
			_velocity.x *= -1;
		}

		_velocity.x = (0.10f * (GetBottom().x - bar.GetMiddle().x)) + _speed / 2;

	}

	else if (GetBottom().x <= bar.GetMiddle().x && GetBottom().x >= bar.GetLeftCorner().x)
	{
		if (_velocity.x > 0)
		{

			_velocity.x *= -1;
		}

		_velocity.x = (-0.10f * (bar.GetMiddle().x - GetBottom().x)) - _speed / 2;
	}

	else if (bounds.contains(GetRight()))
	{
		_shape.setPosition(bar.GetLeftCorner() + sf::Vector2f(-1, 0));
		_velocity.x = (-0.10f * (bar.GetMiddle().x - GetBottom().x)) - _speed / 2;
	}


	else if (bounds.contains(GetLeft()))
	{
		_shape.setPosition(bar.GetRightCorner() + sf::Vector2f(1, 0));
		_velocity.x = (0.10f * (GetBottom().x - bar.GetMiddle().x)) + _speed / 2;
	}

//}

/*else
{*/
	/*if (GetGlobalBounds().contains(bar.GetRightCorner()))
	{
		_shape.setPosition(bar.GetRightCorner() + sf::Vector2f(1, 0));

		_velocity.x = (0.10f * (GetBottom().x - bar.GetMiddle().x)) + _speed / 2;
		_velocity.y = -10;
		std::cout << "LE COIN" << std::endl;
	}

	else if (GetGlobalBounds().contains(bar.GetLeftCorner()))
	{
		_shape.setPosition(bar.GetLeftCorner() + sf::Vector2f(-1, 0));
		_velocity.x = (-0.10f * (bar.GetMiddle().x - GetBottom().x)) - _speed / 2;

		std::cout << "LE COIN" << std::endl;
	}*/
//}
}

void Ball::BrickCollision(Brick& brick)
{
	auto bounds = brick.GetGlobalBounds();
	
	if (bounds.contains(GetTop()) || bounds.contains(GetBottom()))
	{
		_velocity.y *= -1;
	}

	else if (bounds.contains(GetLeft()) || bounds.contains(GetRight()))
	{
		_velocity.x *= -1;
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
	target.draw(_shape, states);
}