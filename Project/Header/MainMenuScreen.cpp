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

	if (!m_Texture.loadFromFile("Images/Background-Menu.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(0, 0);
	m_Sprite.setScale(1.2, 1.2);

	text[0] = sf::Text("MAIN MENU", myFont, 100);
	text[0].setPosition(800, 400);

	text[1] = sf::Text("[PLAY][GAME]", myFont2, 100);
	text[1].setPosition(900, 700);
	text[1].setFillColor(sf::Color::Black);
	text[2] = sf::Text("(EXIT)", myFont2, 100);
	text[2].setPosition(1100, 900);
	text[2].setFillColor(sf::Color::Black);
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
	window.draw(m_Sprite);
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