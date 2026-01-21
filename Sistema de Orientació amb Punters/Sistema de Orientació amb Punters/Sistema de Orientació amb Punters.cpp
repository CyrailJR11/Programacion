#include <iostream>
#include <cmath>     // Per sqrt() i pow()
using namespace std;

// ----------------------------------------------------
// Estructura Enemy: representa un enemic del videojoc
// ----------------------------------------------------
struct Enemy {
	int id;     // Identificador de l’enemic
	float x, y; // Coordenades a l'espai
	int hp;     // Punts de vida
};

// ----------------------------------------------------
// Funció que retorna un PUNTER a l'enemic més proper
// al jugador, que està situat a (0,0).
// ----------------------------------------------------
Enemy* trobarEnemic(Enemy* enemics, int n) {

	// Primer considerem que el primer enemic és el més proper
	Enemy* mesProper = &enemics[0];

	// Distància del primer enemic al jugador
	float millorDist = sqrt(pow(enemics[0].x, 2) + pow(enemics[0].y, 2));

	// Recorrem tots els enemics
	for (int i = 1; i < n; i++) {

		// Distància de l'enemic actual al jugador
		float d = sqrt(pow(enemics[i].x, 2) + pow(enemics[i].y, 2));

		// Si aquest enemic és més proper, actualitzem el punter
		if (d < millorDist) {
			millorDist = d;
			mesProper = &enemics[i];
		}
	}

	// Retornem el punter a l'enemic més proper
	return mesProper;
}

// ----------------------------------------------------
// Aplica dany a l'enemic apuntat pel punter
// e → punter a Enemy
// quant → quantitat de dany
// ----------------------------------------------------
void dany(Enemy* e, int quant) {

	// Mostrem l'HP abans i després del dany
	cout << "Enemy " << e->id << " HP: " << e->hp << " : ";

	e->hp -= quant;  // Reduïm HP usant punters (->)

	cout << e->hp << endl;

	// Si arriba a 0, l'enemic és destruït
	if (e->hp <= 0) {
		cout << "Enemy destroyed!" << endl;
	}
}

int main() {
	int n;

	// Demanem quants enemics vol generar l’usuari
	cout << "Quants enemics vols generar? (minim 3): ";
	cin >> n;

	// Si l’usuari dóna un número inferior, posem 3
	if (n < 3) {
		cout << "Nombre insuficient. S'estableixen 3 enemics automàticament.\n";
		n = 3;
	}

	// ------------------------------------------------
	// CREACIÓ DINÀMICA DE L’ARRAY D’ENEMICS
	// ------------------------------------------------
	Enemy* enemics = new Enemy[n];  // Reservem memòria al heap

	// ------------------------------------------------
	// OMPLEM L’ARRAY AMB DADES INVENTADES
	// ------------------------------------------------
	for (int i = 0; i < n; i++) {
		enemics[i].id = i + 1; // ID automàtic

		// Coordenades aleatòries entre -10 i 10
		enemics[i].x = (rand() % 21 - 10);
		enemics[i].y = (rand() % 21 - 10);

		enemics[i].hp = 30;  // HP inicial
	}

	cout << "\n[Targeting System Activated]" << endl;

	// ------------------------------------------------
	// TROBEM L’ENEMIC MÉS PROPER (RETORNA UN PUNTER)
	// ------------------------------------------------
	Enemy* target = trobarEnemic(enemics, n);

	// Calculem la distància del target
	float dist = sqrt(pow(target->x, 2) + pow(target->y, 2));

	// Mostrem informació
	cout << "Enemy mes proper: ID " << target->id
		<< " (addr: " << target << ")" << endl;
	cout << "Distancia: " << dist << endl;

	// ------------------------------------------------
	// APLIQUEM DANY A TRAVÉS DEL PUNTER
	// ------------------------------------------------
	cout << "\nAplican dany..." << endl;
	dany(target, 20);  // resta 20 d’HP
	dany(target, 10);  // resta 10 d’HP

	// ------------------------------------------------
	// ALLIBERAMENT DE MEMÒRIA DINÀMICA
	// ------------------------------------------------
	delete[] enemics;   // Alliberem l'array
	enemics = nullptr;  // Bona pràctica: evitar punters penjats

	return 0;
}
