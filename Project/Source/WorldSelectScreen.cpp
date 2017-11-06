#include "../Header/WorldSelectScreen.h"

/// <summary>
/// @WorldSelectScreento be played after the main menu
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Opening screen to display 
/// </summary>


//constructs the splash screen
WorldSelectScreen::WorldSelectScreen(Game & game) : m_game(&game)
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


	text[0] = sf::Text("WORLD SELECT ", myFont, 40);
	text[0].setPosition(100, 100);

	text[1] = sf::Text("(world One)", myFont2, 40);
	text[1].setFillColor(sf::Color::Blue);
	text[1].setPosition(700, 400);
	text[2] = sf::Text("[world Two]", myFont2, 40);
	text[2].setPosition(700, 500);
	text[3] = sf::Text("(world Three)", myFont2, 40);
	text[3].setPosition(700, 600);


	keys = KeyHandler();
}

//destructor
WorldSelectScreen::~WorldSelectScreen()
{
}

//updates screen
void WorldSelectScreen::update(sf::Time deltaTime)
{
	
}

//draws window
void WorldSelectScreen::render(sf::RenderWindow & window)
{
	for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++)
	{
		window.draw(text[i]);
	}

}



//sets gamestate
void WorldSelectScreen::setStateBack()
{
	//m_game->changeGameState(GameState::TheMenu);
}