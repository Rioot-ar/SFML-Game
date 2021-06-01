#include "SegundoNivel.h"
#include "Personaje.h"
#include "Plataforma.h"
#include "Castillo.h"

SegundoNivel::SegundoNivel(Personaje* J) {
	Jugador= J;
	J=nullptr;
	
	Objetos.push_back(new Plataforma(Vector2f(10000,50),Vector2f(20,600)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(100,500)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(200,440)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(400,300)));
	Objetos.push_back(new Castillo(Vector2f(800,300),Vector2f(100,400)));
	
	m_camara1 = new View;
	m_camara1->setSize(800.f,600.f);
}


void SegundoNivel::TerminarPartida (Juego & game) {
	
}

