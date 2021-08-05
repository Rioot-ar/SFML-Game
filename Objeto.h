#ifndef OBJETO_H
#define OBJETO_H
#include <SFML/Graphics.hpp>
using namespace sf;
class Objeto {
public:
	Objeto();
	FloatRect CuadObT,CuadObL,CuadObR,CuadObB;
	RectangleShape ObtenerForma(){return Forma;}
	virtual ~Objeto();
protected:
	RectangleShape Forma;

	Texture* Apariencia;
};

#endif

