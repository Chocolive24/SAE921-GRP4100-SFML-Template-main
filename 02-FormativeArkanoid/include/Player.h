#pragma once

#include "Ball.h"
#include "Bar.h"
#include "SFML/Graphics.hpp"

class Player : public sf::Drawable, sf::Transformable
{
private:

	Bar _bar;

	const sf::Vector2f _direction;

	float _speed;

public:

	Player();

	Bar& GetBar() { return _bar; }

	void MoveLeft();
	void MoveRight();

	void Launch(Ball& ball);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};