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

	void Move(const sf::Vector2f& direction);

	void Launch(Ball& ball);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};