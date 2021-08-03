#include "Proyectil.h"
#include <cmath>
#include <iostream>
#include "Personaje.h"
using namespace std;

Proyectil::Proyectil(float R, Texture* T,Vector2f V,Vector2f Pi,float D){
	
	m_rango=R;
	m_velocidad=V;
	m_posicioninicial=Pi;
	m_danio=D;
	
	m_sprite.setTexture(*T);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2,m_sprite.getGlobalBounds().height/2);
	m_sprite.setPosition(Pi);
	
}

void Proyectil::Movimiento ( ) {
	float DistRecorrida;
	DistRecorrida = sqrt(pow(m_posicioninicial.x-m_sprite.getPosition().x,2)+pow(m_posicioninicial.y-m_sprite.getPosition().y,2));
	if(DistRecorrida<m_rango){
		m_sprite.rotate(25);
		m_sprite.move(m_velocidad);
	}else{m_sprite=Sprite();}
}


Proyectil::Proyectil ( ) {
	
}
Proyectil::~Proyectil ( ) {

}
