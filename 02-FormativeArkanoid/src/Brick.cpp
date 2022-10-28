#include "Brick.h"

#include <iostream>



Brick::Brick()
{
	if (!_buffer.loadFromFile("data/sound/pop.wav"))
	{
		return;
	}

	_sound.setBuffer(_buffer);
}

void Brick::CreateBricks()
{
	// incruster les attributs de class Window

	for (int width = 0; width < 20; width++)
	{
		for (int height = 0; height < 10; height++)
		{
			sf::RectangleShape brick(sf::Vector2f(1000 / 20, 25));

			brick.setFillColor(sf::Color(200, 200, 255));

			brick.setOutlineThickness(-1.0f);
			brick.setOutlineColor(sf::Color::Black);

			brick.setPosition(brick.getSize().x * width, brick.getSize().y * height);

			_bricks.emplace_back(brick);
		}
	}
}

bool Brick::Break(Ball& ball)
{
	for (auto& brick : _bricks)
	{
		auto bounds = brick.getGlobalBounds();

		if (bounds.contains(ball.GetTop()) || bounds.contains(ball.GetBottom()) ||
			bounds.contains(ball.GetLeft()) || bounds.contains(ball.GetRight()))
		{
			_sound.play();
			brick.setPosition(-1000, -1000);

			return true;
		}

		
	}

	return false;
}

void Brick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//states.transform *= getTransform();

	for (auto& brick : _bricks)
	{
		target.draw(brick, states);
	}
}
