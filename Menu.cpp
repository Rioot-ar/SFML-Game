#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Juego.h"
#include "SeleccionDePersonaje.h"
#include "Ayuda.h"
#include "Puntaje.h"
using namespace std;
using namespace sf;
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
	FondoEscena= new Texture;
	FondoE= new Sprite;
	FondoEscena->loadFromFile("Recursos/Fondo.PNG");
	
	FondoE->setTexture(*FondoEscena);
	FondoE->setPosition(0,0);
	FondoE->setScale(TamanioVentana.x/FondoEscena->getSize().x,TamanioVentana.y/FondoEscena->getSize().y);
	FlechaM= new Sprite;
	CargarTexto(Titulo, 70, "Desterraria",Vector2f( TamanioVentana.x/2.f,0),*fuente,1 );
	CargarTexto(MenuInicio, 30, "Iniciar Partida",Vector2f( TamanioVentana.x/2.f,TamanioVentana.y*0.25),*fuente );
	CargarTexto(MenuOpciones, 30, "Ayuda",Vector2f( TamanioVentana.x/2.f,TamanioVentana.y*0.5),*fuente );
	CargarTexto(MenuPuntajes, 30, "Puntajes",Vector2f( TamanioVentana.x/2.f,TamanioVentana.y*0.75),*fuente );
	
	MusicaPrincipal.openFromFile("Recursos/MenuP.ogg");
	MusicaPrincipal.setLoop(true);
	MusicaPrincipal.setVolume(50);
	MusicaPrincipal.play();
	
	FlechaM->setTexture(*FlechaMenu);
	FlechaM->setOrigin(FlechaM->getGlobalBounds().height,FlechaM->getGlobalBounds().height/2.f);

	
}
void Menu::Actualizar(Juego &game){
	TamanioVentana = Vector2f(game.Ventana.getSize());
	FondoE->setScale(TamanioVentana.x/FondoEscena->getSize().x,TamanioVentana.y/FondoEscena->getSize().y);
	game.Ventana.setView(View(Vector2f(TamanioVentana.x/2.f,TamanioVentana.y/2.f),TamanioVentana));	
	e=game.ObtenerEvento();
	FlechaM->setScale(TamanioVentana.x*0.0005,TamanioVentana.x*0.0005);
///Acomodar	
	Titulo.setCharacterSize(TamanioVentana.x*0.0875);
	Titulo.setOrigin(Titulo.getGlobalBounds().width/2,0);
	Titulo.setPosition(Vector2f( TamanioVentana.x/2.f,TamanioVentana.y*0));
	
	MenuInicio.setCharacterSize(TamanioVentana.x*0.0375);
	MenuInicio.setPosition(Vector2f( TamanioVentana.x/2.f,TamanioVentana.y*0.25));
	

	
	MenuOpciones.setCharacterSize(TamanioVentana.x*0.0375);
	MenuOpciones.setPosition(Vector2f( TamanioVentana.x/2.f,TamanioVentana.y*0.5));

	
	MenuPuntajes.setCharacterSize(TamanioVentana.x*0.0375);
	MenuPuntajes.setPosition(Vector2f( TamanioVentana.x/2.f,TamanioVentana.y*0.75));
	
	
//	Seleccion Con Mouse-----------------------------------------------------------
	Vector2i MousePoss=Mouse::getPosition(game.Ventana);
	Rect<float> mouse(MousePoss.x,MousePoss.y,1,1);
		
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
	delete FondoEscena;
	delete FondoE;
	delete FlechaM;
	delete fuente;
	delete FlechaMenu;
}

