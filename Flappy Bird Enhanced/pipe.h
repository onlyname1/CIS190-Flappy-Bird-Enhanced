#pragma once
#include <SFML/Graphics.hpp>
class Pipe
{
private:
	float xVelocity;
	float yVelocity;
	sf::Vector2f screenSize;

public:
	std::unique_ptr<sf::Sprite> sprite;

	// constructor
	Pipe(sf::Vector2u screenSize, const sf::Texture& texture);

	// moving 
	void calculatePosition(float time);

	// getBounds
	sf::FloatRect getBounds();
};

