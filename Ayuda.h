#ifndef AYUDA_H
#define AYUDA_H
#include "Escena.h"


class Ayuda : public Escena {
public:
	Ayuda();
	void Actualizar (Juego & game)override;
	void Dibujar (sf::RenderWindow & Vent)override;
	~Ayuda();
private:
	int QueMostrar=0;
	sf::Text ControlesTitulo, DificultadTitulo, PersonajesTitulo;
	sf::Text ControlesContenido, DificultadContenido, PersonajesContenido;
	
};

#endif

