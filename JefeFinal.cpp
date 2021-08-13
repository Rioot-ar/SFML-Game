#include "JefeFinal.h"
#include <cstdlib>
using namespace std;

JefeFinal::JefeFinal(Vector2f pos,char Dificultad) {
	
	//Visual
	Apariencia->loadFromFile("Recursos/Personajes/Jefe.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setTextureRect(IntRect(0,0,86,109));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2.f,m_sprite.getGlobalBounds().height/2.f);
	m_sprite.setPosition(pos);
	//m_sprite.setScale(0.3,0.3);
	m_ataque->loadFromFile("Recursos/Utiles/AtaqueFuego.png");
	
	AtaqueEspecial = new Texture;
	AtaqueEspecial->loadFromFile("Recursos/Utiles/AtaqueEspecial.png");
	RangoVision=700.f;
	velEst=2;
	Velocidad.x=2;
	Velocidad.y=0;
	Posicion=pos;
	VelProyectil=5;
	VelHabilidad=6;
	VelocidadAtaque=2.5;
	RangoAtaque=600.f;
	
	switch(Dificultad){
	case 'N':
		Salud = 200;
		Defensa = 2;
		Danio = 10;
		Salto = 5;
		puntos=150;
		break;
	case 'D':
		Salud = 300;
		Defensa = 3;
		Danio = 15;
		Salto = 5;
		puntos=350;
		break;
	}
	
	
}

void JefeFinal::habilidadEspecial ( ) {
	if(HabilidadEsp.getElapsedTime().asSeconds()>=15){
		Vector2f MovProyectil=CalcularVelocidad(Pendiente,VelHabilidad,DirecionX);
		m_proyectil = Proyectil(600.f,AtaqueEspecial,Vector2f(MovProyectil),Vector2f(m_sprite.getPosition().x+2,m_sprite.getPosition().y),75);
		if(DirecionX>0){m_sprite.setTextureRect(IntRect(86,0,86,109));}else{m_sprite.setTextureRect(IntRect(86*4,109,86,109));}
		Posicion=Vector2f(200*(2+(rand()%6)),400);
		m_sprite.setPosition(Posicion);
		m_sprite.setTextureRect(IntRect(0,0,86,109));
		HabilidadEsp.restart();
	}
	
}

