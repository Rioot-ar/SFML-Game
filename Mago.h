#ifndef MAGO_H
#define MAGO_H
#include "Personaje.h"
#include "Proyectil.h"


class Mago : public Personaje {
public:
	Mago();
	~Mago()override;
	void habilidadEspecial  ( )override;
	bool Atacar ( )override;
	void Movimiento  (  )override;
	void VerificarDist(sf::Vector2f Per);
	sf::Text Informacion(unsigned TV)override;

private:
	float VelProyectil;
	sf::Texture* AtaqueEspecial;
};

#endif

