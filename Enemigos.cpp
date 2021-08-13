#include "Enemigos.h"
#include <cmath>
#include <iostream>
#include "Proyectil.h"
using namespace std;
Enemigos::Enemigos(){

}

///determina si el rango del ataque sera suficiente y se calcula la pendiente con la cual el proyectil se movera. Tambien determina si el jugador esta a la vista para moverse hacia el.
void Enemigos::VerificarDist (Vector2f Per) {
	
	
	DistAPers=sqrt(pow(Per.x-m_sprite.getPosition().x,2)+pow(Per.y-m_sprite.getPosition().y,2));
	
	
	if(DistAPers<=RangoVision){
		PersonajeVisto = true;
	}else{PersonajeVisto = false;}
	
	Pendiente = (Per.y-m_sprite.getPosition().y)/(Per.x-m_sprite.getPosition().x);
	if(Per.x-m_sprite.getPosition().x>=0){
		DirecionX=1;
	}else{
		DirecionX=-1;
		Pendiente*=-1.f;
	}
}


bool Enemigos::Atacar ( ) {
	if(RangoAtaque>=DistAPers){
		if(this->PuedeAtacar() && !m_proyectil.Existe()){
			Vector2f MovProyectil=CalcularVelocidad(Pendiente,VelProyectil,DirecionX);
			m_proyectil=Proyectil(RangoAtaque,m_ataque,Vector2f(MovProyectil),Vector2f(m_sprite.getPosition().x+2,m_sprite.getPosition().y),Danio);
			if(DirecionX>0){m_sprite.setTextureRect(IntRect(86,0,86,109));}else{m_sprite.setTextureRect(IntRect(86*4,109,86,109));}
			return true;
		}
		
	}else{return false;}
}
void Enemigos::Movimiento(){

	if(PersonajeVisto && RangoAtaque<=DistAPers ){
		if(!ObstaculoDe && DirecionX>=0){
			if(timer.getElapsedTime().asSeconds()<=0.3){
				m_sprite.setTextureRect(IntRect(86*2,0,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.6 && timer.getElapsedTime().asSeconds()>0.3){
				m_sprite.setTextureRect(IntRect(86*3,0,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.9 && timer.getElapsedTime().asSeconds()>0.6){
				m_sprite.setTextureRect(IntRect(86*4,0,86,109));
			}else{
				m_sprite.setTextureRect(IntRect(86*5,0,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.3){timer.restart();}
			}
			Posicion.x+=Velocidad.x*DirecionX;
			m_sprite.setPosition(Posicion);
		}
		
		if(!ObstaculoIz && DirecionX<=0){
			if(timer.getElapsedTime().asSeconds()<=0.3){
				m_sprite.setTextureRect(IntRect(86*3,109,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.6 && timer.getElapsedTime().asSeconds()>0.3){
				m_sprite.setTextureRect(IntRect(86*2,109,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.9 && timer.getElapsedTime().asSeconds()>0.6){
				m_sprite.setTextureRect(IntRect(86*1,109,86,109));
			}else{
				m_sprite.setTextureRect(IntRect(86*0,109,86,109));
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

