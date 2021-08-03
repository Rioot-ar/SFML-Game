#ifndef CAZADOR_H
#define CAZADOR_H
#include "Personaje.h"

class Cazador : public Personaje {
public:
	Cazador();
	void habilidadEspecial ( );
	void Movimiento ( );
	bool PuedeAtacar ( );
	void VerificarDist (Vector2f Per);
	bool Atacar ( );
private:
};

#endif

