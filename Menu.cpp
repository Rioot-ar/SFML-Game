#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Juego.h"
#include "SeleccionDePersonaje.h"
#include "Ayuda.h"
#include "Puntaje.h"
using namespace std;
using namespace sf;

//Funcion para crear texto "Orig" sirve para verificar si es necesario cambiar el origen del Text
void CargarTexto(Text &Tipo, int Tamano, String Texto, Vector2f Posicion, const Font &Fuente, int Orig=0) {
	Tipo.setFont(Fuente);
	Tipo.setCharacterSize(Tamano);
	Tipo.setString(Texto);
	if(Orig){
		Tipo.setOrigin(Tipo.getGlobalBounds().width/2,0);
	}
	Tipo.setPosition(Posicion);
}




Menu::Menu(){
	
	//Fondo del menu
	FondoEscena->loadFromFile("Recursos/Estructuras/Fondo.PNG");	
	FondoE->setTexture(*FondoEscena);
	FondoE->setPosition(0,0);
	FondoE->setScale(TamanioVentana.x/FondoEscena->getSize().x,TamanioVentana.y/FondoEscena->getSize().y);
	
	//Flecha de seleccion
	FlechaM->setTexture(*FlechaMenu);
	FlechaM->setOrigin(FlechaM->getGlobalBounds().height,FlechaM->getGlobalBounds().height/2.f);
	
	//Texto a mostrar en pantalla
	CargarTexto(Titulo, 70, "Kingdom",Vector2f( TamanioVentana.x/2.f,0),*fuente,1 );
	CargarTexto(MenuInicio, 30, "Iniciar Partida",Vector2f( TamanioVentana.x/2.f,TamanioVentana.y*0.25),*fuente );
	CargarTexto(MenuOpciones, 30, "Ayuda",Vector2f( TamanioVentana.x/2.f,TamanioVentana.y*0.5),*fuente );
	CargarTexto(MenuPuntajes, 30, "Puntajes",Vector2f( TamanioVentana.x/2.f,TamanioVentana.y*0.75),*fuente );
	
	//Musica del nivel
	MusicaPrincipal.openFromFile("Recursos/Utiles/MenuP.ogg");
	MusicaPrincipal.setLoop(true);
	MusicaPrincipal.setVolume(50);
	MusicaPrincipal.play();
	
	
	
}

void Menu::Actualizar(Juego &game){
	
	TamanioVentana = Vector2f(game.Ventana.getSize());
	e=game.ObtenerEvento();
///Acomodar	
	//View de la ventana 
	game.Ventana.setView(View(Vector2f(TamanioVentana.x/2.f,TamanioVentana.y/2.f),TamanioVentana));	
	//Fondo y flecha de seleccion
	FondoE->setScale(TamanioVentana.x/FondoEscena->getSize().x,TamanioVentana.y/FondoEscena->getSize().y);
	FlechaM->setScale(TamanioVentana.x*0.0005,TamanioVentana.x*0.0005);

	//Texto
	Titulo.setCharacterSize(TamanioVentana.x*0.0875);
	Titulo.setOrigin(Titulo.getGlobalBounds().width/2,0);
	Titulo.setPosition(Vector2f( TamanioVentana.x/2.f,TamanioVentana.y*0));
	
	MenuInicio.setCharacterSize(TamanioVentana.x*0.0375);
	MenuInicio.setPosition(Vector2f( TamanioVentana.x/2.f,TamanioVentana.y*0.25));
	

	
	MenuOpciones.setCharacterSize(TamanioVentana.x*0.0375);
	MenuOpciones.setPosition(Vector2f( TamanioVentana.x/2.f,TamanioVentana.y*0.5));

	
	MenuPuntajes.setCharacterSize(TamanioVentana.x*0.0375);
	MenuPuntajes.setPosition(Vector2f( TamanioVentana.x/2.f,TamanioVentana.y*0.75));
	
	
///	Seleccion Con Mouse-----------------------------------------------------------
	
	//Posicion del mouse en la ventana
	Vector2i MousePoss=Mouse::getPosition(game.Ventana);
	Rect<float> mouse(MousePoss.x,MousePoss.y,1,1);
	
	//Si el puntero intersecta con el texto, entonces mover la flecha de seleccion hacia la izquierda del texto, ademas habilitar la opcion de cambiar la escena
	if(MenuInicio.getGlobalBounds().intersects(mouse)){
		FlechaM->setPosition(MenuInicio.getPosition().x,MenuInicio.getPosition().y+MenuInicio.getGlobalBounds().height);
		if(Keyboard::isKeyPressed(Keyboard::Key::Return) or Mouse::isButtonPressed(Mouse::Left)){
			game.SetEscena(new SeleccionDePersonaje);
		}
	}
	if(MenuOpciones.getGlobalBounds().intersects(mouse)){
		FlechaM->setPosition(MenuOpciones.getPosition().x,MenuOpciones.getPosition().y+MenuOpciones.getGlobalBounds().height/2.f);
		if(Keyboard::isKeyPressed(Keyboard::Key::Return) or Mouse::isButtonPressed(Mouse::Left)){
			game.SetEscena(new Ayuda);
		}
	}
	if(MenuPuntajes.getGlobalBounds().intersects(mouse)){
		FlechaM->setPosition(MenuPuntajes.getPosition().x,MenuPuntajes.getPosition().y+MenuPuntajes.getGlobalBounds().height/2.f);
		if(Keyboard::isKeyPressed(Keyboard::Key::Return) or Mouse::isButtonPressed(Mouse::Left)){
			game.SetEscena(new Puntaje(0));
			
		}
	}
	

}

void Menu::Dibujar(RenderWindow &Vent){
	Vent.clear(Color(0,0,0,255));
	Vent.draw(*FondoE);
	Vent.draw(*FlechaM);
	Vent.draw(Titulo);
	Vent.draw(MenuInicio);
	Vent.draw(MenuOpciones);
	Vent.draw(MenuPuntajes);
	Vent.display();
}


Menu::~Menu ( ) {

}

