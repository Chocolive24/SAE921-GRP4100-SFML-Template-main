#pragma once

#include "Ball.h"
#include "Bar.h"
#include "SFML/Graphics.hpp"

class Player : public sf::Drawable
{
private:
	Bar _bar;
	const sf::Vector2f _direction;
	float _speed;

public:
	Player();

	// ---------------------------------------------------------------------------
	// Getters and Setters.
	Bar& GetBar() { return _bar; }

	auto GetPosition() { return _bar.GetPosition(); }
	void SetPosition(float x, float y) { _bar.SetPosition(x, y);}
	auto GetGlobalBounds() { return _bar.GetGlobalBounds(); }

	// ---------------------------------------------------------------------------
	// Moving Methods.

	void MoveLeft(Ball& ball);
	void MoveRight(Ball& ball);

	// ---------------------------------------------------------------------------

	void Launch(Ball& ball);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};