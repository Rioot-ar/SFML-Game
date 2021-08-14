#include "Objetivo.h"
using namespace sf;
Objetivo::Objetivo(Vector2f Tamanio, Vector2f Posicion,Texture* Nivel) {

	//Sonido del objetivo
	SonidoObjetivo.openFromFile("Recursos/Utiles/SonidoDePuerta.ogg");
	
	
	esobjetivo=true;
	//Visual
	Forma.setSize(Tamanio);
	Forma.setOrigin(0,Forma.getGlobalBounds().height);
	Forma.setPosition(Posicion);
	Forma.setTexture(Nivel);
	
	///Hitbox del objeto
	CuadObT=FloatRect(Forma.getGlobalBounds().left,Forma.getGlobalBounds().top,Forma.getGlobalBounds().width,1.f);;		
	CuadObL=FloatRect(Forma.getGlobalBounds().left+5.0,Forma.getGlobalBounds().top,1,Forma.getGlobalBounds().height);
	CuadObR=FloatRect(Forma.getGlobalBounds().left+Forma.getGlobalBounds().width-1,Forma.getGlobalBounds().top,1.0,Forma.getGlobalBounds().height);
	CuadObB=FloatRect(Forma.getGlobalBounds().left,Forma.getGlobalBounds().top+Forma.getGlobalBounds().height+1.0,Forma.getGlobalBounds().width,1.f);
}

Objetivo::~Objetivo() {

}


Objetivo::Objetivo ( ) {
	
}

