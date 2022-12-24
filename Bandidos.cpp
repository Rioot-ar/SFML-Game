#include "Bandidos.h"

using namespace std;
using namespace sf;

Bandidos::Bandidos(Vector2f pos) {
	
	//normas
	velEst=2;
	Salud=10;
	Defensa=1.5;
	Danio=3;
	Velocidad=Vector2f(2,5);
	Posicion=pos;
	PersonajeVisto=false;
	puntos = 5;
	VelProyectil=1;
	VelocidadAtaque=2;
	RangoVision=200.f;
	RangoAtaque=10.f;
	
	//visual
	m_ataque->loadFromFile("Recursos/Utiles/AtaqueCaba.png");
	Apariencia->loadFromFile("Recursos/Personajes/Bandido.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setTextureRect(IntRect(0,0,86,109));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2,m_sprite.getGlobalBounds().height/2);
	m_sprite.setScale(0.3,0.3);
	m_sprite.setPosition(Posicion);
}


bool Bandidos::Atacar ( ) {
	if(RangoAtaque>=DistAPers){
		if(this->PuedeAtacar()){
			m_proyectil = Proyectil(0.f,m_ataque,Vector2f(DirecionX,0),Vector2f(m_sprite.getPosition().x,m_sprite.getPosition().y),Danio);
			//seleccion de textura, segun el lugar que ataco
			if(DirecionX>0){
				m_sprite.setTextureRect(IntRect(86,0,86,109));
			}else{
				m_sprite.setTextureRect(IntRect(86*4,109,86,109));
			}
			return true;
		}
		
	}else{return false;}
	
}

Bandidos::~Bandidos ( ) {
	
}

