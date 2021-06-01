#ifndef SEGUNDONIVEL_H
#define SEGUNDONIVEL_H
#include "Niveles.h"

class SegundoNivel : public Niveles {
public:
	SegundoNivel(Personaje* J);
	void TerminarPartida(Juego & game);
private:
};

#endif

