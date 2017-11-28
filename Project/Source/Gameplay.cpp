#include "../Header/Gameplay.h"
#include "../Header/Platform.h"
#include "../Header/Player.h"
#include "../Header/LevelLoader.h"


/// <summary>
/// @Gameplay screen to be played before the Main Menu screen 
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Gameplay
/// </summary>


//constructs the splash screen
GameplayScreen::GameplayScreen(Game & game) : m_game(&game)
{
	//loading yaml file
	int currentLevel = 1;
	if (!LevelLoader::load(currentLevel, m_level))
	{
		return;
	}
	m_currentSelect = 0;

	// Load from a font file on disk
	if (!myFont.loadFromFile("Fonts/powerful.ttf"))
	{
		// Error...
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


	

	m_cumulativeTime = sf::Time::Zero;
	
	GeneratePlatform();
	m_ground = make_unique<Platform>(0.0f, 1350.0f, 400.0f, 90.0f);
	m_player = make_unique<Player>();

	view.setCenter(1280, 720); // set player's position to camera
	view.setSize(sf::Vector2f(2560, 1440)); // set camera's size
	
}

//destructor
GameplayScreen::~GameplayScreen()
{
}

//updates screen
void GameplayScreen::update(sf::Time deltaTime)
{
	m_cumulativeTime += deltaTime;

	updateShader += deltaTime.asSeconds() * 2;
	shader.setUniform("time", updateShader);

	
	m_ground->update();
	m_player->checkCollision(m_ground->getSize(), m_ground->getPos());
	for (int i = 0; i < m_platform.size(); i++)
	{
		m_platform[i].update();
		m_player->checkCollision(m_platform[i].getSize(), m_platform[i].getPos());
	}
	
	 
	view.setCenter(posV++, view.getCenter().y);

	m_player->update();

}

void GameplayScreen::GeneratePlatform()
{
	for (int i = 0; i < m_level.m_platform.size(); i++)
	{
		float x = m_level.m_platform[i].m_position.x;
		float y = m_level.m_platform[i].m_position.y;
		float w = m_level.m_platform[i].m_size.x;
		float h = m_level.m_platform[i].m_size.y;
		Platform temp = Platform(x, y, w, h);
		m_platform.push_back(temp);
	}

}

//draws window
void GameplayScreen::render(sf::RenderWindow & window)
{
	window.draw(shaderSprite, &shader);

	m_ground->render(window);
	for (int i = 0; i < m_platform.size(); i++)
	{
		m_platform[i].render(window);
	}
	m_player->render(window);
	window.setView(view);

}
