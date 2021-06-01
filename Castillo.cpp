#include "Castillo.h"

Castillo::Castillo(Vector2f Posicion, Vector2f Tamanio) {
	Apariencia= new Texture;
	Apariencia->loadFromFile("Recursos/castillo.png");
	
	Forma.setSize(Tamanio);
	Forma.setOrigin(Forma.getGlobalBounds().width/2,Forma.getGlobalBounds().height/2);
	Forma.setPosition(Posicion);
	Forma.setTexture(Apariencia);
}

Castillo::~Castillo() {
	delete Apariencia;
}


Castillo::Castillo ( ) {
	
}

