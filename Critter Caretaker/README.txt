# Critter Caretaker 🐾

## Descripción
Critter Caretaker es un pequeño juego de mascota virtual desarrollado en C++.  
El jugador es responsable de cuidar a una o varias mascotas, manteniéndolas felices mediante diferentes acciones como jugar, dar de comer o escuchar cómo se sienten.

El proyecto está basado en el código de **Critter** proporcionado en clase y ha sido ampliado siguiendo los requisitos del enunciado.

---

## Funcionalidades principales
- Jugar con la mascota para reducir el aburrimiento.
- Alimentar a la mascota para reducir la hambre.
- Escuchar a la mascota y conocer su estado de ánimo.
- Estado de ánimo calculado dinámicamente según hambre y aburrimiento.
- Simulación del paso del tiempo.
- Función extra de comportamiento (dormir).
- Sobrecarga del operador `+` para unir dos mascotas.
- Clase hija `BabyCritter` con comportamiento más básico.
- Clase `Granja` que almacena múltiples mascotas usando un `vector`.

---

## Estructura del proyecto
CritterCaretaker/
│── Critter.h
│── Critter.cpp
│── BabyCritter.h
│── BabyCritter.cpp
│── Granja.h
│── Granja.cpp
│── CritterCaretaker.cpp
│── UML.png
│── README.md