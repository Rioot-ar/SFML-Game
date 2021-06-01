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

PrimerNivel::PrimerNivel(char Dificultad, char SPersonaje) {
	//Dificultad, Define numero de enemigos, tiempo limite y tipo de enemigos
	switch(Dificultad){
	case 'N':
		
		break;
	case 'D':
		for(int i=1;i<10;i++) {  
			Malosmalosos.push_back(new Enemigos(1,50,100,Vector2f(5,5),Vector2f(500*i,200)));
		}
		break;
	}
	//Personaje, define las habilidades y la apariencia del jugador.
	switch(SPersonaje){
	case 'M':
		Jugador = new Mago;
		break;
	case 'C':
		/*Jugador = new Caballero;*/
		break;
	case 'H':
		/*Jugador = new Cazador;*/
		break;
	}
	
	
	//Definir nivel: piso, plataformas.
	
	Objetos.push_back(new Plataforma(Vector2f(10000,50),Vector2f(20,600)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(100,500)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(200,440)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(400,300)));
	Objetos.push_back(new Castillo(Vector2f(800,300),Vector2f(100,400)));
	
	m_camara1 = new View;
	m_camara1->setSize(800.f,600.f);
	
}


void PrimerNivel::TerminarPartida (Juego & game) {
	Jugador->consultarPuntos()+=Jugador->consultarPuntos()+100;
	Personaje* J = Jugador;
	game.SetEscena(new SegundoNivel(J));
}

