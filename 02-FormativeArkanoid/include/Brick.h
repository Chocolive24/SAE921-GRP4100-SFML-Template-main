#pragma once

#include "Ball.h"
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>

class Brick : public sf::Drawable
{
private:
	sf::RectangleShape _shape;

	std::vector<sf::RectangleShape> _bricks;

	sf::Sound _sound;
	sf::SoundBuffer _buffer;


public:
	Brick();

	std::vector<sf::RectangleShape>& GetBricks() { return _bricks; }

	void CreateBricks();

	void Break(sf::RectangleShape& brick);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};