#include "Player.hpp"

Player::Player() 
	: speed(0.5f),
      health(100),
      position(0.0f, 0.0f) {
	

	sprite.setColor(sf::Color::White);
	texture.loadFromFile("Content\\alus.png");
	sprite.setTexture(texture);

	bulletTexture.loadFromFile("Content\\projectile.png");
}

sf::FloatRect Player::getBounds() {
	return sprite.getGlobalBounds();
}

bool Player::isAlive() {
	bool alive = health > 0;
	return alive;
}
void Player::takeDamage(int damage) {
	health -= damage;
}
int Player::getHealth() {
	return health;
}

void Player::update(const sf::Time& time) {
	// Katotaan onko D pohjassa.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		position.x += speed;
	} // A
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		position.x -= speed;
	} // W
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		position.y -= speed;
	} // S
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		position.y += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		projectiles.push_back(Projectile());
		Projectile& bullet = projectiles.back();
		bullet.sprite.setTexture(bulletTexture);

		sf::FloatRect size = sprite.getGlobalBounds();
		sf::Vector2f newpos(position.x + size.width,
			position.y + size.height / 2.f);

		bullet.position = newpos;
	}

	for (int i = 0; i < projectiles.size(); ++i) {
		projectiles[i].position.x += 0.5f;
		projectiles[i].sprite.setPosition(
			projectiles[i].position);
	}

	sprite.setPosition(position);
}
void Player::draw(sf::RenderWindow& renderWindow) {
	renderWindow.draw(sprite);
	for (int i = 0; i < projectiles.size(); ++i) {
		renderWindow.draw(projectiles[i].sprite);
	}
}

Player::~Player() {
	
}