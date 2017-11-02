#include "../Header/splashscreen.h"

/// <summary>
/// @SplashScreen splash screen to be played before the title screen 
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Opening screen to display company logo
/// </summary>


//constructs the splash screen
SplashScreen::SplashScreen(Game & game) : m_game(&game)
{
	m_currentSelect = 0;

	// Load from a font file on disk
	if (!myFont.loadFromFile("Fonts/powerful.ttf"))
	{
		// Error...
	}

	if (!myFont2.loadFromFile("Fonts/Batman.ttf"))
	{
		// Error...
	}

	text = sf::Text("MAYJORHARD GAMES", myFont, 40);
	text.setPosition(200, 400);

	text2 = sf::Text("(presents)", myFont2, 40);
	text2.setPosition(400, 500);
}

//destructor
SplashScreen::~SplashScreen()
{
}

//updates screen
void SplashScreen::update(sf::Time deltaTime)
{
	m_cumulativeTime += deltaTime;
	if (m_cumulativeTime.asSeconds() >= 2)
	{
		m_game->changeGameState(GameState::Title);
	}

}

//draws window
void SplashScreen::render(sf::RenderWindow & window)
{
	window.draw(text);
	window.draw(text2);
}



//sets gamestate
void SplashScreen::setStateBack()
{
	//m_game->changeGameState(GameState::TheMenu);
}