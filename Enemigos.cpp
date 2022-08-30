<<<<<<< HEAD
#include "Enemigos.h"
#include <cmath>
#include "Proyectil.h"
using namespace sf;
using namespace std;
Enemigos::Enemigos(){

}

///determina si el rango del ataque sera suficiente y se calcula la pendiente con la cual el proyectil se movera. Tambien determina si el jugador esta a la vista para moverse hacia el.
//Per es la posicion del Jugador
void Enemigos::VerificarDist (Vector2f Per) {
	
	//Distancia
	DistAPers=sqrt(pow(Per.x-m_sprite.getPosition().x,2)+pow(Per.y-m_sprite.getPosition().y,2));
	
	//Verifica si el Jugador esta a la vista
	if(DistAPers<=RangoVision){
		PersonajeVisto = true;
	}else{PersonajeVisto = false;}
	
	//Calcula la pendiente del ataque m=(y2-y1)/(x2-x1)
	Pendiente = (Per.y-m_sprite.getPosition().y)/(Per.x-m_sprite.getPosition().x);
	if(Per.x-m_sprite.getPosition().x>=0){
		DirecionX=1;
	}else{
		DirecionX=-1;
		Pendiente*=-1.f;
	}
}


bool Enemigos::Atacar ( ) {
	if(RangoAtaque>=DistAPers){
		if(this->PuedeAtacar() && !m_proyectil.Existe()){
			Vector2f MovProyectil=CalcularVelocidad(Pendiente,VelProyectil,DirecionX);// Calcula velocidad del proyectil
			m_proyectil=Proyectil(RangoAtaque,m_ataque,Vector2f(MovProyectil),Vector2f(m_sprite.getPosition().x+2,m_sprite.getPosition().y),Danio);
			//Animacion de ataque
			if(DirecionX>0){
				m_sprite.setTextureRect(IntRect(86,0,86,109));
			}else{
				m_sprite.setTextureRect(IntRect(86*4,109,86,109));
			}
			return true;
		}
		
	}else{return false;}
}

