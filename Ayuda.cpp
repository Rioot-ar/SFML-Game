#include "Ayuda.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"

Ayuda::Ayuda() {
	Vector2f TamanioVentana = {800,600};
	
	//Texto Controles--------------------------------
	ControlesTitulo.setFont(*fuente);
	ControlesTitulo.setCharacterSize(55);
	ControlesTitulo.setString("Controles\n");

	
	ControlesContenido.setFont(*fuente);
	ControlesContenido.setCharacterSize(45);
	ControlesContenido.setString("Para Saltar Presione    W\n\nPara Moverse Utilize Las Teclas    A y S\n\nPara Atacar Presione Espacio\n\nPara Utilizar La Habilidad Especial Presione Q");

	
	//Texto Dificultad---------------------------------------
	DificultadTitulo.setFont(*fuente);
	DificultadTitulo.setCharacterSize(55);
	DificultadTitulo.setString("Dificultad\n");

	
	DificultadContenido.setFont(*fuente);
	DificultadContenido.setCharacterSize(45);
	DificultadContenido.setString("Nada Aun");

	
	//Texto Personajes---------------------------
	PersonajesTitulo.setFont(*fuente);
	PersonajesTitulo.setCharacterSize(55);
	PersonajesTitulo.setString("Personajes\n");

	
	PersonajesContenido.setFont(*fuente);
	PersonajesContenido.setCharacterSize(45);
	PersonajesContenido.setString("Caballero: Aguanta mucho\n\nCazador: Pega rapido\n\nMago: Pega fuerte");

	
}
void Ayuda::Actualizar (Juego & game) {
	TamanioVentana = Vector2f(game.Ventana.getSize());
	game.Ventana.setView(View(Vector2f(TamanioVentana.x/2,TamanioVentana.y/2),TamanioVentana));
	Vector2i MousePoss=Mouse::getPosition(game.Ventana);
	Rect<float> mouse(MousePoss.x,MousePoss.y,1,1);
	//Actualizar Textos------------------------------------------------
	ControlesTitulo.setPosition(0,0);
	ControlesContenido.setPosition(0,TamanioVentana.y*0.1);
	
	DificultadTitulo.setPosition(TamanioVentana.x*0.35,0);
	DificultadContenido.setPosition(0,TamanioVentana.y*0.1);
	
	PersonajesTitulo.setPosition(TamanioVentana.x*0.65,0);
	PersonajesContenido.setPosition(0,TamanioVentana.y*0.1);
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		game.SetEscena(new Menu);
	}
	if(ControlesTitulo.getGlobalBounds().intersects(mouse)){
		QueMostrar = 1;
	}
	if(DificultadTitulo.getGlobalBounds().intersects(mouse)){
		QueMostrar = 2;
	}
	if(PersonajesTitulo.getGlobalBounds().intersects(mouse)){
		QueMostrar = 3;
	}
}

void Ayuda::Dibujar (RenderWindow & Vent) {
	Vent.clear(Color(0,0,0,255));
	Vent.draw(ControlesTitulo);
	Vent.draw(DificultadTitulo);
	Vent.draw(PersonajesTitulo);
	switch(QueMostrar){
	case 1:
		Vent.draw(ControlesContenido);
		QueMostrar=0;
		break;
	case 2:
		Vent.draw(DificultadContenido);
		QueMostrar=0;
		break;
	case 3:
		Vent.draw(PersonajesContenido);
		QueMostrar=0;
		break;
	}
	Vent.display();
}


Ayuda::~Ayuda ( ) {
	
}

