#ifndef PUNTAJE_H
#define PUNTAJE_H
#include "Escena.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "InputBox.h"
#include <fstream>


struct Puntos{
	char Nombre[20];
	int Puntuacion;
};

class Puntaje : public Escena {
public:
	Puntaje(int PP);
	~Puntaje();
	void Actualizar (Juego & game);
	void Dibujar (sf::RenderWindow & Vent);
private:
	InputBox m_entrada;
	std::string m_Nombre;
	std::fstream Ar;
	int m_Puntos;
	std::vector<Puntos> m_tPuntos;
	sf::Text IngrN, SusP, MostrarNPuntuaciones, TituloPuntuaciones, MostrarPuntuaciones;
};

#endif
