#include "obstacle.h"

Obstacle::Obstacle(const sf::Texture& texture, int screenWidth, int screenHeight)
	: sprite(std::make_unique<sf::Sprite>(texture)), score(1), velocity(-(std::rand() % 50 + 50)),
	  screenWidth(screenWidth), screenHeight(screenHeight)
{
	sprite->setTextureRect(sf::IntRect(0, 0, 16, 16));
	resetPosition();
}

void Obstacle::resetPosition()
{
	int displacement = std::rand() % ((int)screenHeight / 2) - ((int)screenHeight / 4);
	sprite->setPosition(screenWidth * 1.25, screenHeight / 2 + displacement);
}

sf::FloatRect Obstacle::getBounds()
{
	return sprite->getGlobalBounds();
}