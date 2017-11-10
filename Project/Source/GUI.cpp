/// <summary>
/// @mainpage 3rd year project - 2D platformer
/// @Author Sean Regan, Jamie Murphy
/// @Version 0.1
/// @brief GUI class to handle all buttons and widgets
/// </summary>

#include "../Header/GUI.h"

GUI::GUI()
{

}

GUI::~GUI()
{
}

void GUI::addWidget(Widget * widget)
{
	m_elements.push_back(widget);
}

void GUI::update(int &index, int numOfItems)
{
	for each (Widget* i in m_elements)
	{
		i->update();	
	}
}

void GUI::draw(sf::RenderWindow & window)
{
	for each (Widget* i in m_elements)
	{
		i->draw(window);
	}
}

void GUI::moveDown(int &index, int numOfItems)
{
	if (index + 1 < numOfItems)
	{
		if (m_elements[index + 1]->isActive == false)
		{
			if (index + 2 < numOfItems)
			{
				m_elements[index]->loseFocus();
				index += 2;
				m_elements[index]->gainFocus();
			}
		}
		else
		{
			m_elements[index]->loseFocus();
			index++;
			m_elements[index]->gainFocus();
		}

	}
}

void GUI::moveUp(int &index)
{
	if (index - 1 >= 0)
	{
		if (m_elements[index - 1]->isActive == false)
		{
			if (index - 2 >= 0)
			{
				m_elements[index]->loseFocus();
				index -= 2;
				m_elements[index]->gainFocus();
			}
		}
		else
		{
			m_elements[index]->loseFocus();
			index--;
			m_elements[index]->gainFocus();
		}
	}
}

void GUI::activate(int &index)
{
	bool linked = false;

	if (m_elements[index]->getID() == "button")
	{
		try
		{
			m_elements[index]->Enter();
		}
		catch (std::bad_function_call)
		{
			std::cout << "Bad Function Call" << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < m_elements.size(); i++)
		{
			// if linked then deactivate
			if(m_elements[index]->checkTag() == m_elements[i]->checkTag() && m_elements[index]->getID() == m_elements[i]->getID())
			{
				m_elements[i]->loseActive();
				linked = true;
			}

			if (m_elements[index]->checkActive() == true && !linked)
			{
				m_elements[index]->loseActive();
			}
			else 
			{
				m_elements[index]->getActive();
				try 
				{
					m_elements[index]->Enter();
				}
				catch (std::bad_function_call)
				{
					std::cout << "Bad Function Call" << std::endl;
				}
			}
		}
	}
}