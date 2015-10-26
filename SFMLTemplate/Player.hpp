#pragma once

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

class Player {
private:
	sf::Vector2f position;

	int health;
public:
	Player();

	void update(const sf::Time& time);
	void draw(sf::RenderWindow& renderWindow);

	~Player();
};