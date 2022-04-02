#include "Plataforma.h"
using namespace sf;
Plataforma::Plataforma(Vector2f Tamanio, Vector2f Posicion, Texture* Nivel) {
	
	esobjetivo=false;
	
	//Visual
	Forma.setTexture(Nivel);
	Forma.setTextureRect(IntRect(0,0,Tamanio.x,Tamanio.y));
	Forma.setSize(Tamanio);
	Forma.setPosition(Posicion);
	///Hitbox del objeto
	CuadObT=FloatRect(Forma.getGlobalBounds().left,Forma.getGlobalBounds().top,Forma.getGlobalBounds().width,-1.f);;		
	CuadObL=FloatRect(Forma.getGlobalBounds().left-1.0,Forma.getGlobalBounds().top,1,Forma.getGlobalBounds().height);
	CuadObR=FloatRect(Forma.getGlobalBounds().left+Forma.getGlobalBounds().width+1,Forma.getGlobalBounds().top,1.0,Forma.getGlobalBounds().height);
	CuadObB=FloatRect(Forma.getGlobalBounds().left,Forma.getGlobalBounds().top+Forma.getGlobalBounds().height+1.0,Forma.getGlobalBounds().width,1.f);
}

Plataforma::~Plataforma ( ) {

}
