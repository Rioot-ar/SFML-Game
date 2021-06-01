#include "SeleccionDePersonaje.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "Juego.h"
#include "Menu.h"
#include "Niveles.h"
#include "PrimerNivel.h"
using namespace std;
using namespace sf;
SeleccionDePersonaje::SeleccionDePersonaje() {
	TamanioVentana = {800,600};
	
	//Titulo 1----------------------------------------------
	Seleccion.setFont(*fuente);
	Seleccion.setString("Selecciona Tu Clase");
	Seleccion.setCharacterSize(40);
	Seleccion.setOrigin(Seleccion.getGlobalBounds().width/2,0);

	
	//Mago-------------------------------------------------
	t_Mago.loadFromFile("Recursos/Mago.png");
	m_Mago.setTexture(t_Mago);
	m_Mago.setScale(0.5,0.5);
	
	TMago.setFont(*fuente);
	TMago.setCharacterSize(30);
	TMago.setString("Mago");

	
	//Caballero-------------------------------------------
	t_Caballero.loadFromFile("Recursos/Caballero.png");
	m_Caballero.setTexture(t_Caballero);
	m_Caballero.setScale(0.5,0.5);

	
	TCaballero.setFont(*fuente);
	TCaballero.setCharacterSize(30);
	TCaballero.setString("Caballero");

	
	//Cazador----------------------------------------------
	TCazador.setFont(*fuente);
	TCazador.setCharacterSize(30);
	TCazador.setString("Cazador");

	
	t_Cazador.loadFromFile("Recursos/Cazador.png");
	m_Cazador.setTexture(t_Cazador);
	m_Cazador.setScale(0.5,0.5);	

	
	//Titulo 2--------------------------------------------
	Dificultad.setFont(*fuente);
	Dificultad.setCharacterSize(40);
	Dificultad.setString("Selecciona La Dificultad");
	Dificultad.setOrigin(Dificultad.getGlobalBounds().width/2,0);
	
	//Dificultad Normal-----------------------------------
	Normal.setFont(*fuente);
	Normal.setCharacterSize(30);
	Normal.setString("Normal");
	
	//Dificultad Dificil----------------------------------
	Dificil.setFont(*fuente);
	Dificil.setCharacterSize(30);
	Dificil.setString("Dificil");

	
	//Punteros-------------------------------------------
	FlechaM.setTexture(*FlechaMenu);
	FlechaM.setOrigin(FlechaM.getGlobalBounds().width,0);
	FlechaM.setScale(0.3,0.35);
	FlechaM.setPosition(m_Mago.getPosition().x,m_Mago.getPosition().y);
	
	FlechaD.setTexture(*FlechaMenu);
	FlechaD.setOrigin(FlechaD.getGlobalBounds().width,0);
	FlechaD.setScale(0.3,0.35);
	FlechaD.setPosition(Normal.getPosition().x,Normal.getPosition().y);
	
	
}
void SeleccionDePersonaje::Actualizar(Juego &game){
	TamanioVentana = Vector2f(game.Ventana.getSize());
	game.Ventana.setView(View(Vector2f(TamanioVentana.x/2,TamanioVentana.y/2),TamanioVentana));
	Vector2i MousePoss=Mouse::getPosition(game.Ventana);
	Rect<float> mouse(MousePoss.x,MousePoss.y,1,1);
	bool Cambiarescena=false;
	//Actualizar Personaje--------------------------------------
	Seleccion.setPosition(TamanioVentana.x/2,TamanioVentana.y*0.1);
	
	m_Mago.setPosition(TamanioVentana.x*0.09,TamanioVentana.y*0.25);
	TMago.setPosition(m_Mago.getPosition().x+m_Mago.getGlobalBounds().width,m_Mago.getPosition().y);
	
	m_Caballero.setPosition(TamanioVentana.x*0.4,TamanioVentana.y*0.25);
	TCaballero.setPosition(m_Caballero.getPosition().x+m_Caballero.getGlobalBounds().width,m_Caballero.getPosition().y);
	
	m_Cazador.setPosition(TamanioVentana.x*0.75,TamanioVentana.y*0.25);
	TCazador.setPosition(m_Cazador.getPosition().x+m_Cazador.getGlobalBounds().width,m_Cazador.getPosition().y);
	
	//Actualizar Dificultad------------------------------------------
	Dificultad.setPosition(TamanioVentana.x/2,TamanioVentana.y/2);
	Normal.setPosition(TamanioVentana.x*0.25,TamanioVentana.y*0.75);
	Dificil.setPosition(TamanioVentana.x*0.75,TamanioVentana.y*0.75);
	
	//Seleccionando Personaje----------------------------------------
	if(not SeleccionandoDificultad){
		if(TMago.getGlobalBounds().intersects(mouse)){
			FlechaM.setPosition(m_Mago.getPosition().x,m_Mago.getPosition().y);
			if(Mouse::isButtonPressed(Mouse::Left)){
				SeleccionandoDificultad = true;
				EleccionPersonaje = 'M';
			}	
		}
		if(TCaballero.getGlobalBounds().intersects(mouse)){
			FlechaM.setPosition(m_Caballero.getPosition().x,m_Caballero.getPosition().y);
			if(Mouse::isButtonPressed(Mouse::Left)){
				/*SeleccionandoDificultad = true;*/
				EleccionPersonaje = 'C';
			}	
		}
		if(TCazador.getGlobalBounds().intersects(mouse)){
			FlechaM.setPosition(m_Cazador.getPosition().x,m_Cazador.getPosition().y);
			if(Mouse::isButtonPressed(Mouse::Left)){
				/*SeleccionandoDificultad = true;*/
				EleccionPersonaje = 'H';
			}	
		}
		if(Keyboard::isKeyPressed(Keyboard::Key::Return)){
			SeleccionandoDificultad = true;
		}
		if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
			game.SetEscena(new Menu);
		}
	}
	
	//Seleccionando Dificultad-----------------------------
	if(SeleccionandoDificultad){
		if(Normal.getGlobalBounds().intersects(mouse)){
			FlechaD.setPosition(Normal.getPosition().x,Normal.getPosition().y);
			if(Mouse::isButtonPressed(Mouse::Left)){
				EleccionDificultad = 'N';
				Cambiarescena=true;
			}	
		}
		if(Dificil.getGlobalBounds().intersects(mouse)){
			FlechaD.setPosition(Dificil.getPosition().x,Dificil.getPosition().y);
			if(Mouse::isButtonPressed(Mouse::Left)){		
				EleccionDificultad = 'D';
				Cambiarescena=true;
			}	
		}
		if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
			SeleccionandoDificultad = false;
		}
		if(Cambiarescena){
			game.SetEscena(new PrimerNivel(EleccionDificultad,EleccionPersonaje));
		}
	}
}
void SeleccionDePersonaje::Dibujar(RenderWindow &Vent){
	Vent.clear(Color(0,0,0,255));
	Vent.draw(Seleccion);
	Vent.draw(TMago);
	Vent.draw(m_Mago);
	Vent.draw(m_Caballero);
	Vent.draw(TCaballero);
	Vent.draw(TCazador);
	Vent.draw(m_Cazador);
	Vent.draw(FlechaM);
	if(SeleccionandoDificultad){
		Vent.draw(Dificultad);
		Vent.draw(FlechaD);
		Vent.draw(Normal);
		Vent.draw(Dificil);
	}
	Vent.display();
}

SeleccionDePersonaje::~SeleccionDePersonaje ( ) {
	delete fuente;
	delete FlechaMenu;
}

