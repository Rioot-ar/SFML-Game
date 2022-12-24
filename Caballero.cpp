#include "Caballero.h"
#include <ctime>
using namespace std;
using namespace sf;

Caballero::Caballero() {
	//Visual
	Apariencia->loadFromFile("Recursos/Personajes/Caballero.png");
	m_sprite.setTexture(*Apariencia);
	m_sprite.setTextureRect(IntRect(0,0,86,109));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2.f,m_sprite.getGlobalBounds().height/2.f);
	m_sprite.setPosition(0,200);
	m_sprite.setScale(0.3,0.3);
	m_ataque->loadFromFile("Recursos/Utiles/AtaqueCaba.png");
	
	//Sonido
	SonidoAtaque.openFromFile("Recursos/Utiles/AtaqueEspada.ogg");
	SonidoAtaque.setVolume(40);
	
	//Normas
	velEst=2;
	Velocidad.x=2;
	Velocidad.y=0;
	Posicion=m_sprite.getPosition();
	Salud = 150;
	Defensa = 5;
	Danio = 15;
	Salto = 5;
	puntos=0;
	PuntosdHabilidad = 1;
	VelocidadAtaque=1;
	habilidadActivada=false;
	
	//Fuente para la vida y habilidad que se mostrara en pantalla
	Font* fuente=new Font;fuente->loadFromFile("Recursos/Utiles/Informacion.ttf");
	TInformacion->setFont(*fuente);	
}


///Cura al personaje y lo hace invencible durante 5 segundos
//HAbInven toma el tiempo en el que la habilidad esta activada
void Caballero::habilidadEspecial ( ) {
	if(PuntosdHabilidad){
		if(Keyboard::isKeyPressed(Keyboard::Key::Q)){
			Salud=9999;
			habilidadActivada=true;
			HAbInven.restart();
			PuntosdHabilidad-=1;
		}
		
	}
	if(habilidadActivada && HAbInven.getElapsedTime().asSeconds()>=5){
		Salud=150;
		habilidadActivada=false;
	}
}

void Caballero::Movimiento ( ) {
	
	if(Keyboard::isKeyPressed(Keyboard::Key::D)){
		//ObstaculoDe se determina en Personaje::Colision
		if(!ObstaculoDe){
			//Animacion del Personaje
			if(timer.getElapsedTime().asSeconds()<=0.3){
				m_sprite.setTextureRect(IntRect(0,0,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.8 && timer.getElapsedTime().asSeconds()>0.3){
				m_sprite.setTextureRect(IntRect(86*1,0,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=1.3 && timer.getElapsedTime().asSeconds()>0.8){
				m_sprite.setTextureRect(IntRect(86*2,0,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.3){timer.restart();}
			}else{
				m_sprite.setTextureRect(IntRect(86*3,0,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.8){timer.restart();}
			}
			//Movimiento
			Posicion.x+=Velocidad.x;
			m_sprite.setPosition(Posicion);
		}
		DirecionX=1;//Lugar al que esta mirando, se usa para determinar la textura del ataque
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Key::A)){
		//ObstaculoIz se determina en Personaje::Colision
		if(!ObstaculoIz){
			//Animacion del Personaje
			if(timer.getElapsedTime().asSeconds()<=0.3){
				m_sprite.setTextureRect(IntRect(86*3,109,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=0.8 && timer.getElapsedTime().asSeconds()>0.3){
				m_sprite.setTextureRect(IntRect(86*4,109,86,109));
			}else if(timer.getElapsedTime().asSeconds()<=1.3 && timer.getElapsedTime().asSeconds()>0.8){
				m_sprite.setTextureRect(IntRect(86*5,109,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.3){timer.restart();}
			}else{
				m_sprite.setTextureRect(IntRect(86*6,109,86,109));
				if(timer.getElapsedTime().asSeconds()>=1.8){timer.restart();}
			}
			//Movimiento
			Posicion.x-=Velocidad.x;
			m_sprite.setPosition(Posicion);
		}
		DirecionX=-1;//Lugar al que esta mirando, se usa para determinar la textura del ataque
	}
	
	///Salto
	//Parado se determina en Personaje::Colision
	if(Parado){
		if(Keyboard::isKeyPressed(Keyboard::Key::W)){
			Velocidad.y=-Salto;
			Posicion.y+=Velocidad.y;
			m_sprite.setPosition(Posicion);
			Parado=false;
		}
	}
}



bool Caballero::Atacar ( ) {
	//Animacion
	if(m_proyectil.Existe()){
		if(DirecionX==1){
			if(m_proyectil.ObtenerDistancia()<=30 && m_proyectil.ObtenerDistancia()>=0){
				m_sprite.setTextureRect(IntRect(86*4,0,86,109));
			}else if(m_proyectil.ObtenerDistancia()<=60 && m_proyectil.ObtenerDistancia()>30){
				m_sprite.setTextureRect(IntRect(86*5,0,86,109));
			}else{
				m_sprite.setTextureRect(IntRect(86*6,0,86,109));
			}
		}else{
			if(m_proyectil.ObtenerDistancia()>=330 && m_proyectil.ObtenerDistancia()<=360){
				m_sprite.setTextureRect(IntRect(86*2,109,86,109));
			}else if(m_proyectil.ObtenerDistancia()<330 && m_proyectil.ObtenerDistancia()>=300){
				m_sprite.setTextureRect(IntRect(86*1,109,86,109));
			}else{
				m_sprite.setTextureRect(IntRect(86*0,109,86,109));
			}
		}
	}
	
	//Ataque
	if(Keyboard::isKeyPressed(Keyboard::Key::Space)){
		if(this->PuedeAtacar()){
			SonidoAtaque.play();
			m_proyectil = Proyectil(0.f,m_ataque,Vector2f(DirecionX,0),Vector2f(m_sprite.getPosition().x,m_sprite.getPosition().y),Danio);
			return true;
		}
	}else{return false;}
	
}

//Informacion que se muestra en en la pantalla de los niveles
Text Caballero::Informacion (unsigned TV ) {
	
	string aux;
	aux="Vida: "+to_string((int)Salud)+"\nPuntos de habilidad: "+to_string(PuntosdHabilidad);
	if(habilidadActivada){
		aux+="\nTiempo de habilidad restante: "+to_string(5-(int)HAbInven.getElapsedTime().asSeconds());
	}
	TInformacion->setCharacterSize(TV*0.015);
	TInformacion->setString(aux);
	TInformacion->setPosition(m_sprite.getPosition().x-TV/2.f,10.f);
	
	return *TInformacion;
}


Caballero::~Caballero ( ) {
	
}
