<<<<<<< HEAD
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

=======
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

>>>>>>> 04796e6 (Volumen maestro y debug_win32)
