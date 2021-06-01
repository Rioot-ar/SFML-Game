#ifndef CASTILLO_H
#define CASTILLO_H
#include "Objeto.h"

class Castillo : public Objeto {
public:
	Castillo();
	Castillo(Vector2f Posicion, Vector2f Tamanio);
	~Castillo();
private:
};

#endif

