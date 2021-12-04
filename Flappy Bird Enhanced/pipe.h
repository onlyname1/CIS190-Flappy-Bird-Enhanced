#pragma once
#include <SFML/Graphics.hpp>
class Pipe
{
private:
	

public:
	std::unique_ptr<sf::Sprite> sprite;

	// constructor
	Pipe(const sf::Texture& texture);

	// moving 
	void calculatePosition(sf::Vector2f);

	// getBounds
	sf::FloatRect getBounds();
};

