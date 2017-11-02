#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <SFML\Graphics\Rect.hpp>
#include <memory>
#include <vector>
#include "../Header/splashscreen.h"
#include "../Header/Titlescreen.h"
#include "../Header/MainMenuScreen.h"

using namespace std;

class SplashScreen;
class Titlescreen;
class MainMenuScreen;

enum GameState {
	Splash,
	Title,
	MainMenu
};

/// <summary>
/// Game Class
/// </summary>
class Game
{
public:
	Game();
	~Game();

	void init();
	void run();
	
	void changeGameState(GameState gameState); //function to change the screen

	sf::RenderWindow m_window;

private:
	void update(sf::Time);
	void render();
	void processInput();

	GameState m_currentGameState = GameState::Splash; //current gamestate/screen
	std::unique_ptr<SplashScreen>m_Splash;
	std::unique_ptr<Titlescreen>m_Title;
	std::unique_ptr<MainMenuScreen>m_mainMenu;

	//views
	sf::View m_view;
	sf::View m_view2;

	//time 
	sf::Clock clock;
	sf::Time timeSinceLastUpdate;
	sf::Time timePerFrame;
	float totalTime;
};

