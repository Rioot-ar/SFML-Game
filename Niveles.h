<<<<<<< HEAD
#ifndef Niveles_H
#define Niveles_H
#include "Escena.h"
#include <vector>
#include "Personaje.h"
#include "Mago.h"
#include "Objeto.h"
#include <list>
#include "Enemigos.h"

class Niveles : public Escena {
public:
	Niveles(char SDificultad, char SPersonaje);
	Niveles();
	~Niveles()override;
	virtual void Actualizar (Juego & game);
	virtual void Dibujar (sf::RenderWindow & Vent);
	virtual void TerminarPartida(Juego & game)=0;
protected:
	bool Termino = false;
	Personaje* Jugador;
	sf::View * m_camara1;
	std::list<Personaje*> Malosmalosos;
	std::vector<Objeto*> Objetos;
	char Dificultad;
	sf::Texture* Piso;
	sf::Texture* TObjetivo;
	sf::Clock TiempoTranscurrido;
	sf::Text* EnemigosFaltantes;
	
};

#endif

=======
#ifndef Niveles_H
#define Niveles_H
#include "Escena.h"
#include <vector>
#include "Personaje.h"
#include "Mago.h"
#include "Objeto.h"
#include <list>
#include "Enemigos.h"

class Niveles : public Escena {
public:
	Niveles(char SDificultad, char SPersonaje);
	Niveles();
	~Niveles()override;
	virtual void Actualizar (Juego & game);
	virtual void Dibujar (sf::RenderWindow & Vent);
	virtual void TerminarPartida(Juego & game)=0;
protected:
	bool Termino = false;
	Personaje* Jugador;
	sf::View * m_camara1;
	std::list<Personaje*> Malosmalosos;
	std::vector<Objeto*> Objetos;
	char Dificultad;
	sf::Texture* Piso;
	sf::Texture* TObjetivo;
	sf::Clock TiempoTranscurrido;
	sf::Text* EnemigosFaltantes;
	
};

#endif

>>>>>>> 04796e6 (Volumen maestro y debug_win32)
