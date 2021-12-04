#include <SFML/Graphics.hpp>
#include <iostream>

#include "bird.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 512), "Flappy Bird Enhanced");
    window.setKeyRepeatEnabled(false);

    sf::Clock clock;

    // make background
    sf::Texture texture;
    if (!texture.loadFromFile("..\\gameAssets\\Background\\Background5.png"))
    {
        std::cout << "error loading texture" << std::endl;
        // error...
    }
    texture.setRepeated(true);
    sf::Sprite background(texture);
    background.setTextureRect(sf::IntRect(0, 0, 1024, 512));
    background.setScale(sf::Vector2f(2.f, 2.f));

    // make bird
    sf::Texture birdTexture;
    if (!birdTexture.loadFromFile("..\\gameAssets\\Player\\bird1.png"))
    {
        std::cout << "error loading texture" << std::endl;
        // error...
    }
    Bird bird = Bird(birdTexture);
    bird.sprite->setPosition(window.getSize().x / 5, window.getSize().y / 2);

    while (window.isOpen())
    {
        // check for events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    bird.addVelocity(350);
                }
            }
        }

        sf::Time elapsed = clock.restart();

        // erase previously drawn stuff
        window.clear();

        // bird logic
        bird.calculatePosition(elapsed.asSeconds());
        if (bird.sprite->getPosition().y >= window.getSize().y)
        {
            bird.sprite->setPosition(sf::Vector2f(bird.sprite->getPosition().x, -2 * bird.sprite->getLocalBounds().height));
        }
        else if (bird.sprite->getPosition().y + 2 * bird.sprite->getLocalBounds().height < 0)
        {
            bird.sprite->setPosition(sf::Vector2f(bird.sprite->getPosition().x, window.getSize().y));
        }

        // draw stuff here
        window.draw(background);
        window.draw(*bird.sprite.get());

        // display frame
        window.display();
    }

    return 0;
}

void createPipe()
{
    sf::Texture texture;
    if (!texture.loadFromFile("..\\gameAssets\\Background\\Background5.png"))
    {
        std::cout << "error loading texture" << std::endl;
        // error...
    }
    texture.setRepeated(true);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 1024, 512));
}