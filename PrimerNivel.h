#ifndef PRIMERNIVEL_H
#define PRIMERNIVEL_H

class PrimerNivel : public Niveles {
public:
	PrimerNivel(char Dificultad, char SPersonaje);
	void TerminarPartida(Juego & game);
private:
};

#endif

