#include "JefeFinal.h"
#include <cstdlib>
using namespace std;
using namespace sf;

JefeFinal::JefeFinal(Vector2f pos,char Dificultad) {
	
	//Visual
	Apariencia->loadFromFile("Recursos/Personajes/Jefe.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setTextureRect(IntRect(0,0,86,109));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2.f,m_sprite.getGlobalBounds().height/2.f);
	m_sprite.setPosition(pos);
	m_ataque->loadFromFile("Recursos/Utiles/AtaqueFuego.png");
	AtaqueEspecial = new Texture;
	AtaqueEspecial->loadFromFile("Recursos/Utiles/AtaqueEspecial.png");
	
	//Normas constantes
	RangoVision=700.f;
	velEst=2;
	Velocidad.x=2;
	Velocidad.y=0;
	VelProyectil=5;
	Posicion=pos;
	VelHabilidad=6;
	VelocidadAtaque=2.5;
	RangoAtaque=600.f;
	//Normas segun dificultad
	switch(Dificultad){
	case 'N':
		Salud = 200;
		Defensa = 2;
		Danio = 10;
		Salto = 5;
		puntos=150;
		break;
	case 'D':
		Salud = 1;
		Defensa = 3;
		Danio = 15;
		Salto = 5;
		puntos=350;
		break;
	}
	
	
}

///Cada 15 segundos el Jefe hace un ataque poderoso y se teletransporta, HabilidadEsp verifica el tiempo
void JefeFinal::habilidadEspecial ( ) {
	if(HabilidadEsp.getElapsedTime().asSeconds()>=15){
		Vector2f MovProyectil=CalcularVelocidad(Pendiente,VelHabilidad,DirecionX);
		m_proyectil = Proyectil(600.f,AtaqueEspecial,Vector2f(MovProyectil),Vector2f(m_sprite.getPosition().x+2,m_sprite.getPosition().y),75);
		//Animacion
		if(DirecionX>0){m_sprite.setTextureRect(IntRect(86,0,86,109));}else{m_sprite.setTextureRect(IntRect(86*4,109,86,109));}
		//Teletransporte
		Posicion=Vector2f(200*(2+(rand()%6)),400);
		m_sprite.setPosition(Posicion);
		m_sprite.setTextureRect(IntRect(0,0,86,109));
		//reiniciar timer
		HabilidadEsp.restart();
	}
	
}


JefeFinal::~JefeFinal ( ) {
	delete AtaqueEspecial;
}

