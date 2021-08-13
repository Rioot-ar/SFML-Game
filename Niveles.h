#ifndef Niveles_H
#define Niveles_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Personaje.h"
#include "Mago.h"
#include "Objeto.h"
#include <list>
#include "Enemigos.h"
using namespace std;

class Niveles : public Escena {
public:
	Niveles(char SDificultad, char SPersonaje);
	Niveles();
	~Niveles()override;
	virtual void Actualizar (Juego & game);
	virtual void Dibujar (RenderWindow & Vent);
	virtual void TerminarPartida(Juego & game)=0;
protected:
	bool Termino = false;
	Personaje* Jugador;
	View * m_camara1;
	list<Personaje*> Malosmalosos;
	vector<Objeto*> Objetos;
	char Dificultad;
	Texture* Piso;
	Texture* TObjetivo;
	Clock TiempoTranscurrido;
};

#endif

