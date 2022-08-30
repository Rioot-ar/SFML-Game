<<<<<<< HEAD
#include "Proyectil.h"
#include <cmath>
#include "Personaje.h"
using namespace std;
using namespace sf;

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

	//si m_rango==0 entonces es un ataque cuerpo a cuerpo, cambio el origen del sprite al "mango" del arma
	if(m_rango==0){
		m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2,m_sprite.getGlobalBounds().height);
		DistRecorrida=0;
		//si el ataque es a la izquierda giro 1 grado, esto es para facilitar luego el movimiento del arma
		if(m_velocidad.x==-1){m_sprite.rotate(-1);}
	}else{
		DistRecorrida = 0;
	}

}


void Proyectil::Movimiento ( ) {
	//Si m_rango==0 solo tengo que girar el proyectil, no moverlo.
	if(m_rango==0){
		//los ataque mele constan de girar el proyectil de 0° a 90° si la velocidad es positiva, y de 360° a 270° si es negativa
		if(m_sprite.getRotation()<=90.f && m_sprite.getRotation()>=0.f && m_velocidad.x==1){
			m_sprite.rotate(7);
			DistRecorrida=m_sprite.getRotation();
		}else if(m_sprite.getRotation()<=360.f && m_sprite.getRotation()>=270.f && m_velocidad.x==-1){
			m_sprite.rotate(-7);
			DistRecorrida=m_sprite.getRotation();
		}else{m_sprite=Sprite();activo=false;}//Cuando cumple el recorrido elimino el sprite y le digo a la clase que ya no hay proyectil activo
	}else{		
		//si la distancia que recorrio el proyectil es menor al rango, sigo moviendolo
		if(DistRecorrida<m_rango){
			m_sprite.move(m_velocidad);
			DistRecorrida = sqrt(pow(m_posicioninicial.x-m_sprite.getPosition().x,2)+pow(m_posicioninicial.y-m_sprite.getPosition().y,2));// distancia entre el punto inicial del proyectil y el recorrido
		}else{m_sprite=Sprite();activo=false;}//Cuando cumple el recorrido elimino el sprite y le digo a la clase que ya no hay proyectil activo
	}
}


Proyectil::Proyectil ( ) {
	activo=false;
}
Proyectil::~Proyectil ( ) {

}
=======
#include "Proyectil.h"
#include <cmath>
#include "Personaje.h"
using namespace std;
using namespace sf;

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

	//si m_rango==0 entonces es un ataque cuerpo a cuerpo, cambio el origen del sprite al "mango" del arma
	if(m_rango==0){
		m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2,m_sprite.getGlobalBounds().height);
		DistRecorrida=0;
		//si el ataque es a la izquierda giro 1 grado, esto es para facilitar luego el movimiento del arma
		if(m_velocidad.x==-1){m_sprite.rotate(-1);}
	}else{
		DistRecorrida = 0;
	}

}


void Proyectil::Movimiento ( ) {
	//Si m_rango==0 solo tengo que girar el proyectil, no moverlo.
	if(m_rango==0){
		//los ataque mele constan de girar el proyectil de 0° a 90° si la velocidad es positiva, y de 360° a 270° si es negativa
		if(m_sprite.getRotation()<=90.f && m_sprite.getRotation()>=0.f && m_velocidad.x==1){
			m_sprite.rotate(7);
			DistRecorrida=m_sprite.getRotation();
		}else if(m_sprite.getRotation()<=360.f && m_sprite.getRotation()>=270.f && m_velocidad.x==-1){
			m_sprite.rotate(-7);
			DistRecorrida=m_sprite.getRotation();
		}else{m_sprite=Sprite();activo=false;}//Cuando cumple el recorrido elimino el sprite y le digo a la clase que ya no hay proyectil activo
	}else{		
		//si la distancia que recorrio el proyectil es menor al rango, sigo moviendolo
		if(DistRecorrida<m_rango){
			m_sprite.move(m_velocidad);
			DistRecorrida = sqrt(pow(m_posicioninicial.x-m_sprite.getPosition().x,2)+pow(m_posicioninicial.y-m_sprite.getPosition().y,2));// distancia entre el punto inicial del proyectil y el recorrido
		}else{m_sprite=Sprite();activo=false;}//Cuando cumple el recorrido elimino el sprite y le digo a la clase que ya no hay proyectil activo
	}
}


Proyectil::Proyectil ( ) {
	activo=false;
}
Proyectil::~Proyectil ( ) {

}
>>>>>>> 04796e6 (Volumen maestro y debug_win32)
