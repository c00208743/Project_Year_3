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
	if (!myFont.loadFromFile("Fonts/powerful.ttf"))
	{
		// Error...
	}

	if (!myFont2.loadFromFile("Fonts/Batman.ttf"))
	{
		// Error...
	}

	//if (!shaderTxt.loadFromFile("Images/Background.jpg"))
	//{
	//	std::string s("error loading shader texture");
	//	//throw std::exception(s.c_str);
	//}
	//shaderSprite.setTexture(shaderTxt);
	//shaderSprite.setPosition(0, 0);

	//if (!shader.loadFromFile("Shader/upgrade.frag", sf::Shader::Fragment))
	//{
	//	std::string s("error loading shader");
	//	//throw std::exception(s.c_str);
	//}
	//shader.setParameter("time", 0);
	//shader.setParameter("mouse", 0, 0);
	//shader.setParameter("resolution", 1000, 800);

	text[0] = sf::Text("MAIN MENU", myFont, 40);
	//text.setColor(sf::Color(128, 128, 0));
	text[0].setPosition(200, 200);

	text[1] = sf::Text("[PLAY_GAME]", myFont2, 30);
	text[1].setPosition(200, 500);
	text[2] = sf::Text("(EXIT)", myFont2, 30);
	text[2].setPosition(200, 600);
}

//destructor
MainMenuScreen::~MainMenuScreen()
{
}

//updates screen
void MainMenuScreen::update(sf::Time deltaTime)
{
	std::cout << sf::Keyboard::isKeyPressed(sf::Keyboard::A) << std::endl;

	/*updateShader = m_cumulativeTime.asSeconds();
	shader.setParameter("time", updateShader);*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_game->changeGameState(GameState::WorldSelect);
	}

}

//draws window
void MainMenuScreen::render(sf::RenderWindow & window)
{
	for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++)
	{
		window.draw(text[i]);
	}
	/*window.draw(shaderSprite, &shader);*/
}



//sets gamestate
void MainMenuScreen::setStateBack()
{
	//m_game->changeGameState(GameState::TheMenu);
}