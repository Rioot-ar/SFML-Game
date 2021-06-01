#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include "Personaje.h"

class Enemigos : public Personaje {
public:
	Enemigos(float Sa, float De, float Da, Vector2f Ve, Vector2f pos);
	bool Atacar ( )override;
	void Movimiento ()override;
	void VerificarDist(Vector2f Per)override;
	~Enemigos()override;
private:
	bool PerEstaEnRango;
	float Pendiente, DistAPers,DirecionX;
};

#endif





