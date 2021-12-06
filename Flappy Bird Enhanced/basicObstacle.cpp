#include "basicObstacle.h"

BasicObstacle::BasicObstacle(const sf::Texture& texture, int screenWidth, int screenHeight)
	: Obstacle(texture, screenWidth, screenHeight)
{
	setup();
}

void BasicObstacle::calculatePosition(float deltaTime)
{
	sprite->move(velocity * deltaTime, 0);
}

void BasicObstacle::setup()
{
	sprite->setScale(sf::Vector2f(3.f, 3.f));
}
