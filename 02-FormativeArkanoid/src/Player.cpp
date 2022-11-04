#include "Player.h"

// --------------------------------------------------------------------------------------------------

Player::Player()
{
	_speed = 15.0f;
}

// --------------------------------------------------------------------------------------------------

void Player::MoveLeft(Ball& ball)
{
	// The player can only move if he is on the game window size
	// and if is not intersecting the ball (avoid bugs).
	if (GetPosition().x - GetGlobalBounds().width / 2 >= 0 &&
		!GetGlobalBounds().intersects(ball.GetGlobalBounds()))
	{
		_bar.Move(sf::Vector2f(-1, 0), _speed);
	}
}

// --------------------------------------------------------------------------------------------------

void Player::MoveRight(Ball& ball)
{
	// The player can only move if he is on the game window size
	// and if is not intersecting the ball (avoid bugs).
	if (GetPosition().x + GetGlobalBounds().width / 2 <= 600 &&
		!GetGlobalBounds().intersects(ball.GetGlobalBounds()))
	{
		_bar.Move(sf::Vector2f(1, 0), _speed);
	}
}

// --------------------------------------------------------------------------------------------------

void Player::Launch(Ball& ball)
{
	ball.Move();
}

// --------------------------------------------------------------------------------------------------

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_bar, states);
}

// --------------------------------------------------------------------------------------------------