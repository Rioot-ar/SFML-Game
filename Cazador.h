#ifndef CAZADOR_H
#define CAZADOR_H
#include "Personaje.h"
#include <cmath>
using namespace std;

class Cazador : public Personaje {
public:
	Cazador();
	void habilidadEspecial ( );
	void Movimiento ( );
	void VerificarDist (Vector2f Per);
	Text Informacion(unsigned TV)override;
	bool Atacar ( );
private:
	Clock HAbInven;
	bool habilidadActivada;
	float VelProyectil;
	Texture* AtaqueEspecial;
};

#endif

