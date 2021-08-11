#ifndef ESCENA_H
#define ESCENA_H
#include "Juego.h"
#include <SFML/Audio.hpp>
class Juego;
using namespace sf;
class Escena {
public:
	Escena();
	virtual void Actualizar(Juego &game) = 0;
	virtual void Dibujar(RenderWindow &Vent) = 0;
	void EntreEscena(RenderWindow &Ventana);
	virtual ~Escena();
protected:
	Sprite* FondoE, *FlechaM;
	Font* fuente;
	Vector2f TamanioVentana;
	Texture* FlechaMenu;
	Texture* FondoEscena;
	Event* e;
	
	Music MusicaPrincipal;
};

#endif

