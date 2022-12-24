#ifndef JUEGO_H
#define JUEGO_H
#include "Escena.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Escena;

class Juego {
public:
	Juego();
	void Run();
	void SetEscena(Escena *nueva);
	sf::Event *ObtenerEvento(){return &e;}
	~Juego();
	sf::RenderWindow Ventana;
private:
	sf::Event e;
	Escena *Actual;
	Escena *m_siguiente_escena = nullptr;
};
#endif

