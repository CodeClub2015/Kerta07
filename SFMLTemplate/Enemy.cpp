#include "Enemy.hpp"

Enemy::Enemy(std::string& textureName) {
	texture.loadFromFile(textureName);
	sprite.setTexture(texture);
	health = 100;
	//sprite.setScale(0.5f, 0.5f);
}

bool Enemy::isAlive() {
	return health > 0;
}
void Enemy::takeDamage(int damage) {
	health -= damage;
}
int Enemy::getHealth()  {
	return health;
}

sf::Vector2f& Enemy::getPosition() {
	return position;
}

bool Enemy::collidesWith(sf::FloatRect& other) {
	return getBounds().intersects(other);
}
sf::FloatRect Enemy::getBounds() {
	return sprite.getGlobalBounds();
}

void Enemy::update(const sf::Time& time) {
	position.x -= 0.01f;
	sprite.setPosition(position);

}
void Enemy::draw(sf::RenderWindow& renderWindow) {
	renderWindow.draw(sprite);
}

Enemy::~Enemy() {
}