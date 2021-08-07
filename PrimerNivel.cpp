#include "Niveles.h"
#include <SFML/Graphics.hpp>
#include "Mago.h"
#include "Plataforma.h"
#include <list>
#include "Castillo.h"
#include "PrimerNivel.h"
#include "Puntaje.h"
#include "SegundoNivel.h"
#include "Personaje.h"
#include "Caballero.h"

PrimerNivel::PrimerNivel(char SDificultad, char SPersonaje) {
	
	FondoEscena= new Texture;
	FondoE= new Sprite;
	FondoEscena->loadFromFile("Recursos/FondoNivel.png");
	
	FondoE->setTexture(*FondoEscena);
	FondoE->setOrigin(0,FondoE->getGlobalBounds().height);
	FondoE->setScale(1,TamanioVentana.y/FondoEscena->getSize().y);
	
	Dificultad=SDificultad;
	//Dificultad, Define numero de enemigos, tiempo limite y tipo de enemigos
	switch(SDificultad){
	case 'N':
		
		break;
	case 'D':
		for(int i=2;i<3;i++) {  
			Malosmalosos.push_back(new Enemigos(1,50,0,Vector2f(1,5),Vector2f(500*i,200)));
		}
		break;
	}
	
	//Personaje, define las habilidades y la apariencia del jugador.
	switch(SPersonaje){
	case 'M':
		Jugador = new Mago;
		break;
	case 'C':
		Jugador = new Caballero;
		break;
	case 'H':
		/*Jugador = new Cazador;*/
		break;
	}
	
	
	//Definir nivel: piso, plataformas.
	
	Objetos.push_back(new Plataforma(Vector2f(10000,50),Vector2f(-20,550)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(20,300)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(50,250)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(75,200)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(100,150)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(125,100)));
	Objetos.push_back(new Castillo(Vector2f(800,550),Vector2f(100,550)));
	
	FondoE->setPosition(-500,600);
	
	
	m_camara1 = new View;
	m_camara1->setSize(800.f,600.f);
	m_camara1->setCenter(0,300);
	
}


void PrimerNivel::TerminarPartida (Juego & game) {
	if(Jugador->ObtenerSalud()!=0){
		Jugador->consultarPuntos()+=100;
		game.SetEscena(new SegundoNivel(Dificultad,Jugador));
	}else{
		game.SetEscena(new Puntaje(Jugador->consultarPuntos()));
	}
}

