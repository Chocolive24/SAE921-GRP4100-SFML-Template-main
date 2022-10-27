#include "Player.h"

Player::Player()
{
	_speed = 20.0f;
}

void Player::Move(const sf::Vector2f& direction)
{
	_bar.Move(direction, _speed);
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
