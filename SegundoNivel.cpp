#include "SegundoNivel.h"
#include "Personaje.h"
#include "Plataforma.h"
#include "Castillo.h"
#include "Final.h"

SegundoNivel::SegundoNivel(char SDificultad, Personaje* J) {
	J->VolverInicio();
	Jugador = J;
	Dificultad=SDificultad;
	Objetos.push_back(new Plataforma(Vector2f(10000,50),Vector2f(20,600)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(100,500)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(200,440)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(400,300)));
	Objetos.push_back(new Castillo(Vector2f(800,300),Vector2f(100,400)));
	
	switch(Dificultad){
	case 'N':
		
		break;
	case 'D':
		for(int i=2;i<3;i++) {  
			Malosmalosos.push_back(new Enemigos(1,50,0,Vector2f(5,5),Vector2f(500*i,200)));
		}
		break;
	}
	
	m_camara1 = new View;
	m_camara1->setSize(800.f,600.f);
}


void SegundoNivel::TerminarPartida (Juego & game) {
	Jugador->consultarPuntos()+=Jugador->consultarPuntos()+200;
	game.SetEscena(new Final(Dificultad,Jugador));
}

