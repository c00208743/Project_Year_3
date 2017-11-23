#include "../Header/MainMenuScreen.h"
#include <iostream>

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

	if (!shaderTxt.loadFromFile("Images/Background.jpg"))
	{
		std::string s("error loading shader texture");
		//throw std::exception(s.c_str);
	}
	shaderSprite.setTexture(shaderTxt);
	shaderSprite.setPosition(0, 0);

	if (!shader.loadFromFile("Shader/shader.frag", sf::Shader::Fragment))
	{
		std::string s("error loading shader");
		//throw std::exception(s.c_str);
	}
	shader.setUniform("time", 0.0f);
	shader.setUniform("mouse", sf::Vector2f(0.5f, 0.8f));
	shader.setUniform("resolution", sf::Vector2f(2560, 1440));
	//shader.setUniform("backbuffer", sf::Shader::CurrentTexture);

	m_currentSelect = 0;

	m_title = new Label("MAIN MENU", 800.0f, 400.0f, "powerful.ttf");
	m_title->changeTextSize(100);
	m_gui.addLabel(m_title);

	m_play = new Button("Play", 900.0f, 700.0f);
	m_play->changeTextSize(100);
	m_play->gainFocus();
	m_play->Enter = std::bind(&MainMenuScreen::goToLevelSelect, this);
	m_gui.addButton(m_play);

	m_quit = new Button("Quit", 900.0f, 900.0f);
	m_quit->changeTextSize(100);
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

	updateShader += deltaTime.asSeconds()*2;
	shader.setUniform("time", updateShader);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//m_game->changeGameState(GameState::WorldSelect);
	}

	m_gui.update(m_currentSelect, 2);

}

//draws window
void MainMenuScreen::render(sf::RenderWindow & window)
{
	window.draw(shaderSprite, &shader);
	m_gui.draw(window);
}




void MainMenuScreen::quit()
{
	m_game->m_window.close();
}

void MainMenuScreen::goToLevelSelect()
{
	m_game->changeGameState(GameState::WorldSelect);
}