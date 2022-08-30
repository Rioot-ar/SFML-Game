<<<<<<< HEAD
#include "Final.h"
#include "Plataforma.h"
#include "Personaje.h"
#include "Puntaje.h"
#include "Honderos.h"
#include "JefeFinal.h"
#include "Objetivo.h"
#include <string>

using namespace sf;
using namespace std;
Final::Final(char SDificultad, Personaje* J) {
	

	
	//Fondo del nivel, la escala en x se la deja fija para no perder tanta calidad en imagen
	FondoEscena->loadFromFile("Recursos/Estructuras/FondoFinal.png");
	FondoE->setTexture(*FondoEscena);
	FondoE->setOrigin(0,FondoE->getGlobalBounds().height);
	FondoE->setScale(1,TamanioVentana.y/FondoEscena->getSize().y);
	FondoE->setPosition(-600,600);
	
	
	//Me llevo al jugador a la escena actual
	J->VolverInicio();
	Jugador= J;
	
	Dificultad=SDificultad;
	
	//Piso
	Piso= new Texture;
	Piso->loadFromFile("Recursos/Estructuras/PisoSegundoNivel.png");
	Objetos.push_back(new Plataforma(Vector2f(1500,50),Vector2f(20,550),Piso));

	

	//Plataformas
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(400,475),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(600,475),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(1000,475),Piso));

	//Objetivo
	TObjetivo=new Texture;
	TObjetivo->loadFromFile("Recursos/Estructuras/Escotilla.png");
	Objetos.push_back(new Objetivo(Vector2f(100,10),Vector2f(1380,550),TObjetivo));
	
	//Jefe
	Malosmalosos.push_back(new JefeFinal(Vector2f(800,200),Dificultad));

	
	
	//Camara que seguira al jugador en x, esta fija en y
	m_camara1 = new View;
	m_camara1->setSize(800.f,600.f);
	m_camara1->setCenter(0,300);
	
	
	//Musica del nivel
	MusicaPrincipal.openFromFile("Recursos/Utiles/MFinal.ogg");
	MusicaPrincipal.setLoop(true);
	MusicaPrincipal.setVolume(50);
	MusicaPrincipal.play();
	
	EnemigosFaltantes = new Text;
	EnemigosFaltantes->setFont(*fuente);
	EnemigosFaltantes->setString("Te quedan "+to_string((int)Malosmalosos.size())+" enemigos para matar");
}



void Final::TerminarPartida (Juego & game) {
	//Final 1, el jugador mato al Jefe. Final 2 el jugador murio
	if(Jugador->ObtenerSalud()>0){
		game.SetEscena(new Puntaje(Jugador->consultarPuntos()+=400));
	}else{
		game.SetEscena(new Puntaje(Jugador->consultarPuntos()));
	}
	
	
	
}

=======
#include "Final.h"
#include "Plataforma.h"
#include "Personaje.h"
#include "Puntaje.h"
#include "Honderos.h"
#include "JefeFinal.h"
#include "Objetivo.h"
#include <string>

using namespace sf;
using namespace std;
Final::Final(char SDificultad, Personaje* J) {
	

	
	//Fondo del nivel, la escala en x se la deja fija para no perder tanta calidad en imagen
	FondoEscena->loadFromFile("Recursos/Estructuras/FondoFinal.png");
	FondoE->setTexture(*FondoEscena);
	FondoE->setOrigin(0,FondoE->getGlobalBounds().height);
	FondoE->setScale(1,TamanioVentana.y/FondoEscena->getSize().y);
	FondoE->setPosition(-600,600);
	
	
	//Me llevo al jugador a la escena actual
	J->VolverInicio();
	Jugador= J;
	
	Dificultad=SDificultad;
	
	//Piso
	Piso= new Texture;
	Piso->loadFromFile("Recursos/Estructuras/PisoSegundoNivel.png");
	Objetos.push_back(new Plataforma(Vector2f(1500,50),Vector2f(20,550),Piso));

	

	//Plataformas
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(400,475),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(600,475),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(1000,475),Piso));

	//Objetivo
	TObjetivo=new Texture;
	TObjetivo->loadFromFile("Recursos/Estructuras/Escotilla.png");
	Objetos.push_back(new Objetivo(Vector2f(100,10),Vector2f(1380,550),TObjetivo));
	
	//Jefe
	Malosmalosos.push_back(new JefeFinal(Vector2f(800,200),Dificultad));

	
	
	//Camara que seguira al jugador en x, esta fija en y
	m_camara1 = new View;
	m_camara1->setSize(800.f,600.f);
	m_camara1->setCenter(0,300);
	
	
	//Musica del nivel
	MusicaPrincipal.openFromFile("Recursos/Utiles/MFinal.ogg");
	MusicaPrincipal.setLoop(true);
	MusicaPrincipal.setVolume(volumenFondo);
	MusicaPrincipal.play();
	
	EnemigosFaltantes = new Text;
	EnemigosFaltantes->setFont(*fuente);
	EnemigosFaltantes->setString("Te quedan "+to_string((int)Malosmalosos.size())+" enemigos para matar");
}



void Final::TerminarPartida (Juego & game) {
	//Final 1, el jugador mato al Jefe. Final 2 el jugador murio
	if(Jugador->ObtenerSalud()>0){
		game.SetEscena(new Puntaje(Jugador->consultarPuntos()+=400));
	}else{
		game.SetEscena(new Puntaje(Jugador->consultarPuntos()));
	}
	
	
	
}

>>>>>>> 04796e6 (Volumen maestro y debug_win32)
