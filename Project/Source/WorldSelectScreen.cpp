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
	if (!m_Texture.loadFromFile("Images/Background-Menu.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(0, 0);
	m_Sprite.setScale(1.2, 1.2);


	text[0] = sf::Text("WORLD SELECT ", myFont, 100);
	text[0].setPosition(800, 400);

	text[1] = sf::Text("(world One)", myFont2, 100);
	text[1].setFillColor(sf::Color::Red);
	text[1].setPosition(1000, 600);
	text[2] = sf::Text("[world Two]", myFont2, 100);
	text[2].setFillColor(sf::Color::Black);
	text[2].setPosition(1000, 800);
	text[3] = sf::Text("(world Three)", myFont2, 100);
	text[3].setFillColor(sf::Color::Black);
	text[3].setPosition(1000, 1000);


	keys = KeyHandler();
}

//destructor
WorldSelectScreen::~WorldSelectScreen()
{
}

//updates screen
void WorldSelectScreen::update(sf::Time deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		m_game->changeGameState(GameState::Gameplay);
	}
}

//draws window
void WorldSelectScreen::render(sf::RenderWindow & window)
{
	window.draw(m_Sprite);
	for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++)
	{
		window.draw(text[i]);
	}

}
