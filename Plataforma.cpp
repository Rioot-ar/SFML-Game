#include "Plataforma.h"
Plataforma::Plataforma(Vector2f Tamanio, Vector2f Posicion) {
	Apariencia= new Texture;
	Apariencia->loadFromFile("Recursos/Piso.png");
	
	Forma.setSize(Tamanio);
	Forma.setOrigin(0.f,Forma.getGlobalBounds().height);
	Forma.setPosition(Posicion);
	Forma.setTexture(Apariencia);
}
Plataforma::~Plataforma ( ) {
	delete Apariencia;
}

