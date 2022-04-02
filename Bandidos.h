#ifndef BANDIDOS_H
#define BANDIDOS_H
#include "Enemigos.h"

class Bandidos : public Enemigos {
public:
	Bandidos(sf::Vector2f pos);
	bool Atacar ( )override;
	~Bandidos(	);
private:
	
};

#endif

