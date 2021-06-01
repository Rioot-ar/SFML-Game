#ifndef AYUDA_H
#define AYUDA_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Ayuda : public Escena {
public:
	Ayuda();
	void Actualizar (Juego & game)override;
	void Dibujar (RenderWindow & Vent)override;
	~Ayuda();
private:
	int QueMostrar=0;
	Text ControlesTitulo, DificultadTitulo, PersonajesTitulo;
	Text ControlesContenido, DificultadContenido, PersonajesContenido;
	Texture Fondo;
	Sprite Fondospr;
};

#endif

