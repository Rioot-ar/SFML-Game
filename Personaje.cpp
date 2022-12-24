#include "Personaje.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <SFML/System.hpp>
using namespace std;
using namespace sf;


Personaje::Personaje() {
	Apariencia=new Texture; 
	m_ataque=new Texture;
	TInformacion= new Text;
	Parado=false;
	ObstaculoDe=false;
	ObstaculoIz=false;
}

void Personaje::habilidadEspecial(){
	
}
void Personaje::Movimiento(){

}


///Verifica si el Personaje esta chocando contra un objeto
void Personaje::Colision(vector<Objeto*> Ob){
	Parado = false;
	ObstaculoDe=false;
	ObstaculoIz=false;
	
	///Hitbox del jugador
	FloatRect CuaJuR(m_sprite.getGlobalBounds().left+m_sprite.getGlobalBounds().width+1.0,m_sprite.getGlobalBounds().top,5.0,m_sprite.getGlobalBounds().height);
	FloatRect CuaJuL(m_sprite.getGlobalBounds().left-1.0,m_sprite.getGlobalBounds().top,-5.0,m_sprite.getGlobalBounds().height);
	FloatRect CuaJuT(m_sprite.getGlobalBounds().left,m_sprite.getGlobalBounds().top-1.0,m_sprite.getGlobalBounds().width,-5.f);
		
	for(size_t i=0;i<Ob.size();i++) {
		///verifica si esta parado sobre algun objeto
		if(m_sprite.getGlobalBounds().intersects(Ob[i]->CuadObT)){
			Velocidad.y=0;
			Parado = true;
		}
		if(m_sprite.getGlobalBounds().intersects(Ob[i]->CuadObB)){
			Velocidad.y=0;
			Velocidad.y+=9.8/60;
			m_sprite.setPosition(Posicion);
			Parado = false;
		}
		
		///Verifica si hay un obstaculo delante
		if(CuaJuR.intersects(Ob[i]->CuadObL)){
			Velocidad.x=-Velocidad.x;
			m_sprite.setPosition(Posicion);
			ObstaculoDe=true;
			Velocidad.x=velEst;
		}else if(CuaJuL.intersects(Ob[i]->CuadObR)){
			Velocidad.x=+Velocidad.x;
			m_sprite.setPosition(Posicion);
			ObstaculoIz=true;
			Velocidad.x=velEst;
		}
	}
	
	
	
	///Gravedad 
	if(!Parado){
		Velocidad.y+=9.8/60;
		Posicion.y+=Velocidad.y;
		m_sprite.setPosition(Posicion);
	}

}

///Procesa los proyectiles que impactan con el personaje. Devuelve "true" si el Personaje murio

bool Personaje::RecibirDanio (Proyectil *D) {
	
	if(D->ObtenerForma().getGlobalBounds().intersects(m_sprite.getGlobalBounds())){
		Salud-=(D->ObDanio())/Defensa;//daño del proyectil sobre defensa del Personaje
		D->Impacto();
	}

	if(Salud<=0){
		return true;
	}else{return false;}
}



///Verifica tiempo entre ataques. "true" si el tiempo entre un ataque y otro es mayor a la velocidad de ataque del personaje
bool Personaje::PuedeAtacar ( ) {
	if(m_puedeatk.getElapsedTime().asSeconds()>=VelocidadAtaque){
		m_puedeatk.restart();
		return true;
	}else{ return false;}
}

Personaje::~Personaje ( ) {
	delete Apariencia;
	delete m_ataque;
	delete TInformacion;
	SonidoAtaque.stop();
}

void Personaje::VerificarDist (Vector2f Per) {

}

///Movimiento de los proyectiles para personajes que son a rango. 
Vector2f Personaje::CalcularVelocidad (float Pend, float VELP, int DIR) {
	Vector2f Vec;
	//"atan(Pend)" es el angulo en radianes de la Pendiente, "VELP" es la velocidad del proyectil, "DIR" la direccion
	Vec.y=sin(atan(Pend))*VELP;
	Vec.x=cos(atan(Pend))*VELP*DIR;
	return Vec;//"Vec" es el movimiento del proyectil, osea m_proyectil.move(Vec);
}

Text Personaje::Informacion (unsigned TV) {
	return Text();
}

