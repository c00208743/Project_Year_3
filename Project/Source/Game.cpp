#include "../Header/Game.h"



Game::Game() :
	m_window(sf::VideoMode(2560, 1440), "Sean and Jamie's Game")
{
	m_Splash = make_unique<SplashScreen>(*this);
	m_Title = make_unique<Titlescreen>(*this);
	m_mainMenu = make_unique<MainMenuScreen>(*this);
	m_worldSelect = make_unique<WorldSelectScreen>(*this);
	m_endGame = make_unique<EndGameScreen>(*this);
	
}


Game::~Game()
{
}

void Game::init()
{
	// Display the list of all the video modes available for fullscreen
	//vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
	timePerFrame = sf::seconds(1.0f / 60.0f);
}

void Game::run()
{
	timeSinceLastUpdate = sf::Time::Zero;

	while (m_window.isOpen())
	{
		processInput();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}
		render();

	}
}

void Game::render()
{
	m_window.clear(sf::Color(0, 0, 0, 255));

	switch (m_currentGameState)
	{
	case GameState::Splash:
		m_Splash->render(m_window);
		break;

	case GameState::Title:
		m_Title->render(m_window);
		break;

	case GameState::MainMenu:
		m_mainMenu->render(m_window);
		break;

	case GameState::WorldSelect:
		m_worldSelect->render(m_window);
		break;

	case GameState::EndGame:
		m_endGame->render(m_window);
		break;

	default:
		break;

	}

	m_window.display();
}

void Game::update(sf::Time time)
{
	totalTime += timeSinceLastUpdate.asSeconds(); // Accumulative time

	switch (m_currentGameState)
	{
	case GameState::Splash:
		m_Splash->update(time);
		m_window.setView(m_view2);
		break;

	case GameState::Title:
		m_Title->update(time);
		m_window.setView(m_view2);
		break;

	case GameState::MainMenu:
		m_mainMenu->update(time);
		m_window.setView(m_view2);
		break;

	case GameState::WorldSelect:
		m_worldSelect->update(time);
		m_window.setView(m_view2);
		break;

	case GameState::EndGame:
		m_endGame->update(time);
		m_window.setView(m_view2);
		break;

	default:
		break;

	}
}

void Game::processInput()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		default:
			break;
		}
	}
}

//function to change the games current gamestate
void Game::changeGameState(GameState gameState)
{
	m_currentGameState = gameState;
}