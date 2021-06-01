#ifndef SELECCIONDEPERSONAJE_H
#define SELECCIONDEPERSONAJE_H
#include <SFML/Graphics.hpp>
#include "Juego.h"
using namespace std;
using namespace sf;

class SeleccionDePersonaje : public Escena{
public:
	SeleccionDePersonaje();
	void Actualizar(Juego &game)override;
	void Dibujar(RenderWindow &Vent)override;
	~SeleccionDePersonaje()override;
private:
	bool SeleccionandoDificultad = false;
	char EleccionPersonaje, EleccionDificultad;
	Text Seleccion, TMago, TCaballero, TCazador, Dificultad, Normal, Dificil;
	Texture t_Mago, t_Caballero, t_Cazador;
	Sprite m_Mago, m_Caballero, m_Cazador,FlechaM,FlechaD;
};

#endif

