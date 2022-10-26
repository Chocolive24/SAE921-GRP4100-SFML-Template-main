#pragma once 
#include "Rectangle.h"

class MainController
{
private:
	sf::RenderWindow _window;

	Rectangle _rect;

public:
	MainController();

	void Init();

	int MainLoop();
};