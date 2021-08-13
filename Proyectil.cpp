#include "Proyectil.h"
#include <cmath>
#include "Personaje.h"
#include <iostream>
using namespace std;

Proyectil::Proyectil(float R, Texture* T,Vector2f V,Vector2f Pi,float D){
	
	m_rango=R;
	m_velocidad=V;
	m_posicioninicial=Pi;
	m_danio=D;
	activo=true;
	m_sprite.setTexture(*T);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2,m_sprite.getGlobalBounds().height/2);
	m_sprite.setPosition(Pi);
	m_sprite.rotate(atan(m_velocidad.y/m_velocidad.x)*180/3.14);

	if(m_rango==0){
		m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2,m_sprite.getGlobalBounds().height);
		DistRecorrida=0;
	}else{
		DistRecorrida = 0;
	}
	if(m_velocidad.x==-1){m_sprite.rotate(-1);}
}

void Proyectil::Movimiento ( ) {
	if(m_rango==0){
		if(m_sprite.getRotation()<=90.f && m_sprite.getRotation()>=0.f && m_velocidad.x==1){
			m_sprite.rotate(7);
			DistRecorrida=m_sprite.getRotation();
			
		}else if(m_sprite.getRotation()<=360.f && m_sprite.getRotation()>=270.f && m_velocidad.x==-1){
			m_sprite.rotate(-7);
			DistRecorrida=m_sprite.getRotation();
		}else{m_sprite=Sprite();activo=false;}
	}else{		
		if(DistRecorrida<m_rango){
			m_sprite.move(m_velocidad);
			DistRecorrida = sqrt(pow(m_posicioninicial.x-m_sprite.getPosition().x,2)+pow(m_posicioninicial.y-m_sprite.getPosition().y,2));
		}else{m_sprite=Sprite();activo=false;}
	}
}


Proyectil::Proyectil ( ) {
	activo=false;
}
Proyectil::~Proyectil ( ) {

}
