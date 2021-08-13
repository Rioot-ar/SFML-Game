#include "Objetivo.h"

Objetivo::Objetivo(Vector2f Tamanio, Vector2f Posicion,Texture* Nivel) {

	
	SonidoObjetivo.openFromFile("Recursos/Utiles/SonidoDePuerta.ogg");
	
	
	esobjetivo=true;
	
	Forma.setSize(Tamanio);
	Forma.setOrigin(0,Forma.getGlobalBounds().height);
	Forma.setPosition(Posicion);
	Forma.setTexture(Nivel);
	
	CuadObT=FloatRect(Forma.getGlobalBounds().left,Forma.getGlobalBounds().top,Forma.getGlobalBounds().width,1.f);;		
	CuadObL=FloatRect(Forma.getGlobalBounds().left+10.0,Forma.getGlobalBounds().top,1,Forma.getGlobalBounds().height);
	CuadObR=FloatRect(Forma.getGlobalBounds().left+Forma.getGlobalBounds().width-1,Forma.getGlobalBounds().top,1.0,Forma.getGlobalBounds().height);
	CuadObB=FloatRect(Forma.getGlobalBounds().left,Forma.getGlobalBounds().top+Forma.getGlobalBounds().height+1.0,Forma.getGlobalBounds().width,1.f);
}

Objetivo::~Objetivo() {

}


Objetivo::Objetivo ( ) {
	
}

