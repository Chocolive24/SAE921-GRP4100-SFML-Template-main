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

	for (int width = 0; width < 1; width++)
	{
		for (int height = 0; height < 1; height++)
		{
			sf::RectangleShape brick(sf::Vector2f(1000 / 20, 25));

			brick.setFillColor(sf::Color(200, 200, 255));

			brick.setOutlineThickness(-1.0f);
			brick.setOutlineColor(sf::Color::Black);

			//brick.setPosition(brick.getSize().x * width, brick.getSize().y * height);

			brick.setPosition(300, 800 - 100);

			//brick.setPosition(500, 700);

			_bricks.emplace_back(brick);
		}
	}
}


void Brick::Break(sf::RectangleShape& brick)
{
	_sound.play();
	brick.setPosition(-1000, -1000);
}

void Brick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//states.transform *= getTransform();

	for (auto& brick : _bricks)
	{
		target.draw(brick, states);
	}

	
}
