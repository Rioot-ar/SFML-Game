#ifndef CAZADOR_H
#define CAZADOR_H
#include "Personaje.h"


class Cazador : public Personaje {
public:
	Cazador();
	void habilidadEspecial ( );
	void Movimiento ( );
	void VerificarDist (sf::Vector2f Per);
	sf::Text Informacion(unsigned TV)override;
	bool Atacar ( );
	~Cazador(	);
private:
	sf::Clock HAbInven;
	bool habilidadActivada;
	float VelProyectil;

};

#endif

