#include "Cazador.h"
#include <SFML/Graphics.hpp>
#include "Proyectil.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;



Cazador::Cazador() {
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
	velEst=2.5;
	Velocidad.x=2.5;
	Velocidad.y=0;
	Posicion=m_sprite.getPosition();
	Salud = 75;
	Defensa = 2.5;
	Danio = 10;
	Salto = 6;
	puntos=0;
	PuntosdHabilidad = 1;
	VelProyectil=10;
	VelocidadAtaque=1;
	habilidadActivada=false;
	
}

void Cazador::habilidadEspecial ( ) {
	if(PuntosdHabilidad){
		if(Keyboard::isKeyPressed(Keyboard::Key::Q)){
			VelocidadAtaque=0.5;
			VelProyectil=20;
			habilidadActivada=true;
			HAbInven.restart();
			PuntosdHabilidad=0;
		}
		
	}
	if(habilidadActivada && HAbInven.getElapsedTime().asSeconds()>=5){
		VelProyectil=10;
		VelocidadAtaque=1;
		habilidadActivada=false;
	}
}

void Cazador::Movimiento ( ) {
	
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
	}else if(Keyboard::isKeyPressed(Keyboard::Key::A)){
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
	if(Keyboard::isKeyPressed(Keyboard::Key::W)){
		if(Parado){
			Velocidad.y=-Salto;
			Posicion.y+=Velocidad.y;
			m_sprite.setPosition(Posicion);
			Parado=false;
		}
	}
}

void Cazador::VerificarDist (Vector2f Per) {
	Pendiente = (Per.y) / (Per.x);
	if(Per.x>=0){DirecionX=1;}
	if(Per.x<0){DirecionX=-1;}
	if(Per.y>=0 && Per.x>=0){Pendiente*=-1;}
	if(Per.y<=0 && Per.x>=0){Pendiente*=-1;}
}

bool Cazador::Atacar ( ) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Space)){
		Vector2f MovProyectil=CalcularVelocidad(Pendiente,VelProyectil,DirecionX);// Esto se hace para que el proyectil se mueva siempre a la misma velocidad
		if(this->PuedeAtacar()){			
			m_proyectil = Proyectil(200.f,m_ataque,Vector2f(MovProyectil),m_sprite.getPosition(),Danio);
			if(DirecionX>0){m_sprite.setTextureRect(IntRect(86,0,86,109));}else{m_sprite.setTextureRect(IntRect(86*4,109,86,109));}
			return true;
		}
	}else{return false;}
}

