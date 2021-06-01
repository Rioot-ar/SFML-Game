#include "Mago.h"
#include <vector>
#include <iostream>
#include <tuple>
#include "Proyectil.h"
using namespace std;

Mago::Mago() {
	//Visual
	Apariencia->loadFromFile("Recursos/Mago.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width,m_sprite.getGlobalBounds().height/2);
	m_sprite.setPosition(70,200);
	m_sprite.setScale(0.3,0.3);
	m_ataque->loadFromFile("Recursos/ataque.png");

	//Normas
	Velocidad.x=2;
	Velocidad.y=0;
	Posicion=m_sprite.getPosition();
	Salud = 50;
	Defensa = 2;
	Danio = 25;
	Salto = 5;
	puntos=0;

}
void Mago::habilidadEspecial ( ) {
	
}
bool Mago::Atacar ( ) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Space)){
		if(this->PuedeAtacar()){			
			m_proyectil = Proyectil(200.f,m_ataque,Vector2f(DirecionX*10,0),Vector2f(m_sprite.getPosition().x+2,m_sprite.getPosition().y),Danio);
			return true;
		}
	}else{return false;}
}

void Mago::Movimiento ( ) {
	if(Keyboard::isKeyPressed(Keyboard::Key::D)){
		Posicion.x+=Velocidad.x;
		m_sprite.setPosition(Posicion);
		DirecionX=1;
	}
	if(Keyboard::isKeyPressed(Keyboard::Key::A)){
		Posicion.x-=Velocidad.x;
		m_sprite.setPosition(Posicion);
		DirecionX=-1;
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


Mago::~Mago ( ) {
	delete Apariencia;
	delete m_ataque;
}


void Mago::VerificarDist (Vector2f Per) {
	
}

