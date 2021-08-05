#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Objeto.h"
#include "Proyectil.h"
#include <list>
using namespace std;
using namespace sf;
class Personaje {
public:
	Personaje();
	virtual bool Atacar()=0;
	Sprite ObtenerSprite(){return m_sprite;}
	virtual void Movimiento()=0;
	virtual void habilidadEspecial()=0;
	void Colision(vector<Objeto*> G);
	virtual bool PuedeAtacar();
	Proyectil* ObtenerProyectil(){return &m_proyectil;}
	bool RecibirDanio(Proyectil *D);
	virtual ~Personaje();
	virtual void VerificarDist(Vector2f Per);
	void VolverInicio(){m_sprite.setPosition(70,200);Posicion=m_sprite.getPosition();}
	int &consultarPuntos(){return puntos;}
protected:
	Texture* Apariencia, *m_ataque;
	Sprite m_sprite;
	float Salud, Defensa, Danio, Salto, Pendiente, DistAPers,DirecionX,velEst;
	Vector2f Posicion,Velocidad;
	bool Parado, ObstaculoDe,ObstaculoIz;
	Clock m_puedeatk,timer;
	Proyectil m_proyectil;
	int puntos, PuntosdHabilidad;
	
};

#endif


