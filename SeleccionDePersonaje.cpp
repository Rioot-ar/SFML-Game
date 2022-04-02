#include "SeleccionDePersonaje.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Juego.h"
#include "Menu.h"
#include "Niveles.h"
#include "PrimerNivel.h"
using namespace std;
using namespace sf;
SeleccionDePersonaje::SeleccionDePersonaje() {
	TamanioVentana = {800,600};

	
	//Fondo de la escena
	FondoEscena->loadFromFile("Recursos/Estructuras/FondoSe.jpg");
	FondoE->setTexture(*FondoEscena);
	FondoE->setPosition(0,0);
	FondoE->setScale(TamanioVentana.x/FondoEscena->getSize().x,TamanioVentana.y/FondoEscena->getSize().y);
	
	///Titulo 1----------------------------------------------
	Seleccion.setFont(*fuente);
	Seleccion.setString("Selecciona Tu Clase");
	Seleccion.setCharacterSize(40);
	Seleccion.setOrigin(Seleccion.getGlobalBounds().width/2,0);

	
	///Mago-------------------------------------------------
	//Imagen
	t_Mago.loadFromFile("Recursos/Personajes/Mago.png");
	m_Mago.setTexture(t_Mago);
	m_Mago.setTextureRect(IntRect(0,0,86,109));
	m_Mago.setScale(0.5,0.5);
	
	//Texto
	TMago.setFont(*fuente);
	TMago.setCharacterSize(30);
	TMago.setString("Mago");

	
	///Caballero-------------------------------------------
	//Imagen
	t_Caballero.loadFromFile("Recursos/Personajes/Caballero.png");
	m_Caballero.setTexture(t_Caballero);
	m_Caballero.setTextureRect(IntRect(0,0,86,109));
	m_Caballero.setScale(0.5,0.5);

	//Texto
	TCaballero.setFont(*fuente);
	TCaballero.setCharacterSize(30);
	TCaballero.setString("Caballero");

	
	///Cazador----------------------------------------------
	//Texto
	TCazador.setFont(*fuente);
	TCazador.setCharacterSize(30);
	TCazador.setString("Cazador");

	//Imagen
	t_Cazador.loadFromFile("Recursos/Personajes/Explorador.png");
	m_Cazador.setTexture(t_Cazador);
	m_Cazador.setTextureRect(IntRect(0,0,86,109));
	m_Cazador.setScale(0.5,0.5);	

	
	///Titulo 2--------------------------------------------
	Dificultad.setFont(*fuente);
	Dificultad.setCharacterSize(40);
	Dificultad.setString("Selecciona La Dificultad");
	Dificultad.setOrigin(Dificultad.getGlobalBounds().width/2,0);
	
	///Dificultad Normal-----------------------------------
	Normal.setFont(*fuente);
	Normal.setCharacterSize(30);
	Normal.setString("Normal");
	
	///Dificultad Dificil----------------------------------
	Dificil.setFont(*fuente);
	Dificil.setCharacterSize(30);
	Dificil.setString("Dificil");

	
	///Flechas-------------------------------------------	
	//Flecha Personajes
	FlechaM.setTexture(*FlechaMenu);
	FlechaM.setOrigin(FlechaM.getGlobalBounds().width,FlechaM.getGlobalBounds().height/2);
	FlechaM.setScale(0.3,0.3);
	FlechaM.setPosition(m_Mago.getPosition().x,m_Mago.getPosition().y);
	//Flecha Dificultad
	FlechaD.setTexture(*FlechaMenu);
	FlechaD.setOrigin(FlechaD.getGlobalBounds().width,FlechaM.getGlobalBounds().height/2);
	FlechaD.setScale(0.3,0.3);
	FlechaD.setPosition(Normal.getPosition().x,Normal.getPosition().y);
	
	//Musica
	MusicaPrincipal.openFromFile("Recursos/Utiles/MSeleccionDePersonaje.ogg");
	MusicaPrincipal.setLoop(true);
	MusicaPrincipal.setVolume(50);
	MusicaPrincipal.play();
	
}
void SeleccionDePersonaje::Actualizar(Juego &game){
	
	
	TamanioVentana = Vector2f(game.Ventana.getSize());
	game.Ventana.setView(View(Vector2f(TamanioVentana.x/2,TamanioVentana.y/2),TamanioVentana));
	
	//Actualizar el fondo de la escena
	FondoE->setScale(TamanioVentana.x/FondoEscena->getSize().x,TamanioVentana.y/FondoEscena->getSize().y);
	
	
	bool Cambiarescena=false;
	
	
	//Actualziar Flechas
	FlechaM.setScale(TamanioVentana.x*0.0005,TamanioVentana.x*0.0005);
	FlechaD.setScale(TamanioVentana.x*0.0005,TamanioVentana.x*0.0005);
	

	
	//Actualizar textos e imagenes de personajes--------------------------------------
	Seleccion.setPosition(TamanioVentana.x/2,TamanioVentana.y*0.1);
	Seleccion.setCharacterSize(TamanioVentana.x*0.05);
	Seleccion.setOrigin(Dificultad.getGlobalBounds().width/2,0);
	
	//Mago
	m_Mago.setPosition(TamanioVentana.x*0.09,TamanioVentana.y*0.30);
	m_Mago.setScale(TamanioVentana.x*0.0006,TamanioVentana.x*0.0006);
	TMago.setCharacterSize(TamanioVentana.x*0.0375);
	TMago.setPosition(m_Mago.getPosition().x+m_Mago.getGlobalBounds().width,m_Mago.getPosition().y);
	
	//Caballero
	m_Caballero.setPosition(TamanioVentana.x*0.4,TamanioVentana.y*0.30);
	m_Caballero.setScale(TamanioVentana.x*0.0006,TamanioVentana.x*0.0006);
	TCaballero.setCharacterSize(TamanioVentana.x*0.0375);
	TCaballero.setPosition(m_Caballero.getPosition().x+m_Caballero.getGlobalBounds().width,m_Caballero.getPosition().y);
	
	//Cazador
	m_Cazador.setPosition(TamanioVentana.x*0.75,TamanioVentana.y*0.30);
	m_Cazador.setScale(TamanioVentana.x*0.0006,TamanioVentana.x*0.0006);
	TCazador.setCharacterSize(TamanioVentana.x*0.0375);
	TCazador.setPosition(m_Cazador.getPosition().x+m_Cazador.getGlobalBounds().width,m_Cazador.getPosition().y);
	
	
	//Actualizar textos de dificultad------------------------------------------
	Dificultad.setCharacterSize(TamanioVentana.x*0.05);
	Dificultad.setPosition(TamanioVentana.x/2,TamanioVentana.y/2);
	Dificultad.setOrigin(Dificultad.getGlobalBounds().width/2,0);
	
	Normal.setCharacterSize(TamanioVentana.x*0.0375);
	Normal.setPosition(TamanioVentana.x*0.25,TamanioVentana.y*0.75);
	
	Dificil.setCharacterSize(TamanioVentana.x*0.0375);
	Dificil.setPosition(TamanioVentana.x*0.75,TamanioVentana.y*0.75);
	
	
	//Mouse en ventana
	Vector2i MousePoss=Mouse::getPosition(game.Ventana);
	Rect<float> mouse(MousePoss.x,MousePoss.y,1,1);
	
	//Seleccionando Personaje----------------------------------------
	if(not SeleccionandoDificultad){
		if(TMago.getGlobalBounds().intersects(mouse)){
			FlechaM.setPosition(m_Mago.getPosition().x,m_Mago.getPosition().y+m_Mago.getGlobalBounds().height/2);
			if(Mouse::isButtonPressed(Mouse::Left)){
				SeleccionandoDificultad = true;
				EleccionPersonaje = 'M';
			}	
		}
		if(TCaballero.getGlobalBounds().intersects(mouse)){
			FlechaM.setPosition(m_Caballero.getPosition().x,m_Caballero.getPosition().y+m_Caballero.getGlobalBounds().height/2);
			if(Mouse::isButtonPressed(Mouse::Left)){
				SeleccionandoDificultad = true;
				EleccionPersonaje = 'C';
			}	
		}
		if(TCazador.getGlobalBounds().intersects(mouse)){
			FlechaM.setPosition(m_Cazador.getPosition().x,m_Cazador.getPosition().y+m_Cazador.getGlobalBounds().height/2);
			if(Mouse::isButtonPressed(Mouse::Left)){
				SeleccionandoDificultad = true;
				EleccionPersonaje = 'H';
			}	
		}
		if(Keyboard::isKeyPressed(Keyboard::Key::Return)){
			SeleccionandoDificultad = true;
		}
		//Vuelve al menu
		if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
			game.SetEscena(new Menu);
		}
	}else{
		///Actualiza la flecha en el caso de que se cambie el tamaño de la ventana
		switch(EleccionPersonaje) {
		case 'M' :
			FlechaM.setPosition(m_Mago.getPosition().x,m_Mago.getPosition().y+m_Mago.getGlobalBounds().height/2);
			break;
		case 'C' :
			FlechaM.setPosition(m_Caballero.getPosition().x,m_Caballero.getPosition().y+m_Caballero.getGlobalBounds().height/2);
			break;
		case 'H' :
			FlechaM.setPosition(m_Cazador.getPosition().x,m_Cazador.getPosition().y+m_Cazador.getGlobalBounds().height/2);
			break;
		}
	}
	
	//Seleccionando Dificultad-----------------------------
	if(SeleccionandoDificultad){
		if(Normal.getGlobalBounds().intersects(mouse)){
			FlechaD.setPosition(Normal.getPosition().x,Normal.getPosition().y+Normal.getGlobalBounds().height/2);
			if(Mouse::isButtonPressed(Mouse::Left)){
				EleccionDificultad = 'N';
				Cambiarescena=true;
			}	
		}
		if(Dificil.getGlobalBounds().intersects(mouse)){
			FlechaD.setPosition(Dificil.getPosition().x,Dificil.getPosition().y+Dificil.getGlobalBounds().height/2);
			if(Mouse::isButtonPressed(Mouse::Left)){		
				EleccionDificultad = 'D';
				Cambiarescena=true;
			}	
		}
		//Vuelve al menu
		if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
			SeleccionandoDificultad = false;
			game.SetEscena(new Menu);
			
		}
		//Si ya termino de elegir comienza el primer nivel.
		if(Cambiarescena){
			game.SetEscena(new PrimerNivel(EleccionDificultad,EleccionPersonaje));
		}
}
	}

void SeleccionDePersonaje::Dibujar(RenderWindow &Vent){
	
	Vent.clear(Color(0,0,0,255));
	Vent.draw(*FondoE);
	Vent.draw(Seleccion);
	Vent.draw(TMago);
	Vent.draw(m_Mago);
	Vent.draw(m_Caballero);
	Vent.draw(TCaballero);
	Vent.draw(TCazador);
	Vent.draw(m_Cazador);
	Vent.draw(FlechaM);
	//Dibujo la seleccion de dificultad solo cuando el personaje ya esta decidido 
	if(SeleccionandoDificultad){
		Vent.draw(Dificultad);
		Vent.draw(FlechaD);
		Vent.draw(Normal);
		Vent.draw(Dificil);
	}
	Vent.display();
}

SeleccionDePersonaje::~SeleccionDePersonaje ( ) {

}

