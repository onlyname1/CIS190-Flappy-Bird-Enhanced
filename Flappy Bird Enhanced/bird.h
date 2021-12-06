#pragma once
#include <SFML/Graphics.hpp>

class Bird
{
public:
	Bird(const sf::Texture& texture, int screenWidth, int screenHeight);

	void addVelocity(float force);

	void calculatePosition(float deltaTime);

	bool isColliding(std::tuple<sf::FloatRect, sf::FloatRect> other);
	bool isColliding(sf::FloatRect other);

	void resetPosition();

	static float GRAVITY;

	std::unique_ptr<sf::Sprite> sprite;
	std::unique_ptr<sf::CircleShape> hitbox;
private:
	float velocity;
	int screenWidth;
	int screenHeight;
};

