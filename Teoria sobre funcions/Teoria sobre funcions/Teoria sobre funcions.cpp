#include <iostream>
#include <string>
using namespace std;

// ============================
// Macros para los grupos de edad
// ============================
#define CHILD 0
#define TEEN 1
#define ADULT 2
#define SENIOR 3

// ============================
// Función que pide el nombre del usuario
// ============================
string GetName() {
    string name;
    cout << "Please enter your name: ";
    getline(std::cin, name);
    return name;
}

// ============================
// Función que pide la edad del usuario
// ============================
int GetAge() {
    int age;
    cout << "Please enter your age: ";
    cin >> age;
    cin.ignore(); // Limpiar el buffer por si el usuario mete un salto de línea
    return age;
}

// ============================
// Función que determina el grupo según la edad
// ============================
int GetAgeGroup(int age) {
    if (age < 13)
        return CHILD;
    else if (age < 18)
        return TEEN;
    else if (age < 65)
        return ADULT;
    else
        return SENIOR;
}

// ============================
// Función que devuelve el nombre del grupo
// ============================
string GetGroupName(int group) {
    switch (group) {
    case CHILD: return "Child";
    case TEEN: return "Teenager";
    case ADULT: return "Adult";
    case SENIOR: return "Senior";
    default: return "Unknown";
    }
}

// ============================
// Función principal (main)
// ============================
int main() {
    string name = GetName();   // Pedir el nombre
    int age = GetAge();             // Pedir la edad

    int group = GetAgeGroup(age);   // Calcular el grupo
    string groupName = GetGroupName(group);  // Obtener el nombre del grupo

    cout << "\n--------------------------------\n";
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << "Assigned group: " << groupName << "\n";
    cout << "--------------------------------\n";

    return 0;
}
