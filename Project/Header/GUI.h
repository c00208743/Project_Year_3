#pragma once

/// <summary>
/// @mainpage 3rd year project - 2D platformer
/// @Author Sean Regan, Jamie Murphy
/// @Version 0.1
/// @brief GUI class to handle all buttons and widgets
/// </summary>
 
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Widget.h"

class GUI
{
public:
	GUI();
	~GUI();
	void update(int &index, int numOfItems);	// Update loop
	void draw(sf::RenderWindow &window);		// Draw loop
	void moveDown(int &index, int numOfItems);	// Move down to the next GUI object
	void moveUp(int &index);					// Move up to the previous GUI object
	void activate(int &index);					// Activate current GUI objects function
	void addWidget(Widget *widget);				// Add a widget

protected:
	std::vector<Widget *> m_elements;			// Container to hold widgets
};