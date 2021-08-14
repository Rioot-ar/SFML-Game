#ifndef ESCENA_H
#define ESCENA_H
#include "Juego.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class Juego;

class Escena {
public:
	Escena();
	virtual void Actualizar(Juego &game) = 0;
	virtual void Dibujar(sf::RenderWindow &Vent) = 0;
	void CambioEscena(sf::RenderWindow &Ventana);
	virtual ~Escena();
protected:
	sf::Sprite* FondoE, *FlechaM;
	sf::Font* fuente;
	sf::Vector2f TamanioVentana;
	sf::Texture* FlechaMenu;
	sf::Texture* FondoEscena;
	sf::Event* e;
	sf::Texture* TEntreEscena;	
	sf::Sprite EntreEscena;
	sf::Music MusicaPrincipal;
};

#endif

