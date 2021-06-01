#include "Enemigos.h"
#include <cmath>
#include <iostream>
using namespace std;

Enemigos::Enemigos(float Sa, float De, float Da, Vector2f Ve, Vector2f pos){

	Salud=Sa;
	Defensa=De;
	Danio=Da;
	Velocidad=Ve;
	Posicion=pos;

	PerEstaEnRango=false;
	puntos = 12;
	
	m_ataque->loadFromFile("Recursos/ataque.png");
	Apariencia->loadFromFile("Recursos/Enemigo2.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width,m_sprite.getGlobalBounds().height/2);
	m_sprite.setScale(0.5,0.5);
	m_sprite.setPosition(Posicion);

}
void Enemigos::VerificarDist (Vector2f Per) {
	DistAPers=sqrt(pow(Per.x-m_sprite.getPosition().x,2)+pow(Per.y-m_sprite.getPosition().y,2));
	if(DistAPers<=200.f){
		PerEstaEnRango = true;
	}else{PerEstaEnRango = false;}
	
	Pendiente = (Per.y-m_sprite.getPosition().y)/(Per.x-m_sprite.getPosition().x);
	if(Per.x-m_sprite.getPosition().x>=0){DirecionX=1;}else{DirecionX=-1;}
	
	if((Per.x-m_sprite.getPosition().x)<=0){
		if(Velocidad.x>=0){Velocidad.x=-1*Velocidad.x;}
	}else{
		if(Velocidad.x<=0){Velocidad.x=-1*Velocidad.x;}
	}
}
bool Enemigos::Atacar ( ) {
	if(PerEstaEnRango){
		if(this->PuedeAtacar()){
			m_proyectil=Proyectil(200.f,m_ataque,Vector2f(10*DirecionX,DirecionX*Pendiente*10),Vector2f(m_sprite.getPosition().x+2,m_sprite.getPosition().y),Danio);
			return true;
		}
		
	}else{return false;}
}
void Enemigos::Movimiento(){
	if(PerEstaEnRango){
		Posicion.x+=Velocidad.x;
		m_sprite.setPosition(Posicion);
		
	}
}

Enemigos::~Enemigos ( ) {
	delete Apariencia;
	delete m_ataque;
}

