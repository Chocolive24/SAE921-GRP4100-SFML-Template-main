#pragma once

#include "Ball.h"
#include "Brick.h"
#include "Player.h"
#include "GameText.h"
#include "SFML/Graphics.hpp"

class GameController
{
private:
	sf::RenderWindow _window;

	Player _player;
	Ball _ball;

	std::vector<Brick> _bricks;

	

	GameText* _restartText = new GameText("PRESS ENTER \n  TO RESTART", 50, 
									      sf::Color::Red, sf::Text::Bold);

	GameText* _startText   = new GameText("PRESS SPACE \n    TO START", 50, 
									      sf::Color::Cyan, sf::Text::Bold);

	GameText* _displayControls = new GameText("USE THE SIDE ARROWS TO MOVE", 25,
											  sf::Color::Cyan, sf::Text::Bold);

	GameText* _winText = new GameText("YOU WON !!!", 50, 
									  sf::Color::Cyan, sf::Text::Bold);

	GameText* _gameOverText = new GameText("GAME OVER", 50,
									       sf::Color::Red, sf::Text::Bold);

	bool _isWindowCreated = false;
	bool _launched = false;

	sf::Music _mainTheme;
	sf::Music _gameOverTheme;

	sf::Sound _breakSound;
	sf::SoundBuffer _breakBuffer;

	bool _lost = false;

public:

	void CreateBricks();
	void DeleteBrick();

	void Init();

	void CheckInput();
	void CheckWinAndLose();

	void UpdateObjects();
	void DrawObjects();

	int GameLoop();
};