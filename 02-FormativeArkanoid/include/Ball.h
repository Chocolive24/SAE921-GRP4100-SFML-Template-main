#pragma once

#include "Bar.h"
#include "Brick.h"
#include <SFML/Audio.hpp>
#include "SFML/Graphics.hpp"

class Ball : public sf::Drawable
{
private:
	sf::CircleShape _shape;

	float _radius;

	float _speed;
	sf::Vector2f _velocity;

	sf::Sound _barSound;
	sf::SoundBuffer _barBuffer;
	sf::Sound _wallSound;
	sf::SoundBuffer _wallBuffer;

public:
	// -----------------------------------------------------------------------------------------------------------
	// Constructor

	Ball();

	// -----------------------------------------------------------------------------------------------------------
	// Moving methods.

	void Move();

	void Bounce(sf::Vector2f wallNormal);

	// -----------------------------------------------------------------------------------------------------------
	// Colliding methods.

	bool isColliding(sf::FloatRect bounds);
	void BarCollision(Bar& bar);
	void BrickCollision(Brick& brick);

	// -----------------------------------------------------------------------------------------------------------
	// Getters and Setters.

	float GetRadius() { return _radius; }

	float GetSpeed() { return _speed; }
	auto SetVelocity(sf::Vector2f newVelocity) { _velocity = newVelocity; }

	auto GetPosition() { return _shape.getPosition(); }
	void SetPosition(float x, float y) { _shape.setPosition(x, y); }

	auto GetGlobalBounds() { return _shape.getGlobalBounds(); }

	sf::Vector2f GetTop()    { return sf::Vector2f(_shape.getPosition().x, _shape.getPosition().y - _radius); }
	sf::Vector2f GetBottom() { return sf::Vector2f(_shape.getPosition().x, _shape.getPosition().y + _radius); }
	sf::Vector2f GetLeft()   { return sf::Vector2f(_shape.getPosition().x - _radius, _shape.getPosition().y); }
	sf::Vector2f GetRight()  { return sf::Vector2f(_shape.getPosition().x + _radius, _shape.getPosition().y); }

	// -----------------------------------------------------------------------------------------------------------

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// -----------------------------------------------------------------------------------------------------------
};