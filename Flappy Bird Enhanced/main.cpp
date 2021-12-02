#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Flappy Bird Enhanced");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

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

        // draw stuff here
        window.draw(shape);

        // display frame
        window.display();
    }

    return 0;
}