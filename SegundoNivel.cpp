#include "SegundoNivel.h"
#include "Personaje.h"
#include "Plataforma.h"
#include "Final.h"
#include "Puntaje.h"
#include "Honderos.h"
#include "Objetivo.h"
#include "Bandidos.h"
#include "Asesino.h"

SegundoNivel::SegundoNivel(char SDificultad, Personaje* J) {
	
	FondoEscena= new Texture;
	FondoE= new Sprite;
	FondoEscena->loadFromFile("Recursos/Estructuras/FondoSegundoNivel.png");
	
	FondoE->setTexture(*FondoEscena);
	FondoE->setOrigin(0,FondoE->getGlobalBounds().height);
	FondoE->setScale(1,TamanioVentana.y/FondoEscena->getSize().y);
	
	Piso= new Texture;
	Piso->loadFromFile("Recursos/Estructuras/PisoSegundoNivel.png");
	
	TObjetivo=new Texture;
	TObjetivo->loadFromFile("Recursos/Estructuras/Puerta.png");
	
	J->VolverInicio();
	Jugador = J;
	Dificultad=SDificultad;
	
	//Piso
	Objetos.push_back(new Plataforma(Vector2f(1520,50),Vector2f(0,576),Piso));
	Objetos.push_back(new Plataforma(Vector2f(1510,50),Vector2f(1620,576),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,50),Vector2f(3240,576),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,50),Vector2f(3365,576),Piso));
	Objetos.push_back(new Plataforma(Vector2f(510,50),Vector2f(3490,576),Piso));


	//Plataformas
	Objetos.push_back(new Plataforma(Vector2f(135,25),Vector2f(100,500),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(400,500),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(700,500),Piso));
	Objetos.push_back(new Plataforma(Vector2f(150,25),Vector2f(835,425),Piso));
	Objetos.push_back(new Plataforma(Vector2f(400,25),Vector2f(1025,305),Piso));
	Objetos.push_back(new Plataforma(Vector2f(400,25),Vector2f(1025,500),Piso));
	Objetos.push_back(new Plataforma(Vector2f(200,25),Vector2f(1780,500),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,25),Vector2f(2130,350),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,25),Vector2f(2205,350),Piso));
	Objetos.push_back(new Plataforma(Vector2f(200,25),Vector2f(2370,425),Piso));
	Objetos.push_back(new Plataforma(Vector2f(300,25),Vector2f(2670,350),Piso));
	
	//Objetivo
	Objetos.push_back(new Objetivo(Vector2f(50,100),Vector2f(4050,576),TObjetivo));
	
	switch(SDificultad){
	case 'N':
		for(int i=1;i<21;i++) { 
			switch(int Tipo=rand()%2){
			case 0:
				Malosmalosos.push_back(new Honderos(Vector2f(250*i,350)));
				break;
			case 1:
				Malosmalosos.push_back(new Bandidos(Vector2f(250*i,350)));
				break;
			}
		}
		break;
	case 'D':
		for(int i=1;i<26;i++) { 
			switch(int Tipo=rand()%3){
			case 0:
				Malosmalosos.push_back(new Honderos(Vector2f(150*i,350)));
				break;
			case 1:
				Malosmalosos.push_back(new Bandidos(Vector2f(150*i,350)));
				break;
			case 2:
				Malosmalosos.push_back(new Asesino(Vector2f(150*i,350)));
				break;
			}
			
		}
		break;
	}
	
	
	
	
	FondoE->setPosition(-600,600);
	m_camara1 = new View;
	m_camara1->setSize(800.f,600.f);
	m_camara1->setCenter(0,300);
	
	MusicaPrincipal.openFromFile("Recursos/Utiles/MSegundoNivel.ogg");
	MusicaPrincipal.setLoop(true);
	MusicaPrincipal.setVolume(50);
	MusicaPrincipal.play();
}


void SegundoNivel::TerminarPartida (Juego & game) {
	
	if(Jugador->ObtenerSalud()>0){
		Jugador->consultarPuntos()+=200;
		game.SetEscena(new Final(Dificultad,Jugador));
	}else{
		game.SetEscena(new Puntaje(Jugador->consultarPuntos()));
	}
	
}

