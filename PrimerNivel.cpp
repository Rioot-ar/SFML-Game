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
#include "Cazador.h"
#include "Honderos.h"
#include "Asesino.h"
#include "Bandidos.h"

PrimerNivel::PrimerNivel(char SDificultad, char SPersonaje) {
	
	FondoEscena= new Texture;
	FondoE= new Sprite;
	FondoEscena->loadFromFile("Recursos/FondoNivel.png");
	
	FondoE->setTexture(*FondoEscena);
	FondoE->setOrigin(0,FondoE->getGlobalBounds().height);
	FondoE->setScale(1,TamanioVentana.y/FondoEscena->getSize().y);
	
	Dificultad=SDificultad;
	

	
	//Personaje, define las habilidades y la apariencia del jugador.
	switch(SPersonaje){
	case 'M':
		Jugador = new Mago;
		break;
	case 'C':
		Jugador = new Caballero;
		break;
	case 'H':
		Jugador = new Cazador;
		break;
	}
	//Dificultad, Define numero de enemigos y tipo de enemigos
	switch(SDificultad){
	case 'N':
		for(int i=1;i<16;i++) { 
			switch(int Tipo=rand()%2){
			case 0:
				Malosmalosos.push_back(new Honderos(Vector2f(250*i,200)));
				break;
			case 1:
				Malosmalosos.push_back(new Honderos(Vector2f(215*i,200)));
				break;
			}
		}
		break;
	case 'D':
		for(int i=1;i<21;i++) { 
			switch(int Tipo=rand()%3){
			case 0:
				Malosmalosos.push_back(new Honderos(Vector2f(150*i,200)));
				break;
			case 1:
				Malosmalosos.push_back(new Honderos(Vector2f(150*i,200)));
				break;
			case 2:
				Malosmalosos.push_back(new Honderos(Vector2f(150*i,200)));
				break;
			}
			
		}
		break;
	}
	///Definir nivel
	//Piso 
	Objetos.push_back(new Plataforma(Vector2f(1140,50),Vector2f(-20,550)));
	Objetos.push_back(new Plataforma(Vector2f(1140,50),Vector2f(1220,550)));
	Objetos.push_back(new Plataforma(Vector2f(25,25),Vector2f(2420,550)));
	Objetos.push_back(new Plataforma(Vector2f(25,25),Vector2f(2500,550)));
	Objetos.push_back(new Plataforma(Vector2f(25,25),Vector2f(2580,550)));
	Objetos.push_back(new Plataforma(Vector2f(25,25),Vector2f(2660,550)));
	Objetos.push_back(new Plataforma(Vector2f(1140,50),Vector2f(2740,550)));
	
	//Plataformas
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(150,475)));
	Objetos.push_back(new Plataforma(Vector2f(300,25),Vector2f(250,400)));
	Objetos.push_back(new Plataforma(Vector2f(200,25),Vector2f(650,400)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(925,330)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(1170,360)));
	Objetos.push_back(new Plataforma(Vector2f(250,25),Vector2f(1400,360)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(1750,300)));
	Objetos.push_back(new Plataforma(Vector2f(120,25),Vector2f(2050,300)));
	Objetos.push_back(new Plataforma(Vector2f(200,25),Vector2f(2300,300)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(2800,475)));
	Objetos.push_back(new Plataforma(Vector2f(200,25),Vector2f(3000,355)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(3050,475)));
	
	//Objetivo
	Objetos.push_back(new Castillo(Vector2f(400,200),Vector2f(3500,552)));
	
	FondoE->setPosition(-600,600);
	
	
	m_camara1 = new View;
	m_camara1->setSize(800.f,600.f);
	m_camara1->setCenter(0,300);
	
	MusicaPrincipal.openFromFile("Recursos/MPrimerNivel.ogg");
	MusicaPrincipal.setLoop(true);
	MusicaPrincipal.setVolume(50);
	MusicaPrincipal.play();
	
}


void PrimerNivel::TerminarPartida (Juego & game) {
	if(Jugador->ObtenerSalud()>0){
		Jugador->consultarPuntos()+=100;
		game.SetEscena(new SegundoNivel(Dificultad,Jugador));
	}else{
		game.SetEscena(new Puntaje(Jugador->consultarPuntos()));
	}
}

