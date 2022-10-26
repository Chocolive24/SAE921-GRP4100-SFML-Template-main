#include "Link.h"

Link::Link()
{
    _up.loadFromFile("data/sprites/up.png");
    _down.loadFromFile("data/sprites/down.png");
    _right.loadFromFile("data/sprites/right.png");
    _left.loadFromFile("data/sprites/left.png");

    _sprite.setTexture(_up);
    setOrigin(_up.getSize().x / 2.0f, _up.getSize().y / 2.0f);
    //const auto center = window.getSize();
    setPosition(400, 300);

    _speed = 10.0f;

}

void Link::ChangeTexture(const sf::Vector2f& direction)
{
    if (direction.x > 0)
    {
        _sprite.setTexture(_right);
    }

    if (direction.x < 0)
    {
        _sprite.setTexture(_left);
    }

    if (direction.y > 0)
    {
        _sprite.setTexture(_up);
    }

    if (direction.y < 0)
    {
        _sprite.setTexture(_down);
    }
}

void Link::Move(const sf::Vector2f& direction)
{
    
    ChangeTexture(direction);

    // move the _sprite
    auto position = _sprite.getPosition();
    position += direction * _speed;
    _sprite.setPosition(position);
}

void Link::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //RenderTarget = la window (en gros)

    states.transform *= getTransform();

    target.draw(_sprite, states);
}
