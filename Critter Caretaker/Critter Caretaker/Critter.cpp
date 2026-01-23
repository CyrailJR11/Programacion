#include "Critter.h"

// Constructor
Critter::Critter(const string& name, int hunger, int boredom)
    : m_Name(name), m_Hunger(hunger), m_Boredom(boredom)
{
}

// Saluda la mascota
void Critter::Greet() const
{
    cout << "Hola, soc " << m_Name << endl;
}

// Retorna el nivell de fam
int Critter::GetHunger() const
{
    return m_Hunger;
}

// Modifica el nivell de fam
void Critter::SetHunger(int hunger)
{
    m_Hunger = hunger;
}

// Retorna el nom de la mascota
string Critter::GetName() const
{
    return m_Name;
}

// Simula el pas del temps
void Critter::PassTime()
{
    m_Hunger++;
    m_Boredom++;
}

// Calcula l'estat d'anim segons fam i avorriment
string Critter::GetMood() const
{
    int mood = m_Hunger + m_Boredom;

    if (mood < 5) return "Felic";
    else if (mood < 10) return "Normal";
    else if (mood < 15) return "Enfadat";
    else return "Boig";
}

// Jugar amb la mascota
void Critter::Play(int fun)
{
    m_Boredom -= fun;
    if (m_Boredom < 0) m_Boredom = 0;
    PassTime();
}

// Donar menjar a la mascota
void Critter::Eat(int food)
{
    m_Hunger -= food;
    if (m_Hunger < 0) m_Hunger = 0;
    PassTime();
}

// Escoltar la mascota
void Critter::Talk() const
{
    cout << "Soc " << m_Name
        << " i em sento " << GetMood() << endl;
}

// Funcio extra: dormir
void Critter::Sleep()
{
    m_Boredom = 0;
    PassTime();
}

// Sobrecarga de l'operador +
Critter Critter::operator+(const Critter& other) const
{
    Critter baby(m_Name + "-" + other.m_Name);
    baby.m_Hunger = (m_Hunger + other.m_Hunger) / 2;
    baby.m_Boredom = (m_Boredom + other.m_Boredom) / 2;
    return baby;
}

// Mostra l'estat complet de la mascota
void ShowCritterStatus(const Critter& c)
{
    cout << "[STATUS] Nom: " << c.m_Name
        << " | Hunger: " << c.m_Hunger
        << " | Boredom: " << c.m_Boredom
        << endl;
}

// Operador <<
ostream& operator<<(ostream& os, const Critter& c)
{
    os << "Nom: " << c.m_Name
        << " | Hunger: " << c.m_Hunger
        << " | Boredom: " << c.m_Boredom;
    return os;
}
