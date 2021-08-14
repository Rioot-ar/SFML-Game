#ifndef CABALLERO_H
#define CABALLERO_H
#include "Personaje.h"

class Caballero : public Personaje {
public:
	Caballero();
	void habilidadEspecial ( );
	void Movimiento ( );
	sf::Text Informacion(unsigned TV)override;
	bool Atacar ( );
	~Caballero(	);
private:
	sf::Clock HAbInven;
	bool habilidadActivada;
};

#endif

