#ifndef OBJETO_H
#define OBJETO_H
#include <SFML/Graphics.hpp>

class Objeto {
public:
	Objeto();
	sf::FloatRect CuadObT,CuadObL,CuadObR,CuadObB;
	sf::RectangleShape* ObtenerForma(){return &Forma;}
	virtual bool EsObjetivo(){return esobjetivo;}
	virtual ~Objeto();
protected:
	bool esobjetivo;
	sf::RectangleShape Forma;
};

#endif
