<<<<<<< HEAD
#include "Ayuda.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"
using namespace sf;
Ayuda::Ayuda() {
	Vector2f TamanioVentana = {800,600};
	
	//Texto Controles--------------------------------
	ControlesTitulo.setFont(*fuente);
	ControlesTitulo.setCharacterSize(35);
	ControlesTitulo.setString("Controles\n");

	
	ControlesContenido.setFont(*fuente);
	ControlesContenido.setCharacterSize(25);
	ControlesContenido.setString("Para saltar presione    W\n\nPara moverse utilize las teclas    A y S\n\nPara atacar presione espacio\n\nPara utilizar la habilidad especial presione Q\n\nPara volver al menu presione escape");

	
	//Texto Dificultad---------------------------------------
	DificultadTitulo.setFont(*fuente);
	DificultadTitulo.setCharacterSize(35);
	DificultadTitulo.setString("Dificultad\n");

	
	DificultadContenido.setFont(*fuente);
	DificultadContenido.setCharacterSize(25);
	DificultadContenido.setString("En la dificultad normal los enemigos son menos numerosos,\nel numero de puntos recibidos por terminar un nivel es menor\n\nEn dificil hay mayor cantidad y variedad de enemigos");

	
	//Texto Personajes---------------------------
	PersonajesTitulo.setFont(*fuente);
	PersonajesTitulo.setCharacterSize(35);
	PersonajesTitulo.setString("Personajes\n");

	
	PersonajesContenido.setFont(*fuente);
	PersonajesContenido.setCharacterSize(25);
	PersonajesContenido.setString("Caballero: Personaje con mayor salud y defensa, su habilidad especial\nle cura completamente y lo hace intocable durante 10 segundos\n\nCazador: Personaje equilibrado en su ataque y defensa, su habilidad\nespecial aumenta su daño y su velocidad de ataque\n\nMago: Personaje con mayor daño y poco aguante, su habilidad especial\nconsiste en un ataque de daño elevado");

	
}
void Ayuda::Actualizar (Juego & game) {
	
	//Acomodar vista al centro de la ventana
	TamanioVentana = Vector2f(game.Ventana.getSize());	
	game.Ventana.setView(View(Vector2f(TamanioVentana.x/2,TamanioVentana.y/2),TamanioVentana));
	
	//Obtener posicion del puntero
	Vector2i MousePoss=Mouse::getPosition(game.Ventana);
	Rect<float> mouse(MousePoss.x,MousePoss.y,1,1);
	
	//Actualizar Textos------------------------------------------------
	ControlesTitulo.setPosition(0,0);
	ControlesContenido.setPosition(0,TamanioVentana.y*0.1);
	ControlesTitulo.setCharacterSize(TamanioVentana.x*0.04);
	ControlesContenido.setCharacterSize(TamanioVentana.x*0.03);
	
	DificultadTitulo.setPosition(TamanioVentana.x*0.35,0);
	DificultadTitulo.setCharacterSize(TamanioVentana.x*0.04);
	DificultadContenido.setCharacterSize(TamanioVentana.x*0.03);
	DificultadContenido.setPosition(0,TamanioVentana.y*0.1);
	
	PersonajesTitulo.setPosition(TamanioVentana.x*0.65,0);
	PersonajesTitulo.setCharacterSize(TamanioVentana.x*0.04);
	PersonajesContenido.setCharacterSize(TamanioVentana.x*0.03);
	PersonajesContenido.setPosition(0,TamanioVentana.y*0.1);
	
	//Volver al menu
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		game.SetEscena(new Menu);
	}
	
	///Segun lo que apunte el mouse mostrar ayuda
	//1--Controles 
	//2--Dificultad 
	//3--Personajes
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

=======
#include "Ayuda.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"
using namespace sf;
Ayuda::Ayuda() {
	Vector2f TamanioVentana = {800,600};
	
	//Texto Controles--------------------------------
	ControlesTitulo.setFont(*fuente);
	ControlesTitulo.setCharacterSize(35);
	ControlesTitulo.setString("Controles\n");

	
	ControlesContenido.setFont(*fuente);
	ControlesContenido.setCharacterSize(25);
	ControlesContenido.setString("Para saltar presione    W\n\nPara moverse utilize las teclas    A y S\n\nPara atacar presione espacio\n\nPara utilizar la habilidad especial presione Q\n\nPara volver al menu presione escape");

	
	//Texto Dificultad---------------------------------------
	DificultadTitulo.setFont(*fuente);
	DificultadTitulo.setCharacterSize(35);
	DificultadTitulo.setString("Dificultad\n");

	
	DificultadContenido.setFont(*fuente);
	DificultadContenido.setCharacterSize(25);
	DificultadContenido.setString("En la dificultad normal los enemigos son menos numerosos,\nel numero de puntos recibidos por terminar un nivel es menor\n\nEn dificil hay mayor cantidad y variedad de enemigos");

	
	//Texto Personajes---------------------------
	PersonajesTitulo.setFont(*fuente);
	PersonajesTitulo.setCharacterSize(35);
	PersonajesTitulo.setString("Personajes\n");

	
	PersonajesContenido.setFont(*fuente);
	PersonajesContenido.setCharacterSize(25);
	PersonajesContenido.setString("Caballero: Personaje con mayor salud y defensa, su habilidad especial\nle cura completamente y lo hace intocable durante 10 segundos\n\nCazador: Personaje equilibrado en su ataque y defensa, su habilidad\nespecial aumenta su daño y su velocidad de ataque\n\nMago: Personaje con mayor daño y poco aguante, su habilidad especial\nconsiste en un ataque de daño elevado");

	
}
void Ayuda::Actualizar (Juego & game) {
	
	//Acomodar vista al centro de la ventana
	TamanioVentana = Vector2f(game.Ventana.getSize());	
	game.Ventana.setView(View(Vector2f(TamanioVentana.x/2,TamanioVentana.y/2),TamanioVentana));
	
	//Obtener posicion del puntero
	Vector2i MousePoss=Mouse::getPosition(game.Ventana);
	Rect<float> mouse(MousePoss.x,MousePoss.y,1,1);
	
	//Actualizar Textos------------------------------------------------
	ControlesTitulo.setPosition(0,0);
	ControlesContenido.setPosition(0,TamanioVentana.y*0.1);
	ControlesTitulo.setCharacterSize(TamanioVentana.x*0.04);
	ControlesContenido.setCharacterSize(TamanioVentana.x*0.03);
	
	DificultadTitulo.setPosition(TamanioVentana.x*0.35,0);
	DificultadTitulo.setCharacterSize(TamanioVentana.x*0.04);
	DificultadContenido.setCharacterSize(TamanioVentana.x*0.03);
	DificultadContenido.setPosition(0,TamanioVentana.y*0.1);
	
	PersonajesTitulo.setPosition(TamanioVentana.x*0.65,0);
	PersonajesTitulo.setCharacterSize(TamanioVentana.x*0.04);
	PersonajesContenido.setCharacterSize(TamanioVentana.x*0.03);
	PersonajesContenido.setPosition(0,TamanioVentana.y*0.1);
	
	//Volver al menu
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		game.SetEscena(new Menu);
	}
	
	///Segun lo que apunte el mouse mostrar ayuda
	//1--Controles 
	//2--Dificultad 
	//3--Personajes
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

>>>>>>> 04796e6 (Volumen maestro y debug_win32)
