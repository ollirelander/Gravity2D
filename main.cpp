#include "gravity2d.hpp"

int main() {
    gravity2d::particle_cell_map_t map;
    map.create({ 500, 500 }, { 50, 50 }, 10000, 100);


    //sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity2D");

    //sf::RectangleShape rectangle(sf::Vector2f(200.f, 100.f));
    //rectangle.setFillColor(sf::Color::Red);

    //rectangle.setPosition(window.getSize().x / 2 - rectangle.getSize().x / 2,
    //    window.getSize().y / 2 - rectangle.getSize().y / 2);

    //while (window.isOpen()) {
    //    sf::Event event;
    //    while (window.pollEvent(event)) {
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //    }

    //    window.clear(sf::Color::Black);
    //    window.draw(rectangle);
    //    window.display();
    //}

    return 0;
}
