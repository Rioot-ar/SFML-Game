#ifndef MAGO_H
#define MAGO_H
#include "Personaje.h"
#include "Proyectil.h"
using namespace std;

class Mago : public Personaje {
public:
	Mago();
	~Mago()override;
	void habilidadEspecial  ( )override;
	bool Atacar ( )override;
	void Movimiento  ( )override;
	void VerificarDist(Vector2f Per);

private:
	float VelProyectil;
	Texture* AtaqueEspecial;
};

#endif

