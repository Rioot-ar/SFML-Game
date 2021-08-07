#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include "Juego.h"
using namespace sf;
class Menu : public Escena{
public:
	Menu();
	void Actualizar(Juego &game)override;
	void Dibujar(RenderWindow &Vent)override;
	~Menu()override;
private:
	Text Titulo,MenuInicio,MenuOpciones,MenuPuntajes;
};

#endif
