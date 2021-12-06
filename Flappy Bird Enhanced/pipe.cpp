#include "pipe.h"


Pipe::Pipe(int screenWidth, int screenHeight, const sf::Texture& textureBottom, const sf::Texture& textureTop)
	: screenWidth(screenWidth), screenHeight(screenHeight), xVelocity(-150.0), yVelocity(50.0), 
	  spriteBottom(std::make_unique<sf::Sprite>(textureBottom)), spriteTop(std::make_unique<sf::Sprite>(textureTop)),
	  passed(false)
{
	spriteBottom->setScale(sf::Vector2f(3.f, 3.f));
	spriteTop->setScale(sf::Vector2f(3.f, 3.f));
	resetPosition();
}

void Pipe::calculatePosition(float time)
{

	float topBound = spriteTop->getGlobalBounds().top + spriteTop->getGlobalBounds().height;
	float bottomBound = spriteBottom->getGlobalBounds().top;
	if (topBound <= (0.1 * screenHeight) || bottomBound >= (0.9 * screenHeight)) // if it's moving upwards or downwards past threshold, change directions
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
	int displacement = std::rand() % ((int)screenHeight / 3) - ((int)screenHeight / 6);
	spriteTop->setPosition(screenWidth, -(float)screenHeight + displacement);
	spriteBottom->setPosition(screenWidth, screenHeight * 3 / 4 + displacement);
	passed = false;
}