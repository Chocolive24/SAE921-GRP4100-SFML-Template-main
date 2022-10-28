#pragma once 

#include "Rectangle.h"

class MainController
{
private:
	sf::RenderWindow _window;
	sf::Vector2f _windowCenter;

	bool _startScreen = true;

	sf::Font _font;
	sf::Text _text;

	Rectangle _rect;

public:
	void Init();

	int MainLoop();
};