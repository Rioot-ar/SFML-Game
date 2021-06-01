#include "Escena.h"
#include <SFML/Graphics.hpp>
Escena::Escena() {
	fuente = new Font;
	FlechaMenu = new Texture;
	
	fuente->loadFromFile("Recursos/Pix.ttf");
	FlechaMenu->loadFromFile("Recursos/Flecha.PNG");
}


Escena::~Escena ( ) {
	
}

