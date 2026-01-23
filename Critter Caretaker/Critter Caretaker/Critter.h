#ifndef CRITTER_H
#define CRITTER_H

#include <iostream>
#include <string>
using namespace std;

class Critter
{
    // Funcions friend per mostrar l'estat de la mascota
    friend void ShowCritterStatus(const Critter& c);
    friend ostream& operator<<(ostream& os, const Critter& c);

protected:
    int m_Hunger;     // Nivell de fam
    int m_Boredom;    // Nivell d'avorriment
    string m_Name;    // Nom de la mascota

private:
    // Simula el pas del temps
    void PassTime();

    // Calcula l'estat d'anim segons fam i avorriment
    string GetMood() const;

public:
    // Constructor
    Critter(const string& name = "Anonim", int hunger = 0, int boredom = 0);

    // Saluda la mascota
    virtual void Greet() const;

    // Getters i setters
    int GetHunger() const;
    void SetHunger(int hunger);
    string GetName() const;

    // Accions de la mascota
    void Play(int fun = 4);
    void Eat(int food = 4);
    void Talk() const;
    void Sleep();

    // Sobrecarga de l'operador +
    Critter operator+(const Critter& other) const;
};

#endif
