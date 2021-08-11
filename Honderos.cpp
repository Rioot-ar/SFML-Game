#include "Honderos.h"

Honderos::Honderos(Vector2f pos) {
	velEst=1;
	Salud=1;
	Defensa=50;
	Danio=0;
	Velocidad=Vector2f(1,5);
	Posicion=pos;
	VelProyectil=4;
	PersonajeVisto=false;
	puntos = 10;
	VelocidadAtaque=3;
	RangoVision=200.f;
	RangoAtaque=150.f;
	
	m_ataque->loadFromFile("Recursos/ataque.png");
	Apariencia->loadFromFile("Recursos/Personajes/Enemigo2.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setTextureRect(IntRect(0,0,86,109));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width,m_sprite.getGlobalBounds().height/2);
	m_sprite.setScale(0.3,0.3);
	m_sprite.setPosition(Posicion);
}

