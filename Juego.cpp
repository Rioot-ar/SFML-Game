#include "Juego.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <iostream>
#include "Escena.h"
#include "Puntaje.h"
using namespace std;
using namespace sf;
Juego::Juego() : Ventana(VideoMode(800,600),"Despacito 2.exe"){
	Ventana.setFramerateLimit(60);
	Actual = new Menu;
	m_siguiente_escena = nullptr;
}
void Juego::Run(){
	while(Ventana.isOpen()) {

		while(Ventana.pollEvent(e)) {
			if(e.type == Event::Closed){
				Ventana.close();	
			}
		}		
		Actual->Actualizar(*this);
		Actual->Dibujar(Ventana);
		
		if(m_siguiente_escena){
			delete Actual;
			Actual=m_siguiente_escena;
			m_siguiente_escena= nullptr;
		}
	}
}
void Juego::SetEscena(Escena *nueva){
	m_siguiente_escena=nueva;
}
Juego::~Juego(){
	delete Actual;
	delete m_siguiente_escena;
}
