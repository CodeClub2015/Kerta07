#pragma once

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <vector>

class Projectile {
public:
	sf::Vector2f position;
	sf::Sprite sprite;
	Projectile() {}
	~Projectile() {}
};

class Player {
private:
	std::vector<Projectile> projectiles;
	sf::Texture bulletTexture;
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
	sf::FloatRect getBounds();

	void update(const sf::Time& time);
	void draw(sf::RenderWindow& renderWindow);

	~Player();
};