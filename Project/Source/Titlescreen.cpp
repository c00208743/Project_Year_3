#include "../Header/Titlescreen.h"

/// <summary>
/// @SplashScreen Title screen to be played before the main menu
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Opening screen to display 
/// </summary>


//constructs the splash screen
Titlescreen::Titlescreen(Game & game) : m_game(&game)
{
	m_currentSelect = 0;

	// Load from a font file on disk
	if (!myFont.loadFromFile("Fonts/Batman.ttf"))
	{
		// Error...
	}
	//const sf::Color &colour = sf::Color::Black;

	text = sf::Text("TITLE SCREEN", myFont, 40);
	//text.setColor(sf::Color(128, 128, 0));
	text.setPosition(200, 200);

	keys = KeyHandler();
}

//destructor
Titlescreen::~Titlescreen()
{
}

//updates screen
void Titlescreen::update()
{
	std::cout << sf::Keyboard::isKeyPressed(sf::Keyboard::Space) << std::endl;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_game->changeGameState(GameState::MainMenu);
	}
}

//draws window
void Titlescreen::render(sf::RenderWindow & window)
{
	window.draw(text);
}



//sets gamestate
void Titlescreen::setStateBack()
{
	//m_game->changeGameState(GameState::TheMenu);
}