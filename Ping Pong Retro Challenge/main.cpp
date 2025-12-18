#include <SFML/Graphics.hpp>
#include "carlos.h"

int main() {
    // Crear ventana de juego con resolución 800x600 y título
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Ping Pong Retro Challenge");

    // Limitar la velocidad de actualización a 60 FPS para un juego fluido
    window.setFramerateLimit(60);

    // Reloj para medir el tiempo entre frames (deltaTime)
    sf::Clock clock;

    // Crear e inicializar la pala izquierda en posición (30, 250)
    Pala palaIzquierda;
    inicializarPala(palaIzquierda, 30.f, 250.f);

    // Bucle principal del juego - se ejecuta mientras la ventana esté abierta
    while (window.isOpen()) {
        // Calcular deltaTime: tiempo transcurrido desde el último frame
        // Esto permite movimiento independiente de la velocidad de frames
        float deltaTime = clock.restart().asSeconds();

        // GESTIÓN DE EVENTOS (nueva estructura SFML 3)
        // Procesar todos los eventos pendientes de la ventana
        while (const std::optional event = window.pollEvent()) {
            // Si el usuario cierra la ventana (X), cerrar el juego
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // Si se presiona alguna tecla
            if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
                // Si la tecla es Escape, cerrar el juego
                if (key->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                }
            }
        }

        // ACTUALIZACIÓN (input de teclado)
        // Detectar tecla W presionada (mover pala hacia arriba)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) {
            // Mover pala arriba (true), dentro de los límites 0-600
            moverPala(palaIzquierda, deltaTime, true, 0.f, 600.f);
        }

        // Detectar tecla S presionada (mover pala hacia abajo)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) {
            // Mover pala abajo (false), dentro de los límites 0-600
            moverPala(palaIzquierda, deltaTime, false, 0.f, 600.f);
        }

        // RENDERIZADO
        // Limpiar la pantalla con color negro (fondo del juego)
        window.clear(sf::Color::Black);

        // Dibujar la pala izquierda en la ventana
        dibujarPala(window, palaIzquierda);

        // Mostrar todo lo dibujado en la pantalla (swap de buffers)
        window.display();
    }

    // Finalizar el programa correctamente
    return 0;
}