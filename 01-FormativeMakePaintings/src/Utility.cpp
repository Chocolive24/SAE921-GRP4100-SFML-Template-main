#include "utility.h"

#include <random>

namespace Utility
{
    // -------------------------------------------------------------------------------------------------------

    int GetRandomInt(int min, int max)
	{
        std::random_device os_seed;
        uint_least32_t seed = os_seed();

        std::mt19937 generator(seed);
        std::uniform_int_distribution<uint_least32_t> distribute(min, max);

        return (int)distribute(generator);
    }

    // -------------------------------------------------------------------------------------------------------

    sf::Color GetAColorVariation(Colors color)
    {
        if (color == Colors::PINK)
        {
            sf::Color pink(GetRandomInt(230, 255),
						   GetRandomInt(150, 255),
						   GetRandomInt(220, 255),
						   200);
            return pink;
        }

    	if (color == Colors::RED) 
        {
            sf::Color red(GetRandomInt(170, 255),
						  GetRandomInt(0, 10),
						  GetRandomInt(0, 10), 
						  200);
            return red;
        }

        if (color == Colors::ORANGE)
        {
            sf::Color orange(GetRandomInt(230, 255),
							 GetRandomInt(100, 120),
							 GetRandomInt(10, 20), 
							 200);
            return orange;
        }

        if (color == Colors::PURPLE) 
        {
            sf::Color purple(GetRandomInt(180, 200),
							 GetRandomInt(80, 100),
							 GetRandomInt(200, 220), 
							 200);
            return purple;
        }
    }

    // -------------------------------------------------------------------------------------------------------
}