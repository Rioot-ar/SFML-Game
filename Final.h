#ifndef FINAL_H
#define FINAL_H
#include "Niveles.h"


class Final : public Niveles {
public:
	Final(char SDificultad, Personaje* J);
	void TerminarPartida(Juego & game)override;
private:
};

#endif

