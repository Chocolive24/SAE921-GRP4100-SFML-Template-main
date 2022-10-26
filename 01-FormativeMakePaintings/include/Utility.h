#pragma once

#include <SFML/Graphics.hpp>

enum class Colors
{
	PINK,
	RED,
	ORANGE,
	PURPLE
};

namespace Utility
{
    int GetRandomInt(int min, int max);

	sf::Color GetAColorVariation(Colors color);
};