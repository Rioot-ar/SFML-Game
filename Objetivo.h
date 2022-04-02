#ifndef OBJETIVO_H
#define OBJETIVO_H
#include "Objeto.h"
#include <SFML/Audio.hpp>


class Objetivo : public Objeto {
public:
	Objetivo();
	Objetivo(sf::Vector2f Posicion, sf::Vector2f Tamanio,sf::Texture* Nivel);
	bool EsObjetivo() override {SonidoObjetivo.play();return esobjetivo;}
	~Objetivo();
private:
	sf::Music SonidoObjetivo;
};

#endif

