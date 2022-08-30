<<<<<<< HEAD
#ifndef MENU_H
#define MENU_H
#include "Juego.h"


class Menu : public Escena{
public:
	Menu();
	void Actualizar(Juego &game)override;
	void Dibujar(sf::RenderWindow &Vent)override;
	~Menu()override;
private:
	sf::Text Titulo,MenuInicio,MenuOpciones,MenuPuntajes;
};

#endif
=======
#ifndef MENU_H
#define MENU_H
#include "Juego.h"


class Menu : public Escena{
public:
	Menu();
	void Actualizar(Juego &game)override;
	void Dibujar(sf::RenderWindow &Vent)override;
	~Menu()override;
private:
	sf::Text Titulo,MenuInicio,MenuOpciones,MenuPuntajes;
};

#endif
>>>>>>> 04796e6 (Volumen maestro y debug_win32)
