#include "Escena.h"
#include <SFML/Graphics.hpp>
Escena::Escena() {
	fuente = new Font;
	FlechaMenu = new Texture;
	e=new Event;
	fuente->loadFromFile("Recursos/Pix.ttf");
	FlechaMenu->loadFromFile("Recursos/Flecha.PNG");
	TamanioVentana={800,600};
}


Escena::~Escena ( ) {
	
}

