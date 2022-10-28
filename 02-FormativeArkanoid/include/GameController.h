#pragma once

#include "Ball.h"
#include "Brick.h"
#include "Player.h"
#include "SFML/Graphics.hpp"

class GameController
{
private:
	sf::RenderWindow _window;

	Player _player;
	Ball _ball;
	Brick _brick;

	bool _launched = false;


public:

	void Init();

	void CheckInput();

	void Update();

	int GameLoop();
};