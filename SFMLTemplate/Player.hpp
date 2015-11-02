#pragma once

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

class Player {
private:
	sf::Vector2f position;
	sf::Sprite sprite;
	sf::Texture texture;

	float speed;			// Pelaajan nopeus
	int health;				// Elämäpisteet
public:
	Player();

	bool isAlive();
	void takeDamage(int damage);
	int getHealth();

	void update(const sf::Time& time);
	void draw(sf::RenderWindow& renderWindow);

	~Player();
};