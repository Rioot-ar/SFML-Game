<<<<<<< HEAD
#include "Honderos.h"
using namespace sf;

Honderos::Honderos(Vector2f pos) {
	//Normas
	velEst=1;
	Salud=5;
	Defensa=1;
	Danio=7;
	Velocidad=Vector2f(1,5);
	Posicion=pos;
	VelProyectil=4;
	PersonajeVisto=false;
	puntos = 7;
	VelocidadAtaque=3;
	RangoVision=200.f;
	RangoAtaque=150.f;

	
	//Visual
	m_ataque->loadFromFile("Recursos/Utiles/AtaqueFuego.png");
	Apariencia->loadFromFile("Recursos/Personajes/MagoEn.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setTextureRect(IntRect(0,0,86,109));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width,m_sprite.getGlobalBounds().height/2);
	m_sprite.setScale(0.3,0.3);
	m_sprite.setPosition(Posicion);
}

=======
#include "Honderos.h"
using namespace sf;

Honderos::Honderos(Vector2f pos) {
	//Normas
	velEst=1;
	Salud=5;
	Defensa=1;
	Danio=7;
	Velocidad=Vector2f(1,5);
	Posicion=pos;
	VelProyectil=4;
	PersonajeVisto=false;
	puntos = 7;
	VelocidadAtaque=3;
	RangoVision=200.f;
	RangoAtaque=150.f;

	
	//Visual
	m_ataque->loadFromFile("Recursos/Utiles/AtaqueFuego.png");
	Apariencia->loadFromFile("Recursos/Personajes/MagoEn.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setTextureRect(IntRect(0,0,86,109));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width,m_sprite.getGlobalBounds().height/2);
	m_sprite.setScale(0.3,0.3);
	m_sprite.setPosition(Posicion);
}

>>>>>>> 04796e6 (Volumen maestro y debug_win32)
