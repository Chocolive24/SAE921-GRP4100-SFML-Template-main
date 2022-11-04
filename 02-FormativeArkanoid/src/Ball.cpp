#include "Ball.h"

// -----------------------------------------------------------------------------------------------------------

Ball::Ball()
{
	_radius = 10.0f;
	_shape.setRadius(_radius);

	_shape.setOrigin(_shape.getGlobalBounds().width / 2.0f, _shape.getGlobalBounds().height / 2.0f);

	_speed = 10.0f;

	if (!_bounceBuffer.loadFromFile("data/sound/bar_collision.wav"))
	{
		return;
	}

	_bounceSound.setBuffer(_bounceBuffer);
	_bounceSound.setVolume(50.0f);
}

// -----------------------------------------------------------------------------------------------------------

void Ball::Move()
{
	auto position = _shape.getPosition();
	position += _velocity;
	_shape.setPosition(position);
}

// -----------------------------------------------------------------------------------------------------------

void Ball::Bounce(sf::Vector2f wallNormal)
{
	// Bounce on the top of the screen.
	if (_shape.getPosition().y - _radius <= 0)
	{
		_bounceSound.play();
		_velocity.y *= -1;
	}

	// Bounce and the sides of the screen.
	if (_shape.getPosition().x - _radius <= 0 || _shape.getPosition().x + _radius >= wallNormal.x)
	{
		_bounceSound.play();
		_velocity.x *= -1;
	}
}

// -----------------------------------------------------------------------------------------------------------

bool Ball::isColliding(sf::FloatRect bounds)
{
	// Check if there is a collision between the ball and an object.
	if (bounds.contains(GetTop()) || bounds.contains(GetBottom()) ||
		bounds.contains(GetLeft()) || bounds.contains(GetRight()))
	{
		return true;
	}

	return false;
}

// -----------------------------------------------------------------------------------------------------------

void Ball::BarCollision(Bar& bar)
{
	auto bounds = bar.GetGlobalBounds();

	_bounceSound.play();

	// The ball bounces upwards no matter which side of the bar it hits.
	_velocity.y *= -1;

	// Bounce on the right part of the bar. The ball will bounce back to the right.
	if (GetBottom().x >= bar.GetMiddle().x && GetBottom().x <= bar.GetRightCorner().x)
	{
		// If the ball is going left, make it go right.
		if (_velocity.x < 0)
		{
			_velocity.x *= -1;
		}

		// The x-direction of the ball will be proportional to 10%
		// of the distance from the ball's rebound point to the middle of the bar plus the speed. 
		_velocity.x = (0.10f * (GetBottom().x - bar.GetMiddle().x)) + _speed / 2;
	}

	// Bounce on the left part of the bar. The ball will bounce back to the left.
	else if (GetBottom().x <= bar.GetMiddle().x && GetBottom().x >= bar.GetLeftCorner().x)
	{
		// If the ball is going right, make it go left.
		if (_velocity.x > 0)
		{

			_velocity.x *= -1;
		}

		// The x-direction of the ball will be proportional to - 10%
		// of the distance from the ball's rebound point to the middle of the bar minus the speed. 
		_velocity.x = (-0.10f * (bar.GetMiddle().x - GetBottom().x)) - _speed / 2;
	}

	// Check collision with the right bar side.
	else if (bounds.contains(GetRight()))
	{
		// Set the ball position outside the bar to avoid bugs.
		_shape.setPosition(bar.GetLeftCorner() + sf::Vector2f(- 1, - _radius));

		// Apply the velocity calculation to the x-direction.
		_velocity.x = (-0.10f * (bar.GetMiddle().x - GetBottom().x)) - _speed / 2;
	}

	// Check collision in the left bar corner.
	else if (bounds.contains(GetLeft()))
	{
		// Set the ball position outside the bar to avoid bugs.
		_shape.setPosition(bar.GetRightCorner() + sf::Vector2f(1, - _radius));

		// Apply the velocity calculation to the x-direction.
		_velocity.x = (0.10f * (GetBottom().x - bar.GetMiddle().x)) + _speed / 2;
	}
}

// -----------------------------------------------------------------------------------------------------------

void Ball::BrickCollision(Brick& brick)
{
	auto bounds = brick.GetGlobalBounds();

	// Bounce on top or bottom of bricks.
	if (bounds.contains(GetTop()) || bounds.contains(GetBottom()))
	{
		_velocity.y *= -1;
	}

	// Bounce on right or left side of bricks.
	else if (bounds.contains(GetLeft()) || bounds.contains(GetRight()))
	{
		_velocity.x *= -1;
	}
}

// -----------------------------------------------------------------------------------------------------------

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_shape, states);
}

// -----------------------------------------------------------------------------------------------------------