#include "movingObstacle.h"

MovingObstacle::MovingObstacle(const sf::Texture& texture, int screenWidth, int screenHeight)
	: Obstacle(texture, screenWidth, screenHeight), yVelocity(std::rand() % 50 + 50)
{
	setup();
}

void MovingObstacle::calculatePosition(float deltaTime)
{
	float posY = sprite->getPosition().y + sprite->getGlobalBounds().height / 2.0;
	if (posY <= (0.20 * screenHeight) || posY >= (0.8 * screenHeight))
	{
		yVelocity *= -1;
	}

	sprite->move(velocity * deltaTime, yVelocity * deltaTime);
}

void MovingObstacle::setup()
{
	sprite->setScale(sf::Vector2f(2.5f, 2.5f));
	score = 3;
}
