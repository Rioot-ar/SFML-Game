#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
#include "Escena.h"
class Escena;
using namespace sf;

class Juego {
public:
	Juego();
	void Run();
	void SetEscena(Escena *nueva);
	RenderWindow Ventana;
	~Juego();
	Event e;
private:
	Escena *Actual;
	Escena *m_siguiente_escena = nullptr;
};
#endif

