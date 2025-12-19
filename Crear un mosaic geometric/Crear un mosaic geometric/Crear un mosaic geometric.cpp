// Incloem SFML per fer gràfics
#include <SFML/Graphics.hpp>

int main() {
    // Creem una finestra
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mosaic Mondrian");

    // VARIABLE 1: Rectangle vermell
    sf::RectangleShape rectangle1(sf::Vector2f(300.f, 250.f)); // Mida
    rectangle1.setPosition(50.f, 50.f);                         // On està
    rectangle1.setFillColor(sf::Color::Red);                    // Color
    rectangle1.setOutlineThickness(8.f);                        // Línia negra
    rectangle1.setOutlineColor(sf::Color::Black);

    // VARIABLE 2: Rectangle blau
    sf::RectangleShape rectangle2(sf::Vector2f(200.f, 250.f));
    rectangle2.setPosition(370.f, 50.f);
    rectangle2.setFillColor(sf::Color::Blue);
    rectangle2.setOutlineThickness(8.f);
    rectangle2.setOutlineColor(sf::Color::Black);

    // VARIABLE 3: Rectangle groc
    sf::RectangleShape rectangle3(sf::Vector2f(150.f, 250.f));
    rectangle3.setPosition(590.f, 50.f);
    rectangle3.setFillColor(sf::Color::Yellow);
    rectangle3.setOutlineThickness(8.f);
    rectangle3.setOutlineColor(sf::Color::Black);

    // Rectangle blanc 4
    sf::RectangleShape rectangle4(sf::Vector2f(500.f, 200.f));
    rectangle4.setPosition(50.f, 320.f);
    rectangle4.setFillColor(sf::Color::White);
    rectangle4.setOutlineThickness(8.f);
    rectangle4.setOutlineColor(sf::Color::Black);

    // Rectangle blanc 5
    sf::RectangleShape rectangle5(sf::Vector2f(190.f, 200.f));
    rectangle5.setPosition(570.f, 320.f);
    rectangle5.setFillColor(sf::Color::White);
    rectangle5.setOutlineThickness(8.f);
    rectangle5.setOutlineColor(sf::Color::Black);

    // BUCLE: manté la finestra oberta
    while (window.isOpen()) {

        // Si fem clic a la X, es tanca
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Dibuixem tot
        window.clear(sf::Color::White);
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(rectangle4);
        window.draw(rectangle5);
        window.display();
    }

    return 0;
}