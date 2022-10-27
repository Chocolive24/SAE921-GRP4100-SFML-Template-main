#pragma once

#include "Ball.h"
#include "Bar.h"
#include "Player.h"
#include "SFML/Graphics.hpp"

class GameController
{
private:
	sf::RenderWindow _window;

	//Bar _bar;
	Player _player;
	Ball _ball;

	bool _launch = false;


public:

	void Init();

	int GameLoop();
};