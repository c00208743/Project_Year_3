#pragma once

/// <summary>
/// @WorldSelectScreen to be played after the main menu when play game is selected
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Opening screen to display company logo
/// </summary>

#include "../Header/Game.h"
#include "../Header/KeyHandler.h"
#include <SFML\Graphics.hpp>

class Game;

class WorldSelectScreen
{
public:
	WorldSelectScreen(Game &game);
	~WorldSelectScreen();
	void update(sf::Time deltaTime);
	void render(sf::RenderWindow & window);
	void setStateBack();

private:

	Game *m_game;

	int m_currentSelect = 0;
	bool conToMenu;
	sf::Time m_cumulativeTime;
	sf::Font myFont;
	sf::Font myFont2;
	sf::Text text[5];
	KeyHandler keys;

};