void Enemigos::Movimiento(){
	
	//Simpre que el personaje este a la vista y su rango de ataque no sea suficiente se mueve hacia el Jugador
	if(PersonajeVisto && RangoAtaque<=DistAPers ){
		
		//ObstaculoDe se determina en Personaje::Colision
		if(!ObstaculoDe && DirecionX>=0){
			//Animacion
			if(timer.getElapsedTime().asSeconds()<=0.3){
				m_sprite.setTextureRect(IntRect(86*2,0,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.6 && timer.getElapsedTime().asSeconds()>0.3){
				m_sprite.setTextureRect(IntRect(86*3,0,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.9 && timer.getElapsedTime().asSeconds()>0.6){
				m_sprite.setTextureRect(IntRect(86*4,0,86,109));
			}else{
				m_sprite.setTextureRect(IntRect(86*5,0,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.3){timer.restart();}
			}
			//Movimiento
			Posicion.x+=Velocidad.x*DirecionX;
			m_sprite.setPosition(Posicion);
		}
		
		//ObstaculoIz se determina en Personaje::Colision
		if(!ObstaculoIz && DirecionX<=0){
			//Animacion
			if(timer.getElapsedTime().asSeconds()<=0.3){
				m_sprite.setTextureRect(IntRect(86*3,109,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.6 && timer.getElapsedTime().asSeconds()>0.3){
				m_sprite.setTextureRect(IntRect(86*2,109,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.9 && timer.getElapsedTime().asSeconds()>0.6){
				m_sprite.setTextureRect(IntRect(86*1,109,86,109));
			}else{
				m_sprite.setTextureRect(IntRect(86*0,109,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.3){timer.restart();}
			}
			//Movimiento
			Posicion.x+=Velocidad.x*DirecionX;
			m_sprite.setPosition(Posicion);
		}
		
	}
}

Enemigos::~Enemigos ( ) {

}

void Enemigos::habilidadEspecial ( ) {
	
}

=======
#include "Enemigos.h"
#include <cmath>
#include "Proyectil.h"
using namespace sf;
using namespace std;
Enemigos::Enemigos(){

}

///determina si el rango del ataque sera suficiente y se calcula la pendiente con la cual el proyectil se movera. Tambien determina si el jugador esta a la vista para moverse hacia el.
//Per es la posicion del Jugador
void Enemigos::VerificarDist (Vector2f Per) {
	
	//Distancia
	DistAPers=sqrt(pow(Per.x-m_sprite.getPosition().x,2)+pow(Per.y-m_sprite.getPosition().y,2));
	
	//Verifica si el Jugador esta a la vista
	if(DistAPers<=RangoVision){
		PersonajeVisto = true;
	}else{PersonajeVisto = false;}
	
	//Calcula la pendiente del ataque m=(y2-y1)/(x2-x1)
	Pendiente = (Per.y-m_sprite.getPosition().y)/(Per.x-m_sprite.getPosition().x);
	if(Per.x-m_sprite.getPosition().x>=0){
		DirecionX=1;
	}else{
		DirecionX=-1;
		Pendiente*=-1.f;
	}
}


bool Enemigos::Atacar ( ) {
	if(RangoAtaque>=DistAPers){
		if(this->PuedeAtacar() && !m_proyectil.Existe()){
			Vector2f MovProyectil=CalcularVelocidad(Pendiente,VelProyectil,DirecionX);// Calcula velocidad del proyectil
			m_proyectil=Proyectil(RangoAtaque,m_ataque,Vector2f(MovProyectil),Vector2f(m_sprite.getPosition().x+2,m_sprite.getPosition().y),Danio);
			//Animacion de ataque
			if(DirecionX>0){
				m_sprite.setTextureRect(IntRect(86,0,86,109));
			}else{
				m_sprite.setTextureRect(IntRect(86*4,109,86,109));
			}
			return true;
		}
		
	}else{return false;}
}

void Enemigos::Movimiento(){
	
	//Simpre que el personaje este a la vista y su rango de ataque no sea suficiente se mueve hacia el Jugador
	if(PersonajeVisto && RangoAtaque<=DistAPers ){
		
		//ObstaculoDe se determina en Personaje::Colision
		if(!ObstaculoDe && DirecionX>=0){
			//Animacion
			if(timer.getElapsedTime().asSeconds()<=0.3){
				m_sprite.setTextureRect(IntRect(86*2,0,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.6 && timer.getElapsedTime().asSeconds()>0.3){
				m_sprite.setTextureRect(IntRect(86*3,0,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.9 && timer.getElapsedTime().asSeconds()>0.6){
				m_sprite.setTextureRect(IntRect(86*4,0,86,109));
			}else{
				m_sprite.setTextureRect(IntRect(86*5,0,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.3){timer.restart();}
			}
			//Movimiento
			Posicion.x+=Velocidad.x*DirecionX;
			m_sprite.setPosition(Posicion);
		}
		
		//ObstaculoIz se determina en Personaje::Colision
		if(!ObstaculoIz && DirecionX<=0){
			//Animacion
			if(timer.getElapsedTime().asSeconds()<=0.3){
				m_sprite.setTextureRect(IntRect(86*3,109,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.6 && timer.getElapsedTime().asSeconds()>0.3){
				m_sprite.setTextureRect(IntRect(86*2,109,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.9 && timer.getElapsedTime().asSeconds()>0.6){
				m_sprite.setTextureRect(IntRect(86*1,109,86,109));
			}else{
				m_sprite.setTextureRect(IntRect(86*0,109,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.3){timer.restart();}
			}
			//Movimiento
			Posicion.x+=Velocidad.x*DirecionX;
			m_sprite.setPosition(Posicion);
		}
		
	}
}

Enemigos::~Enemigos ( ) {

}

void Enemigos::habilidadEspecial ( ) {
	
}

>>>>>>> 04796e6 (Volumen maestro y debug_win32)
