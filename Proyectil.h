#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <SFML/Graphics.hpp>
using namespace sf;
class Proyectil {
public:
	Proyectil(float R, Texture* T,Vector2f V,Vector2f Pi, float D);
	Proyectil();
	Sprite ObtenerForma(){return m_sprite;}
	float ObDanio(){return m_danio;}
	void Impacto(){m_sprite=Sprite(); activo=false;}
	bool Existe(){return activo;}
	float ObtenerDistancia(){return DistRecorrida;}
	void Movimiento();
	~Proyectil();
private:
	bool activo;
	float m_rango;
	float m_danio;
	float DistRecorrida;
	Sprite m_sprite;
	Vector2f m_velocidad, m_posicioninicial;
};
#endif
