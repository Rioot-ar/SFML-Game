#include "Mago.h"
#include "Proyectil.h"
#include <cmath>
#include <cstdlib>
using namespace std;
using namespace sf;



Mago::Mago() {
	//Visual
	Apariencia->loadFromFile("Recursos/Personajes/Mago.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setTextureRect(IntRect(0,0,86,109));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2.f,m_sprite.getGlobalBounds().height/2.f);
	m_sprite.setPosition(0,200);
	m_sprite.setScale(0.3,0.3);
	m_ataque->loadFromFile("Recursos/Utiles/AtaqueFuego.png");
	AtaqueEspecial = new Texture;
	AtaqueEspecial->loadFromFile("Recursos/Utiles/AtaqueEspecial.png");
	
	//Sonido
	SonidoAtaque.openFromFile("Recursos/Utiles/AtaqueFuego.ogg");
	
	//Normas
	velEst=2;
	Velocidad.x=2;
	Velocidad.y=0;
	Posicion=m_sprite.getPosition();
	Salud = 50;
	Defensa = 2;
	Danio = 30;
	Salto = 5;
	puntos=0;
	PuntosdHabilidad = 1;
	VelProyectil=10;
	VelocidadAtaque=2;
	
	//Fuente para la vida y habilidad que se mostrara en pantalla
	Font* fuente=new Font;fuente->loadFromFile("Recursos/Utiles/Informacion.ttf");
	TInformacion->setFont(*fuente);	
}


//Realiza un ataque poderoso que se mueve en linea recta
void Mago::habilidadEspecial ( ) {
	if(PuntosdHabilidad){
		if(Keyboard::isKeyPressed(Keyboard::Key::Q)){
			SonidoAtaque.setVolume(100);
			SonidoAtaque.play();
			m_proyectil = Proyectil(600.f,AtaqueEspecial,Vector2f(10*DirecionX,0),Vector2f(m_sprite.getPosition().x+2,m_sprite.getPosition().y),100);
			PuntosdHabilidad=0;
		}
	}
}



bool Mago::Atacar ( ) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Space)){
		Vector2f MovProyectil=CalcularVelocidad(Pendiente,VelProyectil,DirecionX);// Esto se hace para que el proyectil se mueva siempre a la misma velocidad
		if(this->PuedeAtacar()){
			SonidoAtaque.setVolume(40);
			SonidoAtaque.play();
			m_proyectil = Proyectil(200.f,m_ataque,Vector2f(MovProyectil),m_sprite.getPosition(),Danio);
			//Animacion
			if(DirecionX>0){m_sprite.setTextureRect(IntRect(86,0,86,109));}else{m_sprite.setTextureRect(IntRect(86*4,109,86,109));}
			return true;
		}
	}else{return false;}
}


void Mago::Movimiento () {

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

Mago::~Mago ( ) {
	delete AtaqueEspecial;
}

///Verifica la direccion y pendiente del ataque, en este caso "Per" es la posicion del mouse respecto al personaje
//m=y/x
//Tener en cuenta que una pendiente positiva con x>0 e y>0 implica un movimiento positivo en x y negativo en y
void Mago::VerificarDist (Vector2f Per) {
	Pendiente = (Per.y) / (Per.x);
	if(Per.x>=0){DirecionX=1;}
	if(Per.x<0){DirecionX=-1;}
	if(Per.y>=0 && Per.x>=0){Pendiente*=-1;}
	if(Per.y<=0 && Per.x>=0){Pendiente*=-1;}
	
	
}


//Informacion que se muestra en en la pantalla de los niveles
Text Mago::Informacion (unsigned TV ) {
	
	string aux;
	aux="Vida: "+to_string((int)Salud)+"\nPuntos de habilidad: "+to_string(PuntosdHabilidad);
	TInformacion->setCharacterSize(TV*0.015);
	TInformacion->setString(aux);
	TInformacion->setPosition(m_sprite.getPosition().x-TV/2.f,10.f);
	
	return *TInformacion;
}

