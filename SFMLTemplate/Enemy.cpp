#include "Enemy.hpp"

Enemy::Enemy(std::string& textureName) {
}

bool Enemy::isAlive() {
	return false;
}
void Enemy::takeDamage(int damage) {
}
int Enemy::getHealth()  {
	return 0;
}

sf::Vector2f& Enemy::getPosition() {
	return sf::Vector2f();
}

bool Enemy::collidesWith(sf::FloatRect& other) {
	return false;
}
sf::FloatRect Enemy::getBounds() {
	return sf::FloatRect();
}

void Enemy::update(const sf::Time& time) {
}
void Enemy::draw(sf::RenderWindow& renderWindow) {
}

Enemy::~Enemy() {
}