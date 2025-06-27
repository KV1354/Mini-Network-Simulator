#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Circle Example");

    float radius = 50.f;
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Green);

    // Center the circle in the window
    circle.setPosition((800 / 2) - radius, (600 / 2) - radius);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
