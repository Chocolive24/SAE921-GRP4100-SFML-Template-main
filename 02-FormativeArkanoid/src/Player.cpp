#include "Player.h"

Player::Player()
{
	_speed = 15.0f;
}

void Player::MoveLeft()
{
	if (_bar.GetPosition().x - _bar.GetBounds().width / 2 >= 0)
	{
		_bar.Move(sf::Vector2f(-1, 0), _speed);
	}
}

void Player::MoveRight()
{
	if (_bar.GetPosition().x + _bar.GetBounds().width / 2 <= 1000)
	{
		_bar.Move(sf::Vector2f(1, 0), _speed);
	}
}

void Player::Launch(Ball& ball)
{
	ball.Move(sf::Vector2f(-1, -1));
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(_bar, states);
}
