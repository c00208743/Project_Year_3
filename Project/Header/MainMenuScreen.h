#pragma once

/// <summary>
/// @MainMenuScreen Title screen to be played after the title screen
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Dsiplay player options
/// </summary>

#include "../Header/Game.h"
#include <SFML\Graphics.hpp>

class Game;

class MainMenuScreen
{
public:
	MainMenuScreen(Game &game);
	~MainMenuScreen();
	void update();
	void render(sf::RenderWindow & window);
	void setStateBack();

private:

	Game *m_game;

	int m_currentSelect = 0;
	sf::Time m_CumulativeTime;
	sf::Font myFont;
	sf::Text text;


};
