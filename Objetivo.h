#ifndef OBJETIVO_H
#define OBJETIVO_H
#include "Objeto.h"
#include <SFML/Audio/Music.hpp>

class Objetivo : public Objeto {
public:
	Objetivo();
	Objetivo(Vector2f Posicion, Vector2f Tamanio,Texture* Nivel);
	bool EsObjetivo() override {SonidoObjetivo.play();return esobjetivo;}
	~Objetivo();
private:
	Music SonidoObjetivo;
};

#endif

