#include "Niveles.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Mago.h"
#include "Plataforma.h"
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
	
	
	
	//Jugador 
	///Visual
	Jugador->Colision(Objetos);
	Jugador->Movimiento();
	m_camara1->setCenter(Jugador->ObtenerSprite().getPosition().x,TamanioVentana.y/2);
	///Mouse Respecto al personaje
	Vector2i MousePoss=Mouse::getPosition(game.Ventana);
	MousePoss.x=Jugador->ObtenerSprite().getPosition().x+MousePoss.x-TamanioVentana.x/2;


	///Ataque
	Jugador->VerificarDist(Vector2f(MousePoss));
	Jugador->Atacar();
	Jugador->habilidadEspecial();
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
		///Si el Jugador Llega a 0 de Vida Terminar Partida
		if(Jugador->RecibirDanio((*it)->ObtenerProyectil())){
			game.SetEscena(new Puntaje(Jugador->consultarPuntos()));
			break;
		}
	}


	///Objetos.size()-1 el ultimo objeto insertado es el destino del jugador
	///CORREGIR, EN EL FINAL SE TERMINA EN LA PLATAFORMA
	if(Jugador->ObtenerSprite().getGlobalBounds().intersects(Objetos[Objetos.size()-1]->ObtenerForma().getGlobalBounds())){
		Termino=true;
	}
	
	///Otro final posible es que el jugador haya limpiado el nivel
	if(Malosmalosos.empty()){Termino=true;}
	
	if(Termino){
		this->TerminarPartida(game);
		Jugador=nullptr;
	}
}

void Niveles::Dibujar (RenderWindow & Vent) {
	Vent.clear(Color(200,150,255,255));
	//Fondo
	//Dibujo objetos
	for(size_t i=0;i<Objetos.size();i++) { 
		Vent.draw(Objetos[i]->ObtenerForma());
	}
	//Jugador
	if(Jugador){
		Vent.setView(*m_camara1);
		Vent.draw(Jugador->ObtenerProyectil()->ObtenerForma());
		Vent.draw(Jugador->ObtenerSprite());
	}
	//Dibujo enemigos
	for(list<Personaje*>::iterator it=Malosmalosos.begin();it!=Malosmalosos.end();++it) { 
		Vent.draw((*it)->ObtenerSprite());
		Vent.draw((*it)->ObtenerProyectil()->ObtenerForma());
	}
	Vent.display();
}

Niveles::~Niveles ( ) {
	if(Jugador){
		delete Jugador;
	}
	delete m_camara1;
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

