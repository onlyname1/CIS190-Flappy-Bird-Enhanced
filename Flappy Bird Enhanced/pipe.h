#pragma once
#include <SFML/Graphics.hpp>
class Pipe
{
private:
	float xVelocity;
	float yVelocity;
	sf::Vector2f screenSize;

public:
	std::unique_ptr<sf::Sprite> spriteBottom;
	std::unique_ptr<sf::Sprite> spriteTop;

	// constructor
	Pipe(sf::Vector2u screenSize, const sf::Texture& textureBottom, const sf::Texture& textureTop);

	// moving 
	void calculatePosition(float time);

	void resetPosition();

	// getBounds
	std::tuple<sf::FloatRect, sf::FloatRect> getBounds();
};

