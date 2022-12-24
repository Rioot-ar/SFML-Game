#include "Niveles.h"
#include <SFML/Graphics.hpp>
#include "Mago.h"
#include "Plataforma.h"
#include <list>
#include "PrimerNivel.h"
#include "Puntaje.h"
#include "SegundoNivel.h"
#include "Personaje.h"
#include "Caballero.h"
#include "Cazador.h"
#include "Honderos.h"
#include "Asesino.h"
#include "Bandidos.h"
#include "Objetivo.h"
#include <string>

using namespace std;
using namespace sf;

PrimerNivel::PrimerNivel(char SDificultad, char SPersonaje) {
	
	//Fondo del nivel, la escala en x se la deja fija para no perder tanta calidad en imagen
	Piso= new Texture;
	TObjetivo=new Texture;	
	Piso->loadFromFile("Recursos/Estructuras/PisoPrimerNivel.png");
	TObjetivo->loadFromFile("Recursos/Estructuras/Castillo.png");
	FondoEscena->loadFromFile("Recursos/Estructuras/FondoNivel.png");
	
	FondoE->setTexture(*FondoEscena);
	FondoE->setOrigin(0,FondoE->getGlobalBounds().height);
	FondoE->setScale(1,TamanioVentana.y/FondoEscena->getSize().y);
	FondoE->setPosition(-600,600);
	
	
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
				Malosmalosos.push_back(new Honderos(Vector2f(215*i,200)));
				break;
			case 1:
				Malosmalosos.push_back(new Bandidos(Vector2f(215*i,200)));
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
				Malosmalosos.push_back(new Bandidos(Vector2f(150*i,200)));
				break;
			case 2:
				Malosmalosos.push_back(new Asesino(Vector2f(150*i,200)));
				break;
			}
			
		}
		break;
	}
	///Definir nivel
	//Piso 
	Objetos.push_back(new Plataforma(Vector2f(1140,50),Vector2f(-20,550),Piso));
	Objetos.push_back(new Plataforma(Vector2f(1140,50),Vector2f(1220,550),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,25),Vector2f(2420,550),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,25),Vector2f(2500,550),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,25),Vector2f(2580,550),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,25),Vector2f(2660,550),Piso));
	Objetos.push_back(new Plataforma(Vector2f(1140,50),Vector2f(2740,550),Piso));
	
	//Plataformas
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(150,475),Piso));
	Objetos.push_back(new Plataforma(Vector2f(300,25),Vector2f(250,400),Piso));
	Objetos.push_back(new Plataforma(Vector2f(200,25),Vector2f(650,400),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(925,330),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(1170,360),Piso));
	Objetos.push_back(new Plataforma(Vector2f(250,25),Vector2f(1400,360),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(1750,360),Piso));
	Objetos.push_back(new Plataforma(Vector2f(120,25),Vector2f(1950,360),Piso));
	Objetos.push_back(new Plataforma(Vector2f(200,25),Vector2f(2150,360),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(2800,475),Piso));
	Objetos.push_back(new Plataforma(Vector2f(200,25),Vector2f(3000,355),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(3050,475),Piso));
	
	//Objetivo
	Objetos.push_back(new Objetivo(Vector2f(400,200),Vector2f(3500,550),TObjetivo));
	
	
	//Camara que seguira al jugador en x, esta fija en y
	m_camara1 = new View;
	m_camara1->setSize(800.f,600.f);
	m_camara1->setCenter(0,300);
	
	//Musica nivel
	MusicaPrincipal.openFromFile("Recursos/Utiles/MPrimerNivel.ogg");
	MusicaPrincipal.setLoop(true);
	MusicaPrincipal.setVolume(volumenFondo);
	MusicaPrincipal.play();
	
	EnemigosFaltantes = new Text;
	EnemigosFaltantes->setFont(*fuente);
	EnemigosFaltantes->setString("Te quedan "+to_string((int)Malosmalosos.size())+" enemigos para matar");

	
	
}


void PrimerNivel::TerminarPartida (Juego & game) {
	//Final 1, el jugador termino el nivel. Final 2 el jugador murio
	if(Jugador->ObtenerSalud()>0){
		Jugador->consultarPuntos()+=100;
		game.SetEscena(new SegundoNivel(Dificultad,Jugador));
	}else{
		game.SetEscena(new Puntaje(Jugador->consultarPuntos()));
	}
}
