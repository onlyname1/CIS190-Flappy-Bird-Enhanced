#include "pipe.h"


Pipe::Pipe(sf::Vector2u screenSize, const sf::Texture& textureBottom, const sf::Texture& textureTop)
	: screenSize(screenSize), xVelocity(-150.0), yVelocity(50.0), spriteBottom(std::make_unique<sf::Sprite>(textureBottom)), spriteTop(std::make_unique<sf::Sprite>(textureTop))
{
	spriteBottom->setScale(sf::Vector2f(3.f, 3.f));
	spriteTop->setScale(sf::Vector2f(3.f, 3.f));
	spriteBottom->setPosition(screenSize.x, screenSize.y / 4);
	spriteTop->setPosition(screenSize.x, screenSize.y * 3 / 4);
}

void Pipe::calculatePosition(float time)
{
	if (spriteBottom->getPosition().y <= (0.25 * screenSize.y) || spriteBottom->getPosition().y >= (0.75 * screenSize.y)) // if it's moving upwards or downwards past threshold, change directions
	{
		yVelocity *= -1;
	}

	spriteTop->move(xVelocity * time, yVelocity * time);
	spriteBottom->move(xVelocity * time, yVelocity * time);
}

std::tuple<sf::FloatRect, sf::FloatRect> Pipe::getBounds()
{
	return std::tuple<sf::FloatRect, sf::FloatRect>(spriteTop->getGlobalBounds(), spriteBottom->getGlobalBounds());
}

void Pipe::resetPosition()
{
	spriteTop->setPosition(screenSize.x, screenSize.y * 3 / 4);
	spriteBottom->setPosition(screenSize.x, screenSize.y / 4);
}