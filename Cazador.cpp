#include "Cazador.h"
#include <SFML/Graphics.hpp>
#include "Proyectil.h"
#include <cmath>
#include <cstdlib>

using namespace std;
using namespace sf;


Cazador::Cazador() {
	//Visual
	Apariencia->loadFromFile("Recursos/Personajes/Explorador.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setTextureRect(IntRect(0,0,86,109));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2.f,m_sprite.getGlobalBounds().height/2.f);
	m_sprite.setPosition(0,200);
	m_sprite.setScale(0.3,0.3);
	m_ataque->loadFromFile("Recursos/Utiles/FlechaAtaque.png");

	//Sonido
	SonidoAtaque.openFromFile("Recursos/Utiles/AtaqueArco.ogg");
	SonidoAtaque.setVolume(40);
	
	
	//Normas
	velEst=2.5;
	Velocidad.x=2.5;
	Velocidad.y=0;
	Posicion=m_sprite.getPosition();
	Salud = 75;
	Defensa = 3;
	Danio = 10;
	Salto = 6;
	puntos=0;
	PuntosdHabilidad = 1;
	VelProyectil=10;
	VelocidadAtaque=1;
	habilidadActivada=false;
	//Fuente para la vida y habilidad que se mostrara en pantalla
	Font* fuente=new Font;fuente->loadFromFile("Recursos/Utiles/Informacion.ttf");
	TInformacion->setFont(*fuente);	
	
}

///Aumenta la velocidad de ataque y la del proyectil
//HAbInven toma el tiempo en el que la habilidad esta activada
void Cazador::habilidadEspecial ( ) {
	if(PuntosdHabilidad){
		if(Keyboard::isKeyPressed(Keyboard::Key::Q)){
			VelocidadAtaque=0.5;
			VelProyectil=20;
			habilidadActivada=true;
			HAbInven.restart();
			PuntosdHabilidad=0;
		}
		
	}
	if(habilidadActivada && HAbInven.getElapsedTime().asSeconds()>=5){
		VelProyectil=10;
		VelocidadAtaque=1;
		habilidadActivada=false;
	}
}

void Cazador::Movimiento ( ) {
	
	if(Keyboard::isKeyPressed(Keyboard::Key::D)){
		//ObstaculoDe se determina en Personaje::Colision
		if(!ObstaculoDe){
			//Animacion del Personaje
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
			Posicion.x+=Velocidad.x;
			m_sprite.setPosition(Posicion);
		}
	}else if(Keyboard::isKeyPressed(Keyboard::Key::A)){
		//ObstaculoIz se determina en Personaje::Colision
		if(!ObstaculoIz){
			//Animacion del Personaje
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
			Posicion.x-=Velocidad.x;
			m_sprite.setPosition(Posicion);
		}
	}
	///Salto
	//Parado se determina en Personaje::Colision
	if(Keyboard::isKeyPressed(Keyboard::Key::W)){
		if(Parado){
			Velocidad.y=-Salto;
			Posicion.y+=Velocidad.y;
			m_sprite.setPosition(Posicion);
			Parado=false;
		}
	}
}
///Verifica la direccion y pendiente del ataque, en este caso "Per" es la posicion del mouse respecto al personaje
//m=y/x
//Tener en cuenta que una pendiente positiva con x>0 e y>0 implica un movimiento positivo en x y negativo en y
void Cazador::VerificarDist (Vector2f Per) {
	Pendiente = (Per.y) / (Per.x);
	if(Per.x>=0){DirecionX=1;}
	if(Per.x<0){DirecionX=-1;}
	if(Per.y>=0 && Per.x>=0){Pendiente*=-1;}
	if(Per.y<=0 && Per.x>=0){Pendiente*=-1;}
}


bool Cazador::Atacar ( ) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Space)){
		//CalcularVelocidad() es una funcion de Personaje
		Vector2f MovProyectil=CalcularVelocidad(Pendiente,VelProyectil,DirecionX);// Esto se hace para que el proyectil se mueva siempre a la misma velocidad
		if(this->PuedeAtacar()){	
			SonidoAtaque.play();
			m_proyectil = Proyectil(200.f,m_ataque,Vector2f(MovProyectil),m_sprite.getPosition(),Danio);
			//Animacion de ataque
			if(DirecionX>0){m_sprite.setTextureRect(IntRect(86,0,86,109));}else{m_sprite.setTextureRect(IntRect(86*4,109,86,109));}
			return true;
		}
	}else{return false;}
}

//Informacion que se en en la pantalla de los niveles
Text Cazador::Informacion (unsigned TV ) {
	
	string aux;
	aux="Vida: "+to_string((int)Salud)+"\nPuntos de habilidad: "+to_string(PuntosdHabilidad);
	
	if(habilidadActivada){
		aux+="\nTiempo de habilidad restante: "+to_string(5-(int)HAbInven.getElapsedTime().asSeconds());
	}
	
	TInformacion->setCharacterSize(TV*0.02);
	TInformacion->setString(aux);
	TInformacion->setPosition(m_sprite.getPosition().x-TV/2.f,0.f);
	
	return *TInformacion;
}

Cazador::~Cazador ( ) {
	
}

