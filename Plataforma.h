#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include "Objeto.h"

class Plataforma : public Objeto {
public:
	Plataforma(sf::Vector2f Tamanio, sf::Vector2f Posicion, sf::Texture* Nivel);

	~Plataforma();
private:
	
};

#endif
