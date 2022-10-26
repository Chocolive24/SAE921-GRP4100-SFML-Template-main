#pragma once

#include"SFML/Graphics.hpp"

class Link : public sf::Drawable, public sf::Transformable
{
private:
    sf::Texture _up;
    sf::Texture _down;
    sf::Texture _right;
    sf::Texture _left;

    sf::Sprite _sprite;

	float _speed;

    void ChangeTexture(const sf::Vector2f& direction);

public:
    Link();

    void Move(const sf::Vector2f& direction);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};