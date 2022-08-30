<<<<<<< HEAD
#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Objeto.h"
#include "Proyectil.h"
#include <list>
#include <cmath>
#include <SFML/Audio.hpp>


class Personaje {
public:
	Personaje();
	virtual bool Atacar()=0;
	sf::Sprite ObtenerSprite()const{return m_sprite;}
	virtual void Movimiento()=0;
	virtual void habilidadEspecial()=0;
	void Colision(const std::vector<Objeto*>  G);
	virtual bool PuedeAtacar() ;
	Proyectil* ObtenerProyectil(){return &m_proyectil;}
	bool RecibirDanio(Proyectil *D);
	void Matar(){Salud=0;}
	float ObtenerSalud()const{return Salud;}
	virtual ~Personaje();
	virtual void VerificarDist(sf::Vector2f Per);
	void VolverInicio(){
		m_sprite.setPosition(70,200);
		Posicion=m_sprite.getPosition();
	}
	int &consultarPuntos(){return puntos;}
	sf::Vector2f CalcularVelocidad(float Pend, float VELP,int DIR);
	virtual sf::Text Informacion(unsigned TV);
	
protected:
	sf::Texture* Apariencia, *m_ataque;
	sf::Sprite m_sprite;
	float Salud, Defensa, Danio, Salto, Pendiente, DistAPers,DirecionX,VelocidadAtaque,velEst;
	sf::Vector2f Posicion,Velocidad;
	bool Parado, ObstaculoDe,ObstaculoIz;
	sf::Clock m_puedeatk,timer;
	Proyectil m_proyectil;
	sf::Text* TInformacion;
	sf::Music SonidoAtaque;
	int puntos, PuntosdHabilidad;
	
	
};

#endif


=======
#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Objeto.h"
#include "Proyectil.h"
#include <list>
#include <cmath>
#include <SFML/Audio.hpp>


class Personaje {
public:
	Personaje();
	virtual bool Atacar()=0;
	sf::Sprite ObtenerSprite()const{return m_sprite;}
	virtual void Movimiento()=0;
	virtual void habilidadEspecial()=0;
	void Colision(const std::vector<Objeto*>  G);
	virtual bool PuedeAtacar() ;
	Proyectil* ObtenerProyectil(){return &m_proyectil;}
	bool RecibirDanio(Proyectil *D);
	void Matar(){Salud=0;}
	float ObtenerSalud()const{return Salud;}
	virtual ~Personaje();
	virtual void VerificarDist(sf::Vector2f Per);
	void VolverInicio(){
		m_sprite.setPosition(70,200);
		Posicion=m_sprite.getPosition();
	}
	int &consultarPuntos(){return puntos;}
	sf::Vector2f CalcularVelocidad(float Pend, float VELP,int DIR);
	virtual sf::Text Informacion(unsigned TV);
	
protected:
	sf::Texture* Apariencia, *m_ataque;
	sf::Sprite m_sprite;
	float Salud, Defensa, Danio, Salto, Pendiente, DistAPers,DirecionX,VelocidadAtaque,velEst;
	sf::Vector2f Posicion,Velocidad;
	bool Parado, ObstaculoDe,ObstaculoIz;
	sf::Clock m_puedeatk,timer;
	Proyectil m_proyectil;
	sf::Text* TInformacion;
	sf::Music SonidoAtaque;
	int puntos, PuntosdHabilidad;
	
	
};

#endif


>>>>>>> 04796e6 (Volumen maestro y debug_win32)
