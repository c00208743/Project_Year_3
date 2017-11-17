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
	// Load from a font file on disk
	if (!myFont.loadFromFile("Fonts/powerful.ttf"))
	{
		std::cout << "First main menu font failed to load" << std::endl;
	}

	if (!myFont2.loadFromFile("Fonts/Batman.ttf"))
	{
		std::cout << "Second main menu font failed to load" << std::endl;
	}

	m_currentSelect = 0;

	m_title = new Label("MAIN MENU", 200.0f, 200.0f, "powerful.ttf");
	m_gui.addLabel(m_title);

	m_play = new Button("Play", 200.0f, 500.0f);
	m_play->gainFocus();
	m_play->Enter = std::bind(&MainMenuScreen::goToLevelSelect, this);
	m_gui.addButton(m_play);

	m_quit = new Button("Quit", 200.0f, 600.0f);
	m_quit->Enter = std::bind(&MainMenuScreen::quit, this);
	m_gui.addButton(m_quit);



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


}

//destructor
MainMenuScreen::~MainMenuScreen()
{
}

//updates screen
void MainMenuScreen::update(sf::Time deltaTime)
{
	//std::cout << sf::Keyboard::isKeyPressed(sf::Keyboard::A) << std::endl;

	/*updateShader = m_cumulativeTime.asSeconds();
	shader.setParameter("time", updateShader);*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//m_game->changeGameState(GameState::WorldSelect);
	}

	m_gui.update(m_currentSelect, 2);

}

//draws window
void MainMenuScreen::render(sf::RenderWindow & window)
{
	for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++)
	{
		window.draw(text[i]);
	}

	m_gui.draw(window);
}



//sets gamestate
void MainMenuScreen::setStateBack()
{
	//m_game->changeGameState(GameState::TheMenu);
}

void MainMenuScreen::quit()
{
	m_game->m_window.close();
}

void MainMenuScreen::goToLevelSelect()
{
	m_game->changeGameState(GameState::WorldSelect);
}