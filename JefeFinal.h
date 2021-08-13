#ifndef JEFEFINAL_H
#define JEFEFINAL_H
#include "Enemigos.h"

class JefeFinal : public Enemigos {
public:
	JefeFinal(Vector2f Posicion, char Dificultad);
	void habilidadEspecial ( );
private:
	Clock HabilidadEsp;
	Texture* AtaqueEspecial;
	float VelHabilidad;
};

#endif

