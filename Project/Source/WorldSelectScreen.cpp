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

	
	m_title = new Label("WORLD SELECT ", 100.0f, 100.0f, "powerful.ttf");
	m_gui.addLabel(m_title);

	m_worldOne = new Button("(World) (One)", 700.0f, 400.0f, "Batman.ttf");
	m_worldOne->gainFocus();
	m_worldOne->Enter = std::bind(&WorldSelectScreen::goToGameScreen, this);
	m_gui.addButton(m_worldOne);

	m_worldTwo = new Button("(World) (Two)", 700.0f, 500.0f, "Batman.ttf");
	m_worldTwo->Enter = std::bind(&WorldSelectScreen::goToGameScreen, this);
	m_gui.addButton(m_worldTwo);

	m_worldThree = new Button("(World) (Three)", 700.0f, 600.0f, "Batman.ttf");
	m_worldThree->Enter = std::bind(&WorldSelectScreen::goToGameScreen, this);
	m_gui.addButton(m_worldThree);


	m_back = new Button("(Back)", 700.0f, 700.0f, "Batman.ttf");
	m_back->Enter = std::bind(&WorldSelectScreen::goToMainMenu, this);
	m_gui.addButton(m_back);

	keys = KeyHandler();
}

//destructor
WorldSelectScreen::~WorldSelectScreen()
{
}

//updates screen
void WorldSelectScreen::update(sf::Time deltaTime)
{
	m_gui.update(m_currentSelect, 4);
}

//draws window
void WorldSelectScreen::render(sf::RenderWindow & window)
{
	for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++)
	{
		window.draw(text[i]);
	}

	m_gui.draw(window);
}



//sets gamestate
void WorldSelectScreen::setStateBack()
{
	//m_game->changeGameState(GameState::TheMenu);
}


void WorldSelectScreen::goToGameScreen()
{
	m_game->changeGameState(GameState::Gameplay);
}

void WorldSelectScreen::goToMainMenu()
{
	m_game->changeGameState(GameState::MainMenu);
}