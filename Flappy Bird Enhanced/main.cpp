#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#include "bird.h"
#include "pipe.h"
#include "bullet.h"
#include "obstacle.h"
#include "basicObstacle.h"
#include "movingObstacle.h"
#include "bigObstacle.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 512), "Floaty Bird");
    window.setKeyRepeatEnabled(false);

    sf::Clock clock;

    std::list<Pipe> pipes = std::list<Pipe>();
    std::list<std::unique_ptr<Obstacle>> obstacles = std::list<std::unique_ptr<Obstacle>>();
    float timeElapsed = 0.0;
    float timeBetweenPipes = 5.0;
    float timeElapsedObstacle = 0.0;
    float timeBetweenObstacles = 5.0;
    int totalPipes = 3;
    int numPipes = 0;
    int totalObstacles = 5;
    int numObstacles = 0;
    bool isDead = false;
    float birdVelocity = 300.0;
    bool isPlay = false;
    int score = 0;
    int screenWidth = 1024;
    int screenHeight = 512;

    sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(screenWidth * 0.9, screenHeight * 0.9));
    rect.setFillColor(sf::Color(100, 0, 0));
    rect.setOrigin(rect.getLocalBounds().width / 2, rect.getLocalBounds().height / 2);
    rect.setPosition(screenWidth / 2, screenHeight / 2);

    // setup font
    sf::Font font;
    if (!font.loadFromFile("..\\gameAssets\\Fonts\\kenneyBlocks.ttf"))
    {
        std::cout << "error loading font" << std::endl;
    }

    sf::Text mainMenu;
    mainMenu.setFont(font);
    mainMenu.setString("FLOATY BIRD");
    mainMenu.setCharacterSize(100);
    mainMenu.setFillColor(sf::Color::White);
    mainMenu.setOrigin(mainMenu.getLocalBounds().width / 2, mainMenu.getLocalBounds().height / 2);
    mainMenu.setPosition(screenWidth / 2, screenHeight / 4);

    sf::Text playText;
    playText.setFont(font);
    playText.setString("Press P to start");
    playText.setCharacterSize(50);
    playText.setFillColor(sf::Color::White);
    playText.setOrigin(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 2);
    playText.setPosition(screenWidth / 2, screenHeight / 2);

    sf::Text gameOver;
    gameOver.setFont(font);
    gameOver.setString("GAME OVER");
    gameOver.setCharacterSize(100);
    gameOver.setFillColor(sf::Color::White);
    gameOver.setOrigin(gameOver.getLocalBounds().width / 2, gameOver.getLocalBounds().height / 2);
    gameOver.setPosition(screenWidth / 2, screenHeight / 4);

    sf::Text restartText;
    restartText.setFont(font);
    restartText.setString("Press R to restart");
    restartText.setCharacterSize(50);
    restartText.setFillColor(sf::Color::White);
    restartText.setOrigin(restartText.getLocalBounds().width / 2, restartText.getLocalBounds().height / 2);
    restartText.setPosition(screenWidth / 2, 3 * screenHeight / 4);

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString(std::to_string(score));
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);
    scoreText.setPosition(screenWidth / 2, screenHeight / 10);

    sf::Text endScoreText;
    endScoreText.setFont(font);
    endScoreText.setString("Score: " + std::to_string(score));
    endScoreText.setCharacterSize(50);
    endScoreText.setFillColor(sf::Color::White);
    endScoreText.setOrigin(endScoreText.getLocalBounds().width / 2, endScoreText.getLocalBounds().height / 2);
    endScoreText.setPosition(screenWidth / 2, screenHeight / 2);

    // make background
    sf::Texture texture;
    if (!texture.loadFromFile("..\\gameAssets\\Background\\Background5.png"))
    {
        std::cout << "error loading texture" << std::endl;
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
    }
    Bird bird = Bird(birdTexture, screenWidth, screenHeight);

    // setup pipe textures
    sf::Texture pipeTextureTop;
    if (!pipeTextureTop.loadFromFile("..\\gameAssets\\TileSet\\pipeTop.png"))
    {
        std::cout << "error loading texture" << std::endl;
    }
    sf::Texture pipeTextureBottom;
    if (!pipeTextureBottom.loadFromFile("..\\gameAssets\\TileSet\\pipeBottom.png"))
    {
        std::cout << "error loading texture" << std::endl;
    }
    
    // setup obstacle textures
    sf::Texture basicObstacleTexture;
    if (!basicObstacleTexture.loadFromFile("..\\gameAssets\\Obstacles\\basicObstacle.png"))
    {
        std::cout << "error loading texture" << std::endl;
    }
    sf::Texture movingObstacleTexture;
    if (!movingObstacleTexture.loadFromFile("..\\gameAssets\\Obstacles\\movingObstacle.png"))
    {
        std::cout << "error loading texture" << std::endl;
    }
    sf::Texture toughObstacleTexture;
    if (!toughObstacleTexture.loadFromFile("..\\gameAssets\\Obstacles\\toughObstacle.png"))
    {
        std::cout << "error loading texture" << std::endl;
    }

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
                if (event.key.code == sf::Keyboard::R)
                {
                    if (isDead)
                    {
                        timeElapsed = 0.0;
                        timeElapsedObstacle = 0.0;
                        numPipes = 0;
                        numObstacles = 0;
                        isDead = false;
                        birdVelocity = 300.0;
                        score = 0;
                        pipes.clear();
                        obstacles.clear();
                        bird.resetPosition();
                    }
                }
                if (event.key.code == sf::Keyboard::P)
                {
                    if (!isPlay)
                    {
                        isPlay = true;
                        bird.resetPosition();
                    }
                }
            }
        }

        sf::Time elapsed = clock.restart();

        // erase previously drawn stuff
        window.clear();
        if (isPlay)
        {
            if (numPipes < totalPipes)
            {
                timeElapsed += elapsed.asSeconds();
                if (timeElapsed >= timeBetweenPipes)
                {
                    pipes.push_back(Pipe(screenWidth, screenHeight, pipeTextureBottom, pipeTextureTop));
                    timeElapsed = 0;
                    numPipes++;
                }
            }

            if (numObstacles < totalObstacles)
            {
                timeElapsedObstacle += elapsed.asSeconds();
                if (timeElapsedObstacle >= timeBetweenObstacles)
                {
                    switch (numObstacles % 3)
                    {
                    case 0:
                        obstacles.push_back(std::make_unique<BasicObstacle>(basicObstacleTexture, screenWidth, screenHeight));
                        break;
                    case 1:
                        obstacles.push_back(std::make_unique<MovingObstacle>(movingObstacleTexture, screenWidth, screenHeight));
                        break;
                    case 2:
                        obstacles.push_back(std::make_unique<BigObstacle>(toughObstacleTexture, screenWidth, screenHeight));
                        break;
                    }
                    timeElapsedObstacle = 0;
                    numObstacles++;
                }
            }
        }

        // bird logic
        bird.calculatePosition(elapsed.asSeconds());
        if (bird.sprite->getPosition().y >= screenHeight)
        {
            bird.sprite->setPosition(sf::Vector2f(bird.sprite->getPosition().x, -bird.sprite->getGlobalBounds().height));
            bird.hitbox->setPosition(bird.sprite->getGlobalBounds().left + bird.sprite->getGlobalBounds().width / 2,
                bird.sprite->getGlobalBounds().top + bird.sprite->getGlobalBounds().height / 2);
        }
        else if (bird.sprite->getPosition().y + bird.sprite->getGlobalBounds().height < 0)
        {
            bird.sprite->setPosition(sf::Vector2f(bird.sprite->getPosition().x, screenHeight));
            bird.hitbox->setPosition(bird.sprite->getGlobalBounds().left + bird.sprite->getGlobalBounds().width / 2,
                bird.sprite->getGlobalBounds().top + bird.sprite->getGlobalBounds().height / 2);
        }

        // pipe logic
        for (Pipe& pipe : pipes)
        {
            pipe.calculatePosition(elapsed.asSeconds());
            if (pipe.spriteBottom->getPosition().x + pipe.spriteBottom->getGlobalBounds().width <= 0.0)
            {
                pipe.resetPosition();
            }

            if (pipe.spriteBottom->getPosition().x + pipe.spriteBottom->getGlobalBounds().width <= bird.sprite->getPosition().x &&
                !pipe.passed)
            {
                pipe.passed = true;
                score++;
            }

            if (bird.isColliding(pipe.getBounds()) && !isDead)
            {
                isDead = true;
                endScoreText.setString("Score: " + std::to_string(score));
            }
        }

        // obstacle logic
        for (std::unique_ptr<Obstacle>& obstacle : obstacles)
        {
            obstacle->calculatePosition(elapsed.asSeconds());
            if (obstacle->sprite->getPosition().x + obstacle->sprite->getGlobalBounds().width <= 0.0)
            {
                obstacle->resetPosition();
            }

            if (bird.isColliding(obstacle->getBounds()))
            {
                score+= obstacle->score;
                obstacle->resetPosition();
            }
        }

        scoreText.setString(std::to_string(score));

        // draw stuff here
        window.draw(background);
        for (Pipe& pipe : pipes)
        {
            window.draw(*pipe.spriteBottom.get());
            window.draw(*pipe.spriteTop.get());
        }
        for (std::unique_ptr<Obstacle>& obstacle : obstacles)
        {
            window.draw(*obstacle->sprite.get());
        }
        if (!isDead && isPlay)
        {
            window.draw(*bird.sprite.get());
            window.draw(scoreText);
        }
        if (isDead)
        {
            window.draw(rect);
            window.draw(gameOver);
            window.draw(restartText);
            window.draw(endScoreText);
        }
        if (!isPlay)
        {
            window.draw(mainMenu);
            window.draw(playText);
        }

        // display frame
        window.display();
    }

    return 0;
}