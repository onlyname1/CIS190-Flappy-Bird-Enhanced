#include "bird.h"

float Bird::GRAVITY = -300.f;

Bird::Bird(const sf::Texture& texture)
	: sprite(std::make_unique<sf::Sprite>(texture)), velocity(0)
{
	sprite->setTextureRect(sf::IntRect(0, 0, 16, 16));
	sprite->setScale(sf::Vector2f(3.f, 3.f));
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

bool Bird::isColliding(sf::FloatRect other)
{
	return false;
}