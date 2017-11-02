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
	//if (!shader.loadFromFile("upgrade.frag", sf::Shader::Fragment))
	//{
	//	std::string s("error loading shader");
	//	//throw std::exception(s.c_str);
	//}
	//shader.setParameter("time", 0);
	//shader.setParameter("resolution", 1000, 800);
	//shader.setParameter("mouse", 3, 3);

	//if (!shaderTxt.loadFromFile("images/shaderTxt.png"))
	//{
	//	std::string s("error loading shader texture");
	//	//throw std::exception(s.c_str);
	//}
	//shaderSprite.setTexture(shaderTxt);
	//shaderSprite.setPosition(0, 0);

	text = sf::Text("(Main) (menu)", myFont, 40);
	//text.setColor(sf::Color(128, 128, 0));
	text.setPosition(200, 200);
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
	window.draw(text);
	//window.draw(shaderSprite, &shader);
}



//sets gamestate
void MainMenuScreen::setStateBack()
{
	//m_game->changeGameState(GameState::TheMenu);
}