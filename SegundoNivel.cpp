#include "SegundoNivel.h"
#include "Personaje.h"
#include "Plataforma.h"
#include "Castillo.h"
#include "Final.h"
#include "Puntaje.h"

SegundoNivel::SegundoNivel(char SDificultad, Personaje* J) {
	
	FondoEscena= new Texture;
	FondoE= new Sprite;
	FondoEscena->loadFromFile("Recursos/FondoNivel.png");
	
	FondoE->setTexture(*FondoEscena);
	FondoE->setOrigin(0,FondoE->getGlobalBounds().height);
	FondoE->setScale(1,TamanioVentana.y/FondoEscena->getSize().y);
	
	J->VolverInicio();
	Jugador = J;
	Dificultad=SDificultad;
	Objetos.push_back(new Plataforma(Vector2f(10000,50),Vector2f(20,550)));
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
	
	FondoE->setPosition(-200,600);
	m_camara1 = new View;
	m_camara1->setSize(800.f,600.f);
	m_camara1->setCenter(0,300);
}


void SegundoNivel::TerminarPartida (Juego & game) {
	
	if(Jugador->ObtenerSalud()!=0){
		Jugador->consultarPuntos()+=200;
		game.SetEscena(new Final(Dificultad,Jugador));
	}else{
		game.SetEscena(new Puntaje(Jugador->consultarPuntos()));
	}
	
}

