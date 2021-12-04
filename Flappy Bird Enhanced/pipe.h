#pragma once
#include <SFML/Graphics.hpp>
class pipe
{
private:
	std::unique_ptr<sf::Sprite> spr;

public:
	// constructor
	pipe(sf::Sprite sprite) 
		: spr(std::make_unique<sf::Sprite>(sprite)) {}

	// moving 
	void move(sf::Vector2f);

	// getBounds
	sf::FloatRect getBounds();
};

