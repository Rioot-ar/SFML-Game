#include "Final.h"
#include "Plataforma.h"
#include "Personaje.h"
#include "Puntaje.h"
#include "Honderos.h"
#include "JefeFinal.h"

Final::Final(char SDificultad, Personaje* J) {
	
	FondoEscena= new Texture;
	FondoE= new Sprite;
	FondoEscena->loadFromFile("Recursos/Estructuras/FondoFinal.png");
	
	Piso= new Texture;
	Piso->loadFromFile("Recursos/Estructuras/PisoSegundoNivel.png");
	
//	TObjetivo=new Texture;
//	TObjetivo->loadFromFile("")
	
	FondoE->setTexture(*FondoEscena);
	FondoE->setOrigin(0,FondoE->getGlobalBounds().height);
	FondoE->setScale(1,TamanioVentana.y/FondoEscena->getSize().y);
	
	J->VolverInicio();
	Jugador= J;
	Dificultad=SDificultad;
	//Piso
	Objetos.push_back(new Plataforma(Vector2f(1500,50),Vector2f(20,550),Piso));

	

	//Plataformas
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(400,475),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(600,475),Piso));
	Objetos.push_back(new Plataforma(Vector2f(100,25),Vector2f(1000,475),Piso));

	
	//Jefe
	Malosmalosos.push_back(new JefeFinal(Vector2f(800,200),Dificultad));

	

	
	FondoE->setPosition(-600,600);
	m_camara1 = new View;
	m_camara1->setSize(800.f,600.f);
	m_camara1->setCenter(0,300);
	
	MusicaPrincipal.openFromFile("Recursos/Utiles/MFinal.ogg");
	MusicaPrincipal.setLoop(true);
	MusicaPrincipal.setVolume(50);
	MusicaPrincipal.play();
}

void Final::TerminarPartida (Juego & game) {
	if(Jugador->ObtenerSalud()>0){
		game.SetEscena(new Puntaje(Jugador->consultarPuntos()+=400));
	}else{
		game.SetEscena(new Puntaje(Jugador->consultarPuntos()));
	}
	
	
	
}

