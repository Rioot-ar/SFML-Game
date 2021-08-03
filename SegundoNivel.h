#ifndef SEGUNDONIVEL_H
#define SEGUNDONIVEL_H
#include "Niveles.h"

class SegundoNivel : public Niveles {
public:
	SegundoNivel(char SDificultad, Personaje* J);
	void TerminarPartida(Juego & game) override;
private:
};

#endif

