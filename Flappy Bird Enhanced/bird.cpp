#include "bird.h"

float Bird::GRAVITY = -600.f;

Bird::Bird(const sf::Texture& texture, int screenWidth, int screenHeight)
	: sprite(std::make_unique<sf::Sprite>(texture)), hitbox(std::make_unique<sf::CircleShape>(4.0)),
	  velocity(0), screenWidth(screenWidth), screenHeight(screenHeight)
{
	sprite->setTextureRect(sf::IntRect(0, 0, 16, 16));
	sprite->setScale(sf::Vector2f(3.f, 3.f));
	hitbox->setScale(sf::Vector2f(2.f, 2.f));
	hitbox->setOrigin(hitbox->getLocalBounds().width / 2, hitbox->getLocalBounds().height / 2);
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
	hitbox->move(0, velocity * deltaTime);
}

bool Bird::isColliding(std::tuple<sf::FloatRect, sf::FloatRect> other)
{
	if (std::get<0>(other).intersects(hitbox->getGlobalBounds()))
	{
		return true;
	}
	if (std::get<1>(other).intersects(hitbox->getGlobalBounds()))
	{
		return true;
	}
	return false;
}

bool Bird::isColliding(sf::FloatRect other)
{
	return other.intersects(hitbox->getGlobalBounds());
}

void Bird::resetPosition()
{
	velocity = 0;
	sprite->setPosition(screenWidth / 5, screenHeight / 2);
	hitbox->setPosition(sprite->getGlobalBounds().left + sprite->getGlobalBounds().width / 2, 
		sprite->getGlobalBounds().top + sprite->getGlobalBounds().height / 2);
}