#include "Niveles.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Plataforma.h"
#include <list>
#include "Puntaje.h"
#include <iostream>
using namespace std;
using namespace sf;

Niveles::Niveles (char Dificultad, char SPersonaje) {
	
}



void Niveles::Actualizar (Juego & game) {
	TamanioVentana = Vector2f(game.Ventana.getSize());
	//Salir al menu
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		game.SetEscena(new Menu);
	}
	//Camara que sigue al jugador en x, esta fija en y
	m_camara1->setCenter(Jugador->ObtenerSprite().getPosition().x,m_camara1->getCenter().y);
	
	
	///Jugador
	//Visual
	Jugador->Colision(Objetos);
	Jugador->Movimiento();
	
	//Mouse Respecto al personaje
	Vector2i MousePoss=Mouse::getPosition(game.Ventana);
	MousePoss.x=(MousePoss.x-TamanioVentana.x/2.f)*m_camara1->getSize().x/TamanioVentana.x;//Cambio escala
	MousePoss.y=Jugador->ObtenerSprite().getPosition().y-m_camara1->getSize().y*MousePoss.y/TamanioVentana.y;//

	//Ataque
	Jugador->VerificarDist(Vector2f(MousePoss));
	Jugador->Atacar();
	Jugador->habilidadEspecial();

	///Enemigos
	for(list<Personaje*>::iterator it=Malosmalosos.begin(); it!=Malosmalosos.end(); ++it ) {
		//Verifico si el proyectil del jugador impacta con el enemigo, si lo hace lo elimino y paso al siguiente si existe
		if((*it)->RecibirDanio(Jugador->ObtenerProyectil())){
			Jugador->consultarPuntos()+=(*it)->consultarPuntos();
			delete *it;
			it=Malosmalosos.erase(it);
			continue;
		}
		//Si el enemigo se cae del mapa, muere
		if((*it)->ObtenerSprite().getPosition().y>m_camara1->getSize().y){
			delete *it;
			it=Malosmalosos.erase(it);
			continue;
		}
		
		(*it)->Colision(Objetos);
		(*it)->VerificarDist(Jugador->ObtenerSprite().getPosition());
		(*it)->Movimiento();
		(*it)->habilidadEspecial();
		(*it)->Atacar();
		(*it)->ObtenerProyectil()->Movimiento();
		///Verifico si el proyectil enemigo impacta con el jugador. Ademas si el jugador llega a 0 de vida terminar partida
		if(Jugador->RecibirDanio((*it)->ObtenerProyectil())){
			game.SetEscena(new Puntaje(Jugador->consultarPuntos()));
			break;
		}
	}
	
	
	EnemigosFaltantes->setString("Te quedan "+to_string((int)Malosmalosos.size())+" enemigos para matar");
	EnemigosFaltantes->setCharacterSize(m_camara1->getSize().x*0.02);
	EnemigosFaltantes->setOrigin(EnemigosFaltantes->getGlobalBounds().width/2.f,0);
	EnemigosFaltantes->setPosition(Jugador->ObtenerSprite().getPosition().x,50.f);
	
	Jugador->ObtenerProyectil()->Movimiento();

	///Objetos.size()-1 el ultimo objeto insertado es el destino del jugador
	if(Malosmalosos.empty() && Jugador->ObtenerSprite().getGlobalBounds().intersects(Objetos[Objetos.size()-1]->ObtenerForma()->getGlobalBounds()) && Objetos[Objetos.size()-1]->EsObjetivo()){
		Termino=true;
	}
	
	
	///Jugador se cae del mapa
	if(Jugador->ObtenerSprite().getPosition().y>m_camara1->getSize().y){Jugador->Matar();Termino=true;}
	
	//Verifico si el nivel termino de alguna forma
	if(Termino){
		this->TerminarPartida(game);
		Jugador=nullptr;
	}

}

void Niveles::Dibujar (RenderWindow & Vent) {
	Vent.clear(Color(200,150,255,255));
	//Fondo
	Vent.draw(*FondoE);
	Vent.draw(*EnemigosFaltantes);
	//Dibujo objetos
	for(size_t i=0;i<Objetos.size();i++) { 
		Vent.draw(*Objetos[i]->ObtenerForma());
	}
	//Si hay un jugador entonces lo dibujo
	if(Jugador){
		Vent.setView(*m_camara1);
		Vent.draw(Jugador->Informacion(m_camara1->getSize().x));
		Vent.draw(Jugador->ObtenerProyectil()->ObtenerForma());
		Vent.draw(Jugador->ObtenerSprite());
	}
	//Dibujo enemigos
	for(list<Personaje*>::iterator it=Malosmalosos.begin();it!=Malosmalosos.end();++it) { 
		Vent.draw((*it)->ObtenerSprite());
		Vent.draw((*it)->ObtenerProyectil()->ObtenerForma());
		Vent.draw((*it)->Informacion(m_camara1->getSize().x));
	}
	Vent.display();
}

Niveles::~Niveles ( ) {
	if(Jugador){
		delete Jugador;
	}
	delete m_camara1;
	for( Objeto *p:Objetos ) { 
		delete p;
	}
	for( list<Personaje*>::iterator it=Malosmalosos.begin(); it!=Malosmalosos.end(); ++it ) { 
		delete *it;
	}
	
	delete EnemigosFaltantes;
	delete Piso;
	delete TObjetivo;

}

Niveles::Niveles ( ) {
	
}

