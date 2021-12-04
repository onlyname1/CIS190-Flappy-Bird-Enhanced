#include "pipe.h"


Pipe::Pipe(sf::Vector2u screenSize, const sf::Texture& texture)
	: screenSize(screenSize), xVelocity(-100.0), yVelocity(50.0), sprite(std::make_unique<sf::Sprite>(texture)) // change velocity!!!!
{
	sprite->setScale(sf::Vector2f(3.f, 3.f));
	sprite->setPosition(screenSize.x / 2, screenSize.y / 2);
}

void Pipe::calculatePosition(float time)
{
	if (sprite->getPosition().y <= (0.25 * screenSize.y) || sprite->getPosition().y >= (0.75 * screenSize.y)) // if it's moving upwards or downwards past threshold, change directions
	{
		yVelocity *= -1;
	}

	sprite->move(xVelocity * time, yVelocity * time);
}

sf::FloatRect Pipe::getBounds()
{
	return sprite->getGlobalBounds();
}