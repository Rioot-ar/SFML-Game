#ifndef PRIMERNIVEL_H
#define PRIMERNIVEL_H

class PrimerNivel : public Niveles {
public:
	PrimerNivel(char SDificultad, char SPersonaje);
	void TerminarPartida(Juego & game) override;
private:
};

#endif

