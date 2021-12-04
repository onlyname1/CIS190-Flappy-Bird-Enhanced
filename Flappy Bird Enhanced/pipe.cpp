#include "pipe.h"

Pipe::Pipe(const sf::Texture& texture)
	: sprite(std::make_unique<sf::Sprite>(texture))
{}

void Pipe::calculatePosition(float time)
{

}

sf::FloatRect Pipe::getBounds()
{
	
}