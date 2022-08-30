<<<<<<< HEAD
#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include "Personaje.h"


class Enemigos : public Personaje {
public:
	Enemigos();
	virtual bool Atacar ( );
	void Movimiento ()override ;
	void VerificarDist(sf::Vector2f Per)override;
	virtual void habilidadEspecial();
	virtual ~Enemigos();
protected:
	bool PersonajeVisto;
	float VelProyectil, RangoVision,RangoAtaque;
};

#endif





=======
#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include "Personaje.h"


class Enemigos : public Personaje {
public:
	Enemigos();
	virtual bool Atacar ( );
	void Movimiento ()override ;
	void VerificarDist(sf::Vector2f Per)override;
	virtual void habilidadEspecial();
	virtual ~Enemigos();
protected:
	bool PersonajeVisto;
	float VelProyectil, RangoVision,RangoAtaque;
};

#endif





>>>>>>> 04796e6 (Volumen maestro y debug_win32)
