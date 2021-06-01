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
	virtual void habilidadEspecial();
	void Colision(vector<Objeto*> G);
	virtual bool PuedeAtacar();
	Proyectil* ObtenerProyectil(){return &m_proyectil;}
	bool RecibirDanio(Proyectil *D);
	virtual ~Personaje();
	virtual void VerificarDist(Vector2f Per);
	int &consultarPuntos(){return puntos;}
protected:
	Texture* Apariencia, *m_ataque;
	Sprite m_sprite;
	float Salud, Defensa, Danio, Salto;
	Vector2f Posicion,Velocidad;
	bool Parado, Obstaculo;
	Clock m_puedeatk;
	Proyectil m_proyectil;
	int puntos;
};

#endif


