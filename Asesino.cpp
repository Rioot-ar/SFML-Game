#include "Asesino.h"
using namespace sf;

Asesino::Asesino(Vector2f pos) {
	
	//Normas
	velEst=1;
	Salud=1;
	Defensa=0;
	Danio=500;
	Velocidad=Vector2f(1,0);
	Posicion=pos;
	VelProyectil=1;
	PersonajeVisto=false;
	puntos = 20;
	VelocidadAtaque=1;
	RangoVision=10.f;
	RangoAtaque=5.f;
	
	//Visual
	m_ataque->loadFromFile("Recursos/Utiles/AtaqueFuego.png");
	Apariencia->loadFromFile("Recursos/Personajes/Bandido.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setTextureRect(IntRect(0,0,86,109));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width,m_sprite.getGlobalBounds().height/2);
	m_sprite.setScale(0.3,0.3);
	m_sprite.setPosition(Posicion);
	m_sprite.setColor(Color(1,1,1,50));
}


Asesino::~Asesino ( ) {
	
}

