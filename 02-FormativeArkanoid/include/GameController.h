#pragma once

#include "Ball.h"
#include "Brick.h"
#include "GameText.h"
#include "Player.h"
#include "SFML/Graphics.hpp"

class GameController
{
private:
	// ----------------------------------------------------------------------------------------------------
	// Game Window.

	sf::RenderWindow _window;

	// ----------------------------------------------------------------------------------------------------
	// Game Objects.

	Player _player;
	Ball _ball;
	std::vector<Brick> _bricks;

	// ----------------------------------------------------------------------------------------------------
	// Game Texts.

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

	// ----------------------------------------------------------------------------------------------------
	// Game Booleans / Game States.

	bool _isWindowCreated = false;
	bool _launched = false;
	bool _lost = false;
	bool _won = false;

	// ----------------------------------------------------------------------------------------------------
	// Game Musics and Sounds.

	sf::Music _mainTheme;
	sf::Music _gameOverTheme;
	sf::Music _winTheme;

	sf::Sound _breakSound;
	sf::SoundBuffer _breakBuffer;

	// ----------------------------------------------------------------------------------------------------

public:
	// Game Init.

	void Init();

	// ----------------------------------------------------------------------------------------------------
	// Bricks Management.

	void BricksInit();
	void DeleteBrick();

	// ----------------------------------------------------------------------------------------------------
	// Musics and Sounds Management.

	void MusicsAndSoundsInit();

	// ----------------------------------------------------------------------------------------------------
	// Input and Game States Management

	void CheckInput();
	void CheckWinAndLose();

	// ----------------------------------------------------------------------------------------------------
	// Objects Management

	void UpdateObjects();
	void DrawObjects();

	// ----------------------------------------------------------------------------------------------------
	// Game Loop.

	int GameLoop();

	// ----------------------------------------------------------------------------------------------------
};