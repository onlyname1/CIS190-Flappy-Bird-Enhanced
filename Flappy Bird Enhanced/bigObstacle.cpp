#include "bigObstacle.h"

BigObstacle::BigObstacle(const sf::Texture& texture, int screenWidth, int screenHeight)
	: Obstacle(texture, screenWidth, screenHeight)
{
	setup();
}

void BigObstacle::calculatePosition(float deltaTime)
{
	sprite->move(velocity * 0.75 * deltaTime, 0);
}

void BigObstacle::setup()
{
	sprite->setScale(sf::Vector2f(4.f, 4.f));
	score = 5;
}
