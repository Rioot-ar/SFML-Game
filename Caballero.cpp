#include "Caballero.h"
#include <ctime>
using namespace std;

Caballero::Caballero() {
	Apariencia->loadFromFile("Recursos/Personajes/Caballero.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setTextureRect(IntRect(0,0,86,109));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2.f,m_sprite.getGlobalBounds().height/2.f);
	m_sprite.setPosition(0,200);
	m_sprite.setScale(0.3,0.3);
	m_ataque->loadFromFile("Recursos/AtaqueCaba.png");

	
	//Normas
	velEst=1.5;
	Velocidad.x=1.5;
	Velocidad.y=0;
	Posicion=m_sprite.getPosition();
	Salud = 150;
	Defensa = 5;
	Danio = 15;
	Salto = 5;
	puntos=0;
	PuntosdHabilidad = 1;
	VelocidadAtaque=1;
	habilidadActivada=false;
}

void Caballero::habilidadEspecial ( ) {
	if(PuntosdHabilidad){
		if(Keyboard::isKeyPressed(Keyboard::Key::Q)){
			Salud=9999;
			habilidadActivada=true;
			HAbInven.restart();
			PuntosdHabilidad=0;
		}
		
	}
	if(habilidadActivada && HAbInven.getElapsedTime().asSeconds()>=5){
		Salud=150;
		habilidadActivada=false;
	}
}

void Caballero::Movimiento ( ) {
	
	if(Keyboard::isKeyPressed(Keyboard::Key::D)){
		if(!ObstaculoDe){
			if(timer.getElapsedTime().asSeconds()<=0.3){
				m_sprite.setTextureRect(IntRect(0,0,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.8 && timer.getElapsedTime().asSeconds()>0.3){
				m_sprite.setTextureRect(IntRect(86*1,0,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=1.3 && timer.getElapsedTime().asSeconds()>0.8){
				m_sprite.setTextureRect(IntRect(86*2,0,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.3){timer.restart();}
			}else{
				m_sprite.setTextureRect(IntRect(86*3,0,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.8){timer.restart();}
			}
			Posicion.x+=Velocidad.x;
			m_sprite.setPosition(Posicion);
		}
		DirecionX=1;
	}
	if(Keyboard::isKeyPressed(Keyboard::Key::A)){
		if(!ObstaculoIz){
			if(timer.getElapsedTime().asSeconds()<=0.3){
				m_sprite.setTextureRect(IntRect(86*3,109,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.8 && timer.getElapsedTime().asSeconds()>0.3){
				m_sprite.setTextureRect(IntRect(86*4,109,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=1.3 && timer.getElapsedTime().asSeconds()>0.8){
				m_sprite.setTextureRect(IntRect(86*5,109,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.3){timer.restart();}
			}else{
				m_sprite.setTextureRect(IntRect(86*6,109,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.8){timer.restart();}
			}
			Posicion.x-=Velocidad.x;
			m_sprite.setPosition(Posicion);
		}
		DirecionX=-1;
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


void Caballero::VerificarDist (Vector2f Per) {
	
}

bool Caballero::Atacar ( ) {
	if(m_proyectil.Existe()){
		if(DirecionX==1){
			if(m_proyectil.ObtenerDistancia()<=30 && m_proyectil.ObtenerDistancia()>=0){
				m_sprite.setTextureRect(IntRect(86*4,0,86,109));
			}else if(m_proyectil.ObtenerDistancia()<=60 && m_proyectil.ObtenerDistancia()>30){
				m_sprite.setTextureRect(IntRect(86*5,0,86,109));
			}else{
				m_sprite.setTextureRect(IntRect(86*6,0,86,109));
			}
		}else{
			if(m_proyectil.ObtenerDistancia()>=330 && m_proyectil.ObtenerDistancia()<=360){
				m_sprite.setTextureRect(IntRect(86*2,109,86,109));
			}else if(m_proyectil.ObtenerDistancia()<330 && m_proyectil.ObtenerDistancia()>=300){
				m_sprite.setTextureRect(IntRect(86*1,109,86,109));
			}else{
				m_sprite.setTextureRect(IntRect(86*0,109,86,109));
			}
		}
	}
	if(Keyboard::isKeyPressed(Keyboard::Key::Space)){
		if(this->PuedeAtacar()){
			m_proyectil = Proyectil(0.f,m_ataque,Vector2f(DirecionX,m_sprite.getGlobalBounds().height),Vector2f(m_sprite.getPosition().x,m_sprite.getPosition().y),Danio);
			return true;
		}
	}else{return false;}
	
}

