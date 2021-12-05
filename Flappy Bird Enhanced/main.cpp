#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#include "bird.h"
#include "pipe.h"
#include "bullet.h"
#include "obstacle.h"

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

    sf::Texture pipeTextureTop;
    if (!pipeTextureTop.loadFromFile("..\\gameAssets\\TileSet\\pipeTop.png"))
    {
        std::cout << "error loading texture" << std::endl;
        // error...
    }
    sf::Texture pipeTextureBottom;
    if (!pipeTextureBottom.loadFromFile("..\\gameAssets\\TileSet\\pipeBottom.png"))
    {
        std::cout << "error loading texture" << std::endl;
        // error...
    }

    std::list<Pipe> pipes = std::list<Pipe>();
    float timeElapsed = 0.0;
    float timeBetweenPipes = 3.0;
    int totalPipes = 5;
    int numPipes = 0;
    bool isDead = false;
    float birdVelocity = 300.0;

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
                    bird.addVelocity(birdVelocity);
                }
            }
        }

        sf::Time elapsed = clock.restart();
        timeElapsed += elapsed.asSeconds();

        // erase previously drawn stuff
        window.clear();

        if (numPipes < totalPipes)
        {
            timeElapsed += elapsed.asSeconds();
            if (timeElapsed >= timeBetweenPipes)
            {
                pipes.push_back(Pipe(window.getSize(), pipeTextureBottom, pipeTextureTop));
                timeElapsed = 0;
                numPipes++;
            }
        }

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

        // pipe logic
        for (Pipe& pipe : pipes)
        {
            pipe.calculatePosition(elapsed.asSeconds());
            if (pipe.spriteBottom->getPosition().x + 3.0 * pipe.spriteBottom->getLocalBounds().width <= 0.0)
            {
                pipe.resetPosition();
            }

            if (bird.isColliding(pipe.getBounds()))
            {
                isDead = true;
            }
        }

        // draw stuff here
        window.draw(background);
        if (!isDead)
        {
            window.draw(*bird.sprite.get());
        }
        for (Pipe& pipe : pipes)
        {
            window.draw(*pipe.spriteBottom.get());
            window.draw(*pipe.spriteTop.get());
        }

        // display frame
        window.display();
    }

    return 0;
}