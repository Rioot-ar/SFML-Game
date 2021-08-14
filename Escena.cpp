#include "Escena.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
Escena::Escena() {
	//Fuente del juego
	fuente = new Font;
	fuente->loadFromFile("Recursos/Utiles/Pix.ttf");
	//Flechas de seleccion
	FlechaMenu = new Texture;
	FlechaMenu->loadFromFile("Recursos/Utiles/Flecha.PNG");
	FlechaM=new Sprite;
	
	FondoEscena= new Texture;
	FondoE= new Sprite;
	
	
	e=new Event;
	
	//Objetos para el cambio de escena
	TEntreEscena=new Texture;
	TEntreEscena->loadFromFile("Recursos/Utiles/EntreEscena.png");
	EntreEscena.setTexture(*TEntreEscena);

	TamanioVentana={800,600};
	
	
}


Escena::~Escena ( ) {
	delete FlechaM;
	delete fuente;
	delete FlechaMenu;
	delete FondoE;
	delete TEntreEscena;
	delete FondoEscena;
	delete e;
	
}

///Se ejecuta al final de cada escena
void Escena::CambioEscena (RenderWindow & Ventana) {
	EntreEscena.setScale(Ventana.getSize().x/(float)TEntreEscena->getSize().x,Ventana.getSize().y/(float)TEntreEscena->getSize().y);
	Clock Transicion;
	int alp=0;
	float son=25;
	while(Transicion.getElapsedTime().asSeconds()<=2){
		MusicaPrincipal.setVolume(MusicaPrincipal.getVolume()-son*Transicion.getElapsedTime().asSeconds());		
		EntreEscena.setColor(Color(1,1,1,alp));
		alp+=1;
		Ventana.setView(View(Vector2f(Ventana.getSize().x/2.f,Ventana.getSize().y/2.f),Vector2f(Ventana.getSize())));	
		Ventana.draw(EntreEscena);
		Ventana.display();
	}
	MusicaPrincipal.stop();
}

