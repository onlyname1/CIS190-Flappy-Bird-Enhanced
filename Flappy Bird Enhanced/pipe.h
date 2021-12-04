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
	void calculatePosition(float time);

	// getBounds
	sf::FloatRect getBounds();
};

