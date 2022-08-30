<<<<<<< HEAD
#include "SegundoNivel.h"
#include "Personaje.h"
#include "Plataforma.h"
#include "Final.h"
#include "Puntaje.h"
#include "Honderos.h"
#include "Objetivo.h"
#include "Bandidos.h"
#include "Asesino.h"
#include <iostream>
using namespace std;
using namespace sf;

SegundoNivel::SegundoNivel(char SDificultad, Personaje* J) {
	
	//Fondo del nivel, la escala en x se la deja fija para no perder tanta calidad en imagen
	FondoEscena->loadFromFile("Recursos/Estructuras/FondoSegundoNivel.png");
	FondoE->setTexture(*FondoEscena);
	FondoE->setOrigin(0,FondoE->getGlobalBounds().height);
	FondoE->setScale(1,TamanioVentana.y/FondoEscena->getSize().y);
	FondoE->setPosition(-600,600);
	
	
	J->VolverInicio();
	Jugador = J;
	Dificultad=SDificultad;
	
	//Piso
	Piso= new Texture;
	Piso->loadFromFile("Recursos/Estructuras/PisoSegundoNivel.png");
	Objetos.push_back(new Plataforma(Vector2f(1520,50),Vector2f(0,576),Piso));
	Objetos.push_back(new Plataforma(Vector2f(1510,50),Vector2f(1620,576),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,50),Vector2f(3240,576),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,50),Vector2f(3365,576),Piso));
	Objetos.push_back(new Plataforma(Vector2f(510,50),Vector2f(3490,576),Piso));


	//Plataformas, se utiliza la misma textura que el piso
	Objetos.push_back(new Plataforma(Vector2f(135,25),Vector2f(100,500),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(400,500),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(700,500),Piso));
	Objetos.push_back(new Plataforma(Vector2f(150,25),Vector2f(835,425),Piso));
	Objetos.push_back(new Plataforma(Vector2f(400,25),Vector2f(1025,305),Piso));
	Objetos.push_back(new Plataforma(Vector2f(400,25),Vector2f(1025,500),Piso));
	Objetos.push_back(new Plataforma(Vector2f(200,25),Vector2f(1780,500),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,25),Vector2f(2090,450),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,25),Vector2f(2205,450),Piso));
	Objetos.push_back(new Plataforma(Vector2f(200,25),Vector2f(2320,425),Piso));
	Objetos.push_back(new Plataforma(Vector2f(300,25),Vector2f(2600,350),Piso));
	
	//Objetivo
	TObjetivo=new Texture;
	TObjetivo->loadFromFile("Recursos/Estructuras/Puerta.png");
	Objetos.push_back(new Objetivo(Vector2f(50,100),Vector2f(3950,576),TObjetivo));
	
	//Dificultad, Define numero de enemigos y tipo de enemigos
	switch(Dificultad){
	case 'N':
		for(int i=1;i<21;i++) { 
			switch(int Tipo=rand()%2){
			case 0:
				Malosmalosos.push_back(new Honderos(Vector2f(200*i,350)));
				break;
			case 1:
				Malosmalosos.push_back(new Bandidos(Vector2f(200*i,350)));
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
	
	
	
	
	//Camara que seguira al jugador en x, esta fija en y
	m_camara1 = new View;
	m_camara1->setSize(800.f,600.f);
	m_camara1->setCenter(0,300);
	
	//Musica
	MusicaPrincipal.openFromFile("Recursos/Utiles/MSegundoNivel.ogg");
	MusicaPrincipal.setLoop(true);
	MusicaPrincipal.setVolume(50);
	MusicaPrincipal.play();
	
	
	EnemigosFaltantes = new Text;
	EnemigosFaltantes->setFont(*fuente);
	EnemigosFaltantes->setString("Te quedan "+to_string((int)Malosmalosos.size())+" enemigos para matar");
	
}



void SegundoNivel::TerminarPartida (Juego & game) {
	//Final 1, el jugador termino el nivel. Final 2 el jugador murio
	if(Jugador->ObtenerSalud()>0){
		Jugador->consultarPuntos()+=200;
		game.SetEscena(new Final(Dificultad,Jugador));
	}else{
		game.SetEscena(new Puntaje(Jugador->consultarPuntos()));
	}
	
}

=======
#include "SegundoNivel.h"
#include "Personaje.h"
#include "Plataforma.h"
#include "Final.h"
#include "Puntaje.h"
#include "Honderos.h"
#include "Objetivo.h"
#include "Bandidos.h"
#include "Asesino.h"
#include <iostream>
using namespace std;
using namespace sf;

SegundoNivel::SegundoNivel(char SDificultad, Personaje* J) {
	
	//Fondo del nivel, la escala en x se la deja fija para no perder tanta calidad en imagen
	FondoEscena->loadFromFile("Recursos/Estructuras/FondoSegundoNivel.png");
	FondoE->setTexture(*FondoEscena);
	FondoE->setOrigin(0,FondoE->getGlobalBounds().height);
	FondoE->setScale(1,TamanioVentana.y/FondoEscena->getSize().y);
	FondoE->setPosition(-600,600);
	
	
	J->VolverInicio();
	Jugador = J;
	Dificultad=SDificultad;
	
	//Piso
	Piso= new Texture;
	Piso->loadFromFile("Recursos/Estructuras/PisoSegundoNivel.png");
	Objetos.push_back(new Plataforma(Vector2f(1520,50),Vector2f(0,576),Piso));
	Objetos.push_back(new Plataforma(Vector2f(1510,50),Vector2f(1620,576),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,50),Vector2f(3240,576),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,50),Vector2f(3365,576),Piso));
	Objetos.push_back(new Plataforma(Vector2f(510,50),Vector2f(3490,576),Piso));


	//Plataformas, se utiliza la misma textura que el piso
	Objetos.push_back(new Plataforma(Vector2f(135,25),Vector2f(100,500),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(400,500),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(700,500),Piso));
	Objetos.push_back(new Plataforma(Vector2f(150,25),Vector2f(835,425),Piso));
	Objetos.push_back(new Plataforma(Vector2f(400,25),Vector2f(1025,305),Piso));
	Objetos.push_back(new Plataforma(Vector2f(400,25),Vector2f(1025,500),Piso));
	Objetos.push_back(new Plataforma(Vector2f(200,25),Vector2f(1780,500),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,25),Vector2f(2090,450),Piso));
	Objetos.push_back(new Plataforma(Vector2f(25,25),Vector2f(2205,450),Piso));
	Objetos.push_back(new Plataforma(Vector2f(200,25),Vector2f(2320,425),Piso));
	Objetos.push_back(new Plataforma(Vector2f(300,25),Vector2f(2600,350),Piso));
	
	//Objetivo
	TObjetivo=new Texture;
	TObjetivo->loadFromFile("Recursos/Estructuras/Puerta.png");
	Objetos.push_back(new Objetivo(Vector2f(50,100),Vector2f(3950,576),TObjetivo));
	
	//Dificultad, Define numero de enemigos y tipo de enemigos
	switch(Dificultad){
	case 'N':
		for(int i=1;i<21;i++) { 
			switch(int Tipo=rand()%2){
			case 0:
				Malosmalosos.push_back(new Honderos(Vector2f(200*i,350)));
				break;
			case 1:
				Malosmalosos.push_back(new Bandidos(Vector2f(200*i,350)));
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
	
	
	
	
	//Camara que seguira al jugador en x, esta fija en y
	m_camara1 = new View;
	m_camara1->setSize(800.f,600.f);
	m_camara1->setCenter(0,300);
	
	//Musica
	MusicaPrincipal.openFromFile("Recursos/Utiles/MSegundoNivel.ogg");
	MusicaPrincipal.setLoop(true);
	MusicaPrincipal.setVolume(volumenFondo);
	MusicaPrincipal.play();
	
	
	EnemigosFaltantes = new Text;
	EnemigosFaltantes->setFont(*fuente);
	EnemigosFaltantes->setString("Te quedan "+to_string((int)Malosmalosos.size())+" enemigos para matar");
	
}



void SegundoNivel::TerminarPartida (Juego & game) {
	//Final 1, el jugador termino el nivel. Final 2 el jugador murio
	if(Jugador->ObtenerSalud()>0){
		Jugador->consultarPuntos()+=200;
		game.SetEscena(new Final(Dificultad,Jugador));
	}else{
		game.SetEscena(new Puntaje(Jugador->consultarPuntos()));
	}
	
}

>>>>>>> 04796e6 (Volumen maestro y debug_win32)
