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
	void Impacto(){m_sprite=Sprite();}
	void Movimiento();
	~Proyectil();
private:
	float m_rango;
	float m_danio;
	Sprite m_sprite;
	Vector2f m_velocidad, m_posicioninicial;
};
#endif
