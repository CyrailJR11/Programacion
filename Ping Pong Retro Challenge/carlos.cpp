#include "carlos.h"

// Inicialización de la pala
void inicializarPala(Pala& pala, float x, float y) {
    // Establecer el tamaño de la pala: 20 píxeles de ancho x 100 de alto
    pala.forma.setSize(sf::Vector2f(20.f, 100.f));

    // Posicionar la pala en las coordenadas (x, y) especificadas
    pala.forma.setPosition({ x, y });

    // Establecer el color de relleno de la pala en blanco
    pala.forma.setFillColor(sf::Color::White);

    // Definir la velocidad de movimiento en píxeles por segundo
    pala.velocidad = 300.f;
}

// Movimiento de la pala
void moverPala(Pala& pala, float deltaTime, bool subir,
    float limiteSuperior, float limiteInferior) {

    // Calcular el desplazamiento basado en velocidad y tiempo transcurrido
    // Esto asegura movimiento consistente independiente de los FPS
    float movimiento = pala.velocidad * deltaTime;

    // Si subir es true, mover hacia arriba (Y negativo)
    if (subir) {
        pala.forma.move({ 0.f, -movimiento });
    }
    // Si subir es false, mover hacia abajo (Y positivo)
    else {
        pala.forma.move({ 0.f, movimiento });
    }

    // Comprobar colisión con el límite superior de la pantalla
    // Si la pala se sale por arriba, reposicionarla en el límite
    if (pala.forma.getPosition().y < limiteSuperior) {
        pala.forma.setPosition({ pala.forma.getPosition().x, limiteSuperior });
    }

    // Comprobar colisión con el límite inferior de la pantalla
    // Sumar la altura de la pala para detectar cuando el borde inferior se sale
    if (pala.forma.getPosition().y + pala.forma.getSize().y > limiteInferior) {
        // Reposicionar la pala para que su borde inferior coincida con el límite
        pala.forma.setPosition({
            pala.forma.getPosition().x,  // Mantener posición X
            limiteInferior - pala.forma.getSize().y  // Ajustar Y restando la altura
            });
    }
}

// Dibujo
void dibujarPala(sf::RenderWindow& window, Pala& pala) {
    // Renderizar la forma rectangular de la pala en la ventana
    window.draw(pala.forma);
}