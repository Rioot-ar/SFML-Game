#ifndef SELECCIONDEPERSONAJE_H
#define SELECCIONDEPERSONAJE_H
#include <SFML/Graphics.hpp>
#include "Juego.h"


class SeleccionDePersonaje : public Escena{
public:
	SeleccionDePersonaje();
	void Actualizar(Juego &game)override;
	void Dibujar(sf::RenderWindow &Vent)override;
	~SeleccionDePersonaje()override;
private:
	bool SeleccionandoDificultad = false;
	char EleccionPersonaje, EleccionDificultad;
	sf::Text Seleccion, TMago, TCaballero, TCazador, Dificultad, Normal, Dificil;
	sf::Texture t_Mago, t_Caballero, t_Cazador;
	sf::Sprite m_Mago, m_Caballero, m_Cazador,FlechaM,FlechaD;
};

#endif

