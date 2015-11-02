#pragma once

#include <SFML/Graphics.hpp>

class Enemy {
private:
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;
	int health;
public:
	Enemy(std::string& textureName);

	bool isAlive();
	void takeDamage(int damage);
	int getHealth();

	sf::Vector2f& getPosition();

	bool collidesWith(sf::FloatRect& other);
	sf::FloatRect getBounds();

	~Enemy();
};