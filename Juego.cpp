#include "Juego.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"

using namespace std;
using namespace sf;
Juego::Juego() : Ventana(VideoMode(800,600),"Kingdom"){
	Ventana.setFramerateLimit(60);
	Actual = new Menu;
	m_siguiente_escena = nullptr;
}

void Juego::Run(){
	while(Ventana.isOpen()) {
		
		Actual->Actualizar(*this);
		while(Ventana.pollEvent(e)) {
			if(e.type == Event::Closed){
				Ventana.close();	
			}
		}		
		Actual->Dibujar(Ventana);
		
		if(m_siguiente_escena){
			Actual->CambioEscena(Ventana);	
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
