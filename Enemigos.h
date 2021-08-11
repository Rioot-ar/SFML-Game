#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include "Personaje.h"

class Enemigos : public Personaje {
public:
	Enemigos();
	bool Atacar ( )override;
	void Movimiento ()override;
	void VerificarDist(Vector2f Per)override;
	void habilidadEspecial()override;
	~Enemigos()override;
protected:
	bool PersonajeVisto;
	float VelProyectil, RangoVision,RangoAtaque;
};

#endif





