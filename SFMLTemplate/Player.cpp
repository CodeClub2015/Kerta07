#include "Player.hpp"

Player::Player(sf::Texture* texture) 
	: texture(texture),
   sprite(*texture),
   speed(0.5f),
   health(100),
   position(0.0f, 0.0f) {
	sprite.setColor(sf::Color::White);
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

	sprite.setPosition(position);
}
void Player::draw(sf::RenderWindow& renderWindow) {
	renderWindow.draw(sprite);
}

Player::~Player() {
	delete texture;
}