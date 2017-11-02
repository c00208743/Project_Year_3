#pragma once

/// <summary>
/// @Player Class handling player acts and rendering 
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Player for the user to play as
/// </summary>

#include "Game.h"

class Player
{
public:
	Player();
	~Player();
	void update();
	void render(sf::RenderWindow & window);
	void applyForce(sf::Vector2f force);

	void checkCollision(sf::Vector2f size, sf::Vector2f pos);

private:
	float m_mass;
	float m_speed;
	sf::Vector2f m_size;
	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
	sf::Vector2f m_accel;
	sf::Vector2f m_gravity;
	sf::RectangleShape m_rect;
	bool fall;


};