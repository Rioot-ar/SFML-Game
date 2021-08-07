#include "Castillo.h"

Castillo::Castillo(Vector2f Posicion, Vector2f Tamanio) {
	Apariencia= new Texture;
	Apariencia->loadFromFile("Recursos/castillo.png");
	
	Forma.setSize(Tamanio);
	Forma.setOrigin(Forma.getGlobalBounds().width/2.f,Forma.getGlobalBounds().height);
	Forma.setPosition(Posicion);
	Forma.setTexture(Apariencia);
	
	CuadObT=FloatRect(Forma.getGlobalBounds().left,Forma.getGlobalBounds().top,Forma.getGlobalBounds().width,1.f);;		
	CuadObL=FloatRect(Forma.getGlobalBounds().left-1.0,Forma.getGlobalBounds().top,1,Forma.getGlobalBounds().height);
	CuadObR=FloatRect(Forma.getGlobalBounds().left+Forma.getGlobalBounds().width+1,Forma.getGlobalBounds().top,1.0,Forma.getGlobalBounds().height);
	CuadObB=FloatRect(Forma.getGlobalBounds().left,Forma.getGlobalBounds().top+Forma.getGlobalBounds().height+1.0,Forma.getGlobalBounds().width,1.f);
}

Castillo::~Castillo() {
	delete Apariencia;
}


Castillo::Castillo ( ) {
	
}

