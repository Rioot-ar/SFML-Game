#include "Plataforma.h"
Plataforma::Plataforma(Vector2f Tamanio, Vector2f Posicion) {
	Apariencia= new Texture;
	Apariencia->loadFromFile("Recursos/Piso.png");
	
	Forma.setSize(Tamanio);
	Forma.setPosition(Posicion);
	Forma.setTexture(Apariencia);
	
	CuadObT=FloatRect(Forma.getGlobalBounds().left,Forma.getGlobalBounds().top,Forma.getGlobalBounds().width,1.f);;		
	CuadObL=FloatRect(Forma.getGlobalBounds().left-1.0,Forma.getGlobalBounds().top,1,Forma.getGlobalBounds().height);
	CuadObR=FloatRect(Forma.getGlobalBounds().left+Forma.getGlobalBounds().width+1,Forma.getGlobalBounds().top,1.0,Forma.getGlobalBounds().height);
	CuadObB=FloatRect(Forma.getGlobalBounds().left,Forma.getGlobalBounds().top+Forma.getGlobalBounds().height+1.0,Forma.getGlobalBounds().width,1.f);
}
Plataforma::~Plataforma ( ) {
	delete Apariencia;
}
