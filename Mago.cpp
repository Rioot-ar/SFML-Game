#include "Mago.h"
#include "Proyectil.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

Vector2f CalcularVelocidad(float Pend, float VELP,int DIR) {
	Vector2f Vec;
	Vec.x=cos(atan(Pend))*VELP*DIR;
	Vec.y=sin(atan(Pend))*VELP;
	return Vec;
}


Mago::Mago() {
	//Visual
	Apariencia->loadFromFile("Recursos/Personajes/Mago.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setTextureRect(IntRect(0,0,86,109));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2.f,m_sprite.getGlobalBounds().height/2.f);
	m_sprite.setPosition(0,200);
	m_sprite.setScale(0.3,0.3);
	m_ataque->loadFromFile("Recursos/ataque.png");
	
	
	AtaqueEspecial = new Texture;
	AtaqueEspecial->loadFromFile("Recursos/ataqueesp.png");
	
	//Normas
	velEst=2;
	Velocidad.x=2;
	Velocidad.y=0;
	Posicion=m_sprite.getPosition();
	Salud = 50;
	Defensa = 2;
	Danio = 25;
	Salto = 5;
	puntos=0;
	PuntosdHabilidad = 1;
	VelProyectil=10;
	VelocidadAtaque=2;
	
}


void Mago::habilidadEspecial ( ) {
	if(PuntosdHabilidad){
		if(Keyboard::isKeyPressed(Keyboard::Key::Q)){
			m_proyectil = Proyectil(600.f,AtaqueEspecial,Vector2f(10,0),Vector2f(m_sprite.getPosition().x+2,m_sprite.getPosition().y),100);
			PuntosdHabilidad=0;
		}
		
	}
}


bool Mago::Atacar ( ) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Space)){
		Vector2f MovProyectil=CalcularVelocidad(Pendiente,VelProyectil,DirecionX);// Esto se hace para que el proyectil se mueva siempre a la misma velocidad
		if(this->PuedeAtacar()){			
			m_proyectil = Proyectil(200.f,m_ataque,Vector2f(MovProyectil),m_sprite.getPosition(),Danio);
			if(DirecionX>0){m_sprite.setTextureRect(IntRect(86,0,86,109));}else{m_sprite.setTextureRect(IntRect(86*4,109,86,109));}
			return true;
		}
	}else{return false;}
}

void Mago::Movimiento () {

	if(Keyboard::isKeyPressed(Keyboard::Key::D)){
		if(!ObstaculoDe){
			if(timer.getElapsedTime().asSeconds()<=0.3){
				m_sprite.setTextureRect(IntRect(86*2,0,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.8 && timer.getElapsedTime().asSeconds()>0.3){
				m_sprite.setTextureRect(IntRect(86*3,0,86,109));
			}
			else{
				m_sprite.setTextureRect(IntRect(86*4,0,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.3){timer.restart();}
			}
			Posicion.x+=Velocidad.x;
			m_sprite.setPosition(Posicion);
		}
	}
	if(Keyboard::isKeyPressed(Keyboard::Key::A)){
		if(!ObstaculoIz){
			if(timer.getElapsedTime().asSeconds()<=0.3){
				m_sprite.setTextureRect(IntRect(0,109,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.8 && timer.getElapsedTime().asSeconds()>0.3){
				m_sprite.setTextureRect(IntRect(86*1,109,86,109));
			}
			else{
				m_sprite.setTextureRect(IntRect(86*2,109,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.3){timer.restart();}
			}
			Posicion.x-=Velocidad.x;
			m_sprite.setPosition(Posicion);
		}
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

}

//determina direccion y pendiente del ataque.
void Mago::VerificarDist (Vector2f Per) {
	Pendiente = (Per.y) / (Per.x);
	if(Per.x>=0){DirecionX=1;}
	if(Per.x<0){DirecionX=-1;}
	if(Per.y>=0 && Per.x>=0){Pendiente*=-1;}
	if(Per.y<=0 && Per.x>=0){Pendiente*=-1;}
	
	
}

