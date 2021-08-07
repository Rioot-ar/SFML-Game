#ifndef ESCENA_H
#define ESCENA_H
#include "Juego.h"
class Juego;
using namespace sf;
class Escena {
public:
	Escena();
	virtual void Actualizar(Juego &game) = 0;
	virtual void Dibujar(RenderWindow &Vent) = 0;
	virtual ~Escena()=0;
protected:
	Sprite* FondoE, *FlechaM;
	Font* fuente;
	Vector2f TamanioVentana;
	Texture* FlechaMenu;
	Texture* FondoEscena;
	Event* e;
};

#endif

