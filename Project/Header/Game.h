#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <SFML\Graphics\Rect.hpp>
#include <memory>
#include <vector>
#include "splashscreen.h"
#include "Titlescreen.h"
#include "MainMenuScreen.h"
#include "Platform.h"
#include "Player.h"
#include "WorldSelectScreen.h"
#include "EndGameScreen.h"
#include "LevelLoader.h"
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Audio.hpp>

using namespace std;

class SplashScreen;
class Titlescreen;
class MainMenuScreen;
class Platform;
class Player;
class WorldSelectScreen;
class EndGameScreen;



enum GameState {
	Splash,
	Title,
	MainMenu,
	Gameplay,
	WorldSelect,
	EndGame
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
	void GeneratePlatform();

	sf::RenderWindow m_window;

private:
	void update(sf::Time);
	void render();
	void processInput();

	GameState m_currentGameState = GameState::Gameplay; //current gamestate/screen
	std::unique_ptr<SplashScreen>m_Splash;
	std::unique_ptr<Titlescreen>m_Title;
	std::unique_ptr<MainMenuScreen>m_mainMenu;
	std::unique_ptr<Platform>m_ground;
	std::vector<Platform>m_platform;
	std::unique_ptr<Player>m_player;
	std::unique_ptr<WorldSelectScreen>m_worldSelect;
	std::unique_ptr<EndGameScreen>m_endGame;
	LevelData m_level;

	//time 
	sf::Clock clock;
	sf::Time timeSinceLastUpdate;
	sf::Time timePerFrame;
	float totalTime;

	//Audio
	sf::Music music;
	sf::View m_view;
};

