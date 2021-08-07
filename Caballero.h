#ifndef CABALLERO_H
#define CABALLERO_H
#include "Personaje.h"
#include <SFML/System/Clock.hpp>
using namespace std;

class Caballero : public Personaje {
public:
	Caballero();
	void habilidadEspecial ( );
	void Movimiento ( );
	void VerificarDist (Vector2f Per);
	bool Atacar ( );
private:
	Clock HAbInven, AnimAtaque;;
	bool habilidadActivada;
};

#endif

