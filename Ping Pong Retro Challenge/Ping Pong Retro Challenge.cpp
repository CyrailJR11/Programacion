#include "carlos.h"

// Inicialización de la pala
// Configura las propiedades iniciales de la pala: tamaño, posición, color y velocidad
void inicializarPala(Pala& pala, float x, float y) {
    // Define el tamaño de la pala: 20 píxeles de ancho y 100 de alto
    pala.forma.setSize(sf::Vector2f(20.f, 100.f));

    // Establece la posición inicial de la pala en las coordenadas (x, y)
    pala.forma.setPosition(x, y);

    // Asigna el color blanco a la pala
    pala.forma.setFillColor(sf::Color::White);

    // Define la velocidad de movimiento de la pala en píxeles por segundo
    pala.velocidad = 300.f;
}

// Movimiento de la pala
// Mueve la pala verticalmente según la dirección indicada, respetando los límites de la pantalla
void moverPala(Pala& pala, float deltaTime, bool subir,
    float limiteSuperior, float limiteInferior) {

    // Calcula la distancia a mover basándose en la velocidad y el tiempo transcurrido (deltaTime)
    float movimiento = pala.velocidad * deltaTime;

    // Si el parámetro 'subir' es verdadero, mueve la pala hacia arriba (eje Y negativo)
    if (subir) {
        pala.forma.move({ 0.f, -movimiento });
    }
    // Si es falso, mueve la pala hacia abajo (eje Y positivo)
    else {
        pala.forma.move({ 0.f, movimiento });
    }

    // Límites de movimiento para evitar que la pala salga de la pantalla

    // Si la pala se sale por la parte superior, la reposiciona en el límite superior
    if (pala.forma.getPosition().y < limiteSuperior) {
        pala.forma.setPosition({ pala.forma.getPosition().x, limiteSuperior });
    }

    // Si la pala se sale por la parte inferior, la reposiciona en el límite inferior
    // Se resta la altura de la pala para que el borde inferior quede alineado con el límite
    if (pala.forma.getPosition().y + pala.forma.getSize().y > limiteInferior) {
        pala.forma.setPosition(
            pala.forma.getPosition().x,
            limiteInferior - pala.forma.getSize().y
        );
    }
}

// Dibujo de la pala
// Renderiza la pala en la ventana de SFML
void dibujarPala(sf::RenderWindow& window, Pala& pala) {
    // Dibuja la forma rectangular de la pala en la ventana
    window.draw(pala.forma);
}