#include "Mago.h"
#include "Proyectil.h"
#include <cmath>
using namespace std;

Vector2f CalcularVelocidad(float Pend, float VELP,int DIR) {
	Vector2f Vec;
	Vec.x=cos(atan(Pend))*VELP*DIR;
	Vec.y=sin(atan(Pend))*VELP;
	return Vec;
}


Mago::Mago() {
	//Visual
	Apariencia->loadFromFile("Recursos/Mago.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width,m_sprite.getGlobalBounds().height/2);
	m_sprite.setPosition(0,200);
	m_sprite.setScale(0.3,0.3);
	m_ataque->loadFromFile("Recursos/ataque.png");
	
	AtaqueEspecial = new Texture;
	AtaqueEspecial->loadFromFile("Recursos/ataqueesp.png");
	
	//Normas
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
			m_proyectil = Proyectil(200.f,m_ataque,Vector2f(MovProyectil),Vector2f(m_sprite.getPosition().x+2,m_sprite.getPosition().y),Danio);
			return true;
		}
	}else{return false;}
}

void Mago::Movimiento () {
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

Mago::~Mago ( ) {

}

//determina direccion y pendiente del ataque.
void Mago::VerificarDist (Vector2f Per) {
	Pendiente = (Per.y-m_sprite.getPosition().y) / (Per.x-m_sprite.getPosition().x);
	if(Per.x-Posicion.x>=0){
		DirecionX=1;
	}
	if(Per.x-Posicion.x<0){
		DirecionX=-1;
		Pendiente*=-1;
	}
	
	
}

