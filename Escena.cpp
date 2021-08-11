#include "Escena.h"
#include <SFML/Graphics.hpp>
using namespace std;
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

void Escena::EntreEscena (RenderWindow & Ventana) {
	Texture prueba;
	prueba.loadFromFile("Recursos/EntreEscena.png");
	Sprite prue;
	prue.setTexture(prueba);
	prue.setScale((float)Ventana.getSize().x/(float)prueba.getSize().x,(float)Ventana.getSize().y/(float)prueba.getSize().y);
	Ventana.setView(View(Vector2f(Ventana.getSize().x/2.f,Ventana.getSize().y/2.f),Vector2f(Ventana.getSize())));	
	Clock Transicion;
	int alp=50;
	float son=25;
	while(Transicion.getElapsedTime().asSeconds()<=2){
		MusicaPrincipal.setVolume(MusicaPrincipal.getVolume()-son*Transicion.getElapsedTime().asSeconds());
		prue.setColor(Color(1,1,1,alp));
		alp+=1;
		Ventana.draw(prue);
		Ventana.display();
	}
}

