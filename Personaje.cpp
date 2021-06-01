#include "Personaje.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
using namespace std;
using namespace sf;
Personaje::Personaje() {
	Apariencia=new Texture; 
	m_ataque=new Texture;
	Parado=false;
	Obstaculo=false;
}
void Personaje::habilidadEspecial(){
	
}
void Personaje::Movimiento(){

}

void Personaje::Colision(vector<Objeto*> Ob){
	Parado = false;
	Obstaculo = false;
	FloatRect CuaJuR(m_sprite.getGlobalBounds().left+m_sprite.getGlobalBounds().width+1.0,m_sprite.getGlobalBounds().top,1.0,m_sprite.getGlobalBounds().height);
	FloatRect CuaJuL(m_sprite.getGlobalBounds().left-1.0,m_sprite.getGlobalBounds().top,1.0,m_sprite.getGlobalBounds().height);
	FloatRect CuaJuT(m_sprite.getGlobalBounds().left,m_sprite.getGlobalBounds().top-1.0,m_sprite.getGlobalBounds().width,Salto/2);
	for(size_t i=0;i<Ob.size();i++) {
		FloatRect CuadObT(Ob[i]->ObtenerForma().getGlobalBounds().left,Ob[i]->ObtenerForma().getGlobalBounds().top,Ob[i]->ObtenerForma().getGlobalBounds().width,4);;		
		FloatRect CuadObL(Ob[i]->ObtenerForma().getGlobalBounds().left-1.0,Ob[i]->ObtenerForma().getGlobalBounds().top,1,Ob[i]->ObtenerForma().getGlobalBounds().height);
		FloatRect CuadObR(Ob[i]->ObtenerForma().getGlobalBounds().left+Ob[i]->ObtenerForma().getGlobalBounds().width+1,Ob[i]->ObtenerForma().getGlobalBounds().top,1.0,Ob[i]->ObtenerForma().getGlobalBounds().height);
		FloatRect CuadObB(Ob[i]->ObtenerForma().getGlobalBounds().left,Ob[i]->ObtenerForma().getGlobalBounds().top+Ob[i]->ObtenerForma().getGlobalBounds().height+1.0,Ob[i]->ObtenerForma().getGlobalBounds().width,Salto/2);
		if(m_sprite.getGlobalBounds().intersects(CuadObT)){
			Velocidad.y=0;
			Parado = true;
		}
		if(CuaJuR.intersects(CuadObL)|| CuaJuL.intersects(CuadObR)){
			Velocidad.x=0;
			Obstaculo=true;
		}
		if(CuaJuT.intersects(CuadObB)){
			Velocidad.y=0;
			Velocidad.y+=9.8/60;
			m_sprite.setPosition(Posicion);
			Parado = false;
		}
	}
	if(!Obstaculo){Velocidad.x=2;}
	if(!Parado){
		Velocidad.y+=9.8/60;
		Posicion.y+=Velocidad.y;
		m_sprite.setPosition(Posicion);
	}

}


bool Personaje::RecibirDanio (Proyectil *D) {
	if(D->ObtenerForma().getGlobalBounds().intersects(m_sprite.getGlobalBounds())){
		Salud=Salud-(D->ObDanio());
		D->Impacto();
	}

	if(Salud<=0){
		return true;
	}else{return false;}
}

bool Personaje::PuedeAtacar ( ) {
	if(m_puedeatk.getElapsedTime().asSeconds()>=1.5){
		m_puedeatk.restart();
		return true;
	}else{ return false;}
}
Personaje::~Personaje ( ) {

}

void Personaje::VerificarDist (Vector2f Per) {
	
}

