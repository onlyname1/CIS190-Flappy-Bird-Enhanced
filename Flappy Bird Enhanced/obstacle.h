#pragma once
#include <SFML/Graphics.hpp>

class Obstacle
{
public:
	Obstacle(const sf::Texture& texture, int screenWidth, int screenHeight);

	virtual void calculatePosition(float deltaTime) = 0;

	virtual void setup() = 0;

	void resetPosition();

	sf::FloatRect getBounds();

	std::unique_ptr<sf::Sprite> sprite;

	int score;
protected:
	float velocity;
	int screenWidth;
	int screenHeight;
};

