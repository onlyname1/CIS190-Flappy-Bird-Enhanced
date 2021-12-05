#pragma once
#include <SFML/Graphics.hpp>

class Bird
{
public:
	Bird(const sf::Texture& texture, sf::Vector2u windowSize);

	void addVelocity(float force);

	void calculatePosition(float deltaTime);

	bool isColliding(std::tuple<sf::FloatRect, sf::FloatRect> other);

	void resetPosition();

	static float GRAVITY;

	std::unique_ptr<sf::Sprite> sprite;
private:
	float velocity;

	sf::Vector2u windowSize;
};

