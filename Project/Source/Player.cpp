#include "../Header/Player.h"

Player::Player()
{
	m_mass = 20.0f;
	m_speed = 10.0f;
	m_size = sf::Vector2f(50, 50);
	m_pos = sf::Vector2f(50, 1200);
	m_velocity = sf::Vector2f(0, 0);
	m_accel = sf::Vector2f(0, 0);
	m_rect = sf::RectangleShape(m_size);
	m_rect.setPosition(m_pos);
	m_rect.setFillColor(sf::Color::Green);
	m_gravity = sf::Vector2f(0, 0.1f * m_mass);
	fall = true;
}

Player::~Player()
{

}


void Player::render(sf::RenderWindow & window)
{
	window.draw(m_rect);
}

void Player::applyForce(sf::Vector2f force)
{
	sf::Vector2f f = force / m_mass;
	m_accel += f;
}

void Player::update()
{	
	if (fall)
	{
		applyForce(m_gravity);
	}
	else
	{
		m_velocity = sf::Vector2f(m_velocity.x, 0.0f);
	}

	m_velocity += m_accel;
	m_pos += m_velocity;
	m_accel = sf::Vector2f(0.0f, 0.0f);

	m_rect.setPosition(m_pos);
}

void Player::checkCollision(sf::Vector2f size, sf::Vector2f pos)
{

	float w = 0.5 * (m_size.x + size.x);
	float h = 0.5 * (m_size.y + size.y);
	float dx = (m_pos.x + (m_size.x / 2)) - (pos.x + (size.x / 2));
	float dy = (m_pos.y + (m_size.y / 2)) - (pos.y + (size.y / 2));

	if (abs(dx) <= w && abs(dy) <= h)
	{
		/* collision! */
		float wy = w * dy;
		float hx = h * dx;

		if (wy > hx)
		{
			if (wy > -hx)
			{
				// Top 
				std::cout << "Colliding" << std::endl;
				fall = false;
				m_pos.y -= 10.0f;
			}
			else
			{
				// Left
				fall = false;
			}
		}
		else
		{
			if (wy > -hx)
			{
				// Right
				fall = false;
			}
			else
			{
				// Bottom
				std::cout << "Colliding" << std::endl;
				fall = false;
				m_pos.y -= 1.0f;
			}
		}
	}

	std::cout << fall << std::endl;
	/*if ((abs(m_pos.x - pos.x) * 2 < (m_size.x + size.x)) &&
		(abs(m_pos.y - pos.y) * 2 < (m_size.y + size.y)))
	{
		std::cout << "Collision" << std::endl;
		fall = false;
	}*/
}