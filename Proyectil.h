#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <SFML/Graphics.hpp>


class Proyectil {
public:
	Proyectil(float R, sf::Texture* T,sf::Vector2f V,sf::Vector2f Pi, float D);
	Proyectil();
	sf::Sprite ObtenerForma()const{return m_sprite;}
	float ObDanio()const{return m_danio;}
	void Impacto(){m_sprite=sf::Sprite(); activo=false;}
	bool Existe()const{return activo;}
	float ObtenerDistancia()const{return DistRecorrida;}
	void Movimiento();
	~Proyectil();
private:
	bool activo;
	float m_rango;
	float m_danio;
	float DistRecorrida;
	sf::Sprite m_sprite;
	sf::Vector2f m_velocidad, m_posicioninicial;
};
#endif
