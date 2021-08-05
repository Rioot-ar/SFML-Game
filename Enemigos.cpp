#include "Enemigos.h"
#include <cmath>
#include <iostream>
using namespace std;
Vector2f CalcularVelocidads(float Pend, float VELP,int DIR) {
	Vector2f Vec;
	Vec.x=cos(atan(Pend))*VELP*DIR;
	Vec.y=sin(atan(Pend))*VELP;
	return Vec;
}

Enemigos::Enemigos(float Sa, float De, float Da, Vector2f Ve, Vector2f pos){
	
	velEst=Ve.x;
	Salud=Sa;
	Defensa=De;
	Danio=Da;
	Velocidad=Ve;
	Posicion=pos;
	VelProyectil=5;
	PerEstaEnRango=false;
	puntos = 12;
	
	m_ataque->loadFromFile("Recursos/ataque.png");
	Apariencia->loadFromFile("Recursos/Personajes/Enemigo2.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setTextureRect(IntRect(0,0,86,109));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width,m_sprite.getGlobalBounds().height/2);
	m_sprite.setScale(0.3,0.3);
	m_sprite.setPosition(Posicion);

}

///determina si el rango del ataque sera suficiente y se calcula la pendiente con la cual el proyectil se movera. Tambien determina si el jugador esta a la vista para moverse hacia el.
void Enemigos::VerificarDist (Vector2f Per) {
	
	
	DistAPers=sqrt(pow(Per.x-m_sprite.getPosition().x,2)+pow(Per.y-m_sprite.getPosition().y,2));
	
	
	if(DistAPers<=200.f&&DistAPers>=50.f){
		PerEstaEnRango = true;
	}else{PerEstaEnRango = false;}
	
	Pendiente = (Per.y-m_sprite.getPosition().y)/(Per.x-m_sprite.getPosition().x);
	if(Per.x-m_sprite.getPosition().x>=0){
		DirecionX=1;
	}else{
		DirecionX=-1;
		Pendiente*=-1.f;
	}
}


bool Enemigos::Atacar ( ) {
	if(PerEstaEnRango){
		if(this->PuedeAtacar()){
			Vector2f MovProyectil=CalcularVelocidads(Pendiente,VelProyectil,DirecionX);
			m_proyectil=Proyectil(200.f,m_ataque,Vector2f(MovProyectil),Vector2f(m_sprite.getPosition().x+2,m_sprite.getPosition().y),Danio);
			if(DirecionX>0){m_sprite.setTextureRect(IntRect(86,0,86,109));}else{m_sprite.setTextureRect(IntRect(86*4,109,86,109));}
			return true;
		}
		
	}else{return false;}
}
void Enemigos::Movimiento(){

	if(PerEstaEnRango){
		if(!ObstaculoDe&&DirecionX<0){
			if(timer.getElapsedTime().asSeconds()<=0.3){
				m_sprite.setTextureRect(IntRect(0,109,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.8 && timer.getElapsedTime().asSeconds()>0.3){
				m_sprite.setTextureRect(IntRect(86*1,109,86,109));
			}
			else{
				m_sprite.setTextureRect(IntRect(86*2,109,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.3){timer.restart();}
			}
			Posicion.x+=Velocidad.x*DirecionX;
			m_sprite.setPosition(Posicion);
		}
		
		if(!ObstaculoIz&&DirecionX>0){
			if(timer.getElapsedTime().asSeconds()<=0.3){
				m_sprite.setTextureRect(IntRect(86*2,0,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.8 && timer.getElapsedTime().asSeconds()>0.3){
				m_sprite.setTextureRect(IntRect(86*3,0,86,109));
			}
			else{
				m_sprite.setTextureRect(IntRect(86*4,0,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.3){timer.restart();}
			}
			Posicion.x+=Velocidad.x*DirecionX;
			m_sprite.setPosition(Posicion);
		}
		
	}
}

Enemigos::~Enemigos ( ) {

}

void Enemigos::habilidadEspecial ( ) {
	
}

