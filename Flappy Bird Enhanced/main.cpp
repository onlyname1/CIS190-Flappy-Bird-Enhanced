#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 512), "Flappy Bird Enhanced");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
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
    
    sprite.setScale(sf::Vector2f(2.f, 2.f));


    while (window.isOpen())
    {
        // check for events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // erase previously drawn stuff
        window.clear();

        shape.move(0, 0.1f);
        if (shape.getPosition().y >= window.getSize().y)
        {
            shape.setPosition(sf::Vector2f(shape.getPosition().x, 0));
        }
        else if (shape.getPosition().y < 0)
        {
            shape.setPosition(sf::Vector2f(shape.getPosition().x, window.getSize().y));
        }
        // draw stuff here
        window.draw(sprite);
        window.draw(shape);

        // display frame
        window.display();
    }

    return 0;
}

void updateGame()
{

}