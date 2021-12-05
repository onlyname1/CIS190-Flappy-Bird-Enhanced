#pragma once
#include <SFML/Graphics.hpp>

class Bird
{
public:
	Bird(const sf::Texture& texture);

	void addVelocity(float force);

	void calculatePosition(float deltaTime);

	bool isColliding(std::tuple<sf::FloatRect, sf::FloatRect> other);

	static float GRAVITY;

	std::unique_ptr<sf::Sprite> sprite;
private:
	float velocity;
};

