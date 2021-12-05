#include "bird.h"

float Bird::GRAVITY = -600.f;

Bird::Bird(const sf::Texture& texture, sf::Vector2u windowSize)
	: sprite(std::make_unique<sf::Sprite>(texture)), velocity(0), windowSize(windowSize)
{
	sprite->setTextureRect(sf::IntRect(0, 0, 16, 16));
	sprite->setScale(sf::Vector2f(3.f, 3.f));
	sprite->setPosition(windowSize.x / 5, windowSize.y / 2);
}

void Bird::addVelocity(float f)
{
	// add to force
	velocity -= f;
}

void Bird::calculatePosition(float deltaTime)
{
	velocity = velocity - GRAVITY * deltaTime;
	if (velocity < -600.f)
	{
		velocity = -600.f;
	}
	if (velocity > 600.f)
	{
		velocity = 600.f;
	}
	sprite->move(0, velocity * deltaTime);
}

bool Bird::isColliding(std::tuple<sf::FloatRect, sf::FloatRect> other)
{
	if (std::get<0>(other).intersects(sprite->getGlobalBounds()))
	{
		return true;
	}
	if (std::get<1>(other).intersects(sprite->getGlobalBounds()))
	{
		return true;
	}
	return false;
}

void Bird::resetPosition()
{
	velocity = 0;
	sprite->setPosition(windowSize.x / 5, windowSize.y / 2);
}