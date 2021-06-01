#include "Niveles.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Mago.h"
#include "Plataforma.h"
#include <iostream>
#include <list>
#include "Castillo.h"
#include "Puntaje.h"
using namespace std;


Niveles::Niveles (char Dificultad, char SPersonaje) {
	
}

void Niveles::Actualizar (Juego & game) {

	//salir al menu
	TamanioVentana = Vector2f(game.Ventana.getSize());
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		game.SetEscena(new Menu);
	}
	Vector2i MousePoss=Mouse::getPosition(game.Ventana);
	//Jugador 
	///Visual
	Jugador->Colision(Objetos);
	Jugador->Movimiento();
	m_camara1->setCenter(Jugador->ObtenerSprite().getPosition().x,TamanioVentana.y/2);

	/// Interacciones

	///Ataque
	Jugador->VerificarDist(Vector2f(MousePoss));
	Jugador->Atacar();
	///Daño 
	for(list<Personaje*>::iterator it=Malosmalosos.begin(); it!=Malosmalosos.end(); ++it ) { 
		if((*it)->RecibirDanio(Jugador->ObtenerProyectil())){
			Jugador->consultarPuntos()+=Jugador->consultarPuntos()+(*it)->consultarPuntos();
			delete *it;
			it=Malosmalosos.erase(it);
		}
	}	
	Jugador->ObtenerProyectil()->Movimiento();

	///Enemigos
	for(list<Personaje*>::iterator it=Malosmalosos.begin(); it!=Malosmalosos.end(); ++it ) {
		(*it)->Colision(Objetos);
		(*it)->VerificarDist(Jugador->ObtenerSprite().getPosition());
		(*it)->Movimiento();
		(*it)->Atacar();
		(*it)->ObtenerProyectil()->Movimiento();
		///Si el Jugador Llega a 0 de Vida
		if(Jugador->RecibirDanio((*it)->ObtenerProyectil())){
			game.SetEscena(new Puntaje(Jugador->consultarPuntos()));
			break;
		}
	}


	///Si el Jugador Llega al Final
	if(Jugador->ObtenerSprite().getGlobalBounds().intersects(Objetos[Objetos.size()-1]->ObtenerForma().getGlobalBounds())){
		Termino=true;
	}
	
	if(Termino){
		this->TerminarPartida(game);
	}
}

void Niveles::Dibujar (RenderWindow & Vent) {
	Vent.clear(Color(200,150,255,255));
	//View en el Personaje
	Vent.setView(*m_camara1);
	//Fondo
	//Dibujo objetos
	for(size_t i=0;i<Objetos.size();i++) { 
		Vent.draw(Objetos[i]->ObtenerForma());
	}

	Vent.draw(Jugador->ObtenerProyectil()->ObtenerForma());

	//Dibujo Jugador
	Vent.draw(Jugador->ObtenerSprite());
	//Dibujo enemigos
	for(list<Personaje*>::iterator it=Malosmalosos.begin();it!=Malosmalosos.end();++it) { 
		Vent.draw((*it)->ObtenerSprite());
		Vent.draw((*it)->ObtenerProyectil()->ObtenerForma());
	}
	Vent.display();
}

Niveles::~Niveles ( ) {
	Jugador= nullptr;
	delete m_camara1;
	delete Jugador;
	delete fuente;
	delete FlechaMenu;
	for( Objeto *p:Objetos ) { 
		delete p;
	}
	for( list<Personaje*>::iterator it=Malosmalosos.begin(); it!=Malosmalosos.end(); ++it ) { 
		delete *it;
	}
}

Niveles::Niveles ( ) {
	
}

