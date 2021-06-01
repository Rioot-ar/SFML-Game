#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include "Objeto.h"
using namespace sf;
class Plataforma : public Objeto {
public:
	Plataforma(Vector2f Tamanio, Vector2f Posicion);
	~Plataforma();
private:
};

#endif

