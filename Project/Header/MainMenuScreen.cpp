#include "../Header/MainMenuScreen.h"

/// <summary>
/// @SplashScreen Title screen to be played before the main menu
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Opening screen to display 
/// </summary>


//constructs the splash screen
MainMenuScreen::MainMenuScreen(Game & game) : m_game(&game)
{
	m_currentSelect = 0;

	// Load from a font file on disk
	if (!myFont.loadFromFile("Fonts/Batman.ttf"))
	{
		// Error...
	}
	//const sf::Color &colour = sf::Color::Black;

	text = sf::Text("(Main) (menu)", myFont, 40);
	//text.setColor(sf::Color(128, 128, 0));
	text.setPosition(200, 200);
}

//destructor
MainMenuScreen::~MainMenuScreen()
{
}

//updates screen
void MainMenuScreen::update()
{

}

//draws window
void MainMenuScreen::render(sf::RenderWindow & window)
{
	window.draw(text);
}



//sets gamestate
void MainMenuScreen::setStateBack()
{
	//m_game->changeGameState(GameState::TheMenu);
}