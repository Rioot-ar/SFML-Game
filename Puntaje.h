#ifndef PUNTAJE_H
#define PUNTAJE_H
#include "Escena.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "InputBox.h"
#include <fstream>
using namespace std;

struct Puntos{
	char Nombre[20];
	int Puntuacion;
};
class Puntaje : public Escena {
public:
	Puntaje(int PP);
	~Puntaje();
	void Actualizar (Juego & game);
	void Dibujar (RenderWindow & Vent);
private:
	InputBox m_entrada;
	string m_Nombre;
	fstream Ar;
	int m_Puntos;
	vector<Puntos> m_tPuntos;
	RenderWindow *w;
	Text IngrN, SusP, MostrarPuntuaciones, TituloPuntuaciones;
};

#endif
