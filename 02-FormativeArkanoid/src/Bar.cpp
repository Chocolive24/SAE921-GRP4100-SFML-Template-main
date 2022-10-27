#include "Bar.h"

Bar::Bar()
{
	_shape.setSize(sf::Vector2f(100, 15));

	_shape.setOrigin(_shape.getGlobalBounds().width / 2.0f, _shape.getGlobalBounds().height / 2.0f);
	_shape.setPosition(500, 800 - _shape.getGlobalBounds().height / 2);
}

void Bar::Move(const sf::Vector2f& direction, float speed)
{
	auto position = _shape.getPosition();
	position += direction * speed;
	_shape.setPosition(position);
}

void Bar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//states.transform *= _shape.getTransform();

	target.draw(_shape, states);
}
