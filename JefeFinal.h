<<<<<<< HEAD
#ifndef JEFEFINAL_H
#define JEFEFINAL_H
#include "Enemigos.h"


class JefeFinal : public Enemigos {
public:
	JefeFinal(sf::Vector2f Posicion, char Dificultad);
	void habilidadEspecial ( );
	sf::Text Informacion(unsigned TV)override;
	~JefeFinal( );
private:
	sf::Clock HabilidadEsp;
	sf::Texture* AtaqueEspecial;
	float VelHabilidad;
};

#endif

=======
#ifndef JEFEFINAL_H
#define JEFEFINAL_H
#include "Enemigos.h"


class JefeFinal : public Enemigos {
public:
	JefeFinal(sf::Vector2f Posicion, char Dificultad);
	void habilidadEspecial ( );
	sf::Text Informacion(unsigned TV)override;
	~JefeFinal( );
private:
	sf::Clock HabilidadEsp;
	sf::Texture* AtaqueEspecial;
	float VelHabilidad;
};

#endif

>>>>>>> 04796e6 (Volumen maestro y debug_win32)
