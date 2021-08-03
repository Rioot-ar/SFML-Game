#include "Caballero.h"
#include <ctime>

Caballero::Caballero() {
	Apariencia->loadFromFile("Recursos/Caballero.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width,m_sprite.getGlobalBounds().height/2);
	m_sprite.setPosition(0,200);
	m_sprite.setScale(0.3,0.3);
	m_ataque->loadFromFile("Recursos/AtaqueCaba.png");

	
	//Normas
	Velocidad.x=1.5;
	Velocidad.y=0;
	Posicion=m_sprite.getPosition();
	Salud = 150;
	Defensa = 5;
	Danio = 15;
	Salto = 5;
	puntos=0;
	PuntosdHabilidad = 1;
	habilidadActivada=false;
}

void Caballero::habilidadEspecial ( ) {
	if(PuntosdHabilidad){
		if(Keyboard::isKeyPressed(Keyboard::Key::Q)){
			Salud=9999;
			habilidadActivada=true;
			HAbInven.restart();
			PuntosdHabilidad=0;
		}
		
	}
	if(habilidadActivada && HAbInven.getElapsedTime().asSeconds()>=5){
		Salud=150;
		habilidadActivada=false;
	}
}

void Caballero::Movimiento ( ) {
	if(Keyboard::isKeyPressed(Keyboard::Key::D)){
		Posicion.x+=Velocidad.x;
		m_sprite.setPosition(Posicion);
	}
	if(Keyboard::isKeyPressed(Keyboard::Key::A)){
		Posicion.x-=Velocidad.x;
		m_sprite.setPosition(Posicion);
	}
	
	if(Parado){
		if(Keyboard::isKeyPressed(Keyboard::Key::W)){
			Velocidad.y=-Salto;
			Posicion.y+=Velocidad.y;
			m_sprite.setPosition(Posicion);
			Parado=false;
		}
	}
}


void Caballero::VerificarDist (Vector2f Per) {
	if(Per.x-Posicion.x>=0){
		DirecionX=1;
	}
	if(Per.x-Posicion.x<0){
		DirecionX=-1;
	}
	
}

bool Caballero::Atacar ( ) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Space)){
		if(this->PuedeAtacar()){			
			m_proyectil = Proyectil(50.f,m_ataque,Vector2f(0,m_sprite.getGlobalBounds().height),Vector2f(m_sprite.getPosition().x,m_sprite.getPosition().y),Danio);
			return true;
		}
	}else{return false;}
}

