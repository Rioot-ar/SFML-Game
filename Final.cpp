#include "Final.h"
#include "Plataforma.h"
#include "Personaje.h"
#include "Puntaje.h"

Final::Final(char SDificultad, Personaje* J) {
	
	FondoEscena= new Texture;
	FondoE= new Sprite;
	FondoEscena->loadFromFile("Recursos/FondoNivel.png");
	
	FondoE->setTexture(*FondoEscena);
	FondoE->setOrigin(0,FondoE->getGlobalBounds().height);
	FondoE->setScale(1,TamanioVentana.y/FondoEscena->getSize().y);
	
	J->VolverInicio();
	Jugador= J;
	Dificultad=SDificultad;
	//Objetos
	Objetos.push_back(new Plataforma(Vector2f(10000,50),Vector2f(20,550)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(400,500)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(600,500)));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(1200,500)));

	
	//Jefe
	switch(Dificultad){
	case 'N':
		
		break;
	case 'D':
		for(int i=2;i<3;i++) {  
			Malosmalosos.push_back(new Enemigos(1,50,100,Vector2f(5,0),Vector2f(500,200)));
		}
		break;
	}
	

	
	FondoE->setPosition(-600,600);
	m_camara1 = new View;
	m_camara1->setSize(800.f,600.f);
	m_camara1->setCenter(0,300);
}

void Final::TerminarPartida (Juego & game) {
	Jugador->consultarPuntos()+=400;
	game.SetEscena(new Puntaje(Jugador->consultarPuntos()));
	
}

