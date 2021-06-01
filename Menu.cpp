#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Juego.h"
#include "SeleccionDePersonaje.h"
#include "Ayuda.h"
#include <iostream>
#include "Puntaje.h"
using namespace std;
using namespace sf;
void CargarTexto(Text &Tipo, int Tamano, String Texto, Vector2f Posicion, const Font &Fuente, int Orig) {
	Tipo.setFont(Fuente);
	Tipo.setCharacterSize(Tamano);
	Tipo.setString(Texto);
	if(Orig){
		Tipo.setOrigin(Tipo.getGlobalBounds().width/2,0);
	}
	Tipo.setPosition(Posicion);
}


Menu::Menu(){
	FondoMenu= new Texture;
	FondoM= new Sprite;
	FlechaM= new Sprite;
	FondoMenu->loadFromFile("Recursos/Fondo.PNG");
	
	FondoM->setTexture(*FondoMenu);
	FondoM->setPosition(0,0);
	FondoM->setScale(TamanioVentana.x/FondoMenu->getSize().x,TamanioVentana.y/FondoMenu->getSize().y);
	
	CargarTexto(Titulo, 70, "Nombre Del Juego",Vector2f( TamanioVentana.x/2,0),*fuente,1 );
	CargarTexto(MenuInicio, 30, "Iniciar Partida",Vector2f( TamanioVentana.x/2,200),*fuente,0 );
	CargarTexto(MenuOpciones, 30, "Ayuda",Vector2f( TamanioVentana.x/2,300),*fuente,0 );
	CargarTexto(MenuPuntajes, 30, "Puntajes",Vector2f( TamanioVentana.x/2,400),*fuente,0 );
	
	
	FlechaM->setTexture(*FlechaMenu);
	FlechaM->setScale(0.3,0.35);
	FlechaM->setPosition(Titulo.getPosition().x-FlechaM->getGlobalBounds().width,200);
	
}
void Menu::Actualizar(Juego &game){
	TamanioVentana = Vector2f(game.Ventana.getSize());
	FondoM->setScale(TamanioVentana.x/FondoMenu->getSize().x,TamanioVentana.y/FondoMenu->getSize().y);
	game.Ventana.setView(View(Vector2f(TamanioVentana.x/2,TamanioVentana.y/2),TamanioVentana));
	
//	Acomodar 
	Titulo.setPosition(Vector2f( TamanioVentana.x/2,0));
	MenuInicio.setPosition(Vector2f( TamanioVentana.x/2,200));
	MenuOpciones.setPosition(Vector2f( TamanioVentana.x/2,300));
	MenuPuntajes.setPosition(Vector2f( TamanioVentana.x/2,400));
	
//	Seleccion Con Teclado-----------------------------------------------------------
	if(Keyboard::isKeyPressed(Keyboard::Key::Up) and FlechaM->getPosition().y >200){
		FlechaM->setPosition(Titulo.getPosition().x-FlechaM->getGlobalBounds().width,FlechaM->getPosition().y-100);
	}
	if(Keyboard::isKeyPressed(Keyboard::Key::Down) and FlechaM->getPosition().y <400){
		FlechaM->setPosition(Titulo.getPosition().x-FlechaM->getGlobalBounds().width,FlechaM->getPosition().y+100);
	}
	
//	Seleccion Con Mouse-----------------------------------------------------------
	Vector2i MousePoss=Mouse::getPosition(game.Ventana);
	Rect<float> mouse(MousePoss.x,MousePoss.y,1,1);
		
	if(MenuInicio.getGlobalBounds().intersects(mouse)){
		FlechaM->setPosition(Titulo.getPosition().x-FlechaM->getGlobalBounds().width,200);
		if(Keyboard::isKeyPressed(Keyboard::Key::Return) or Mouse::isButtonPressed(Mouse::Left)){
			game.SetEscena(new SeleccionDePersonaje);
		}
	}
	if(MenuOpciones.getGlobalBounds().intersects(mouse)){
		FlechaM->setPosition(Titulo.getPosition().x-FlechaM->getGlobalBounds().width,300);
		if(Keyboard::isKeyPressed(Keyboard::Key::Return) or Mouse::isButtonPressed(Mouse::Left)){
			game.SetEscena(new Ayuda);
		}
	}
	if(MenuPuntajes.getGlobalBounds().intersects(mouse)){
		FlechaM->setPosition(Titulo.getPosition().x-FlechaM->getGlobalBounds().width,400);
		if(Keyboard::isKeyPressed(Keyboard::Key::Return) or Mouse::isButtonPressed(Mouse::Left)){
			game.SetEscena(new Puntaje(0));
		}
	}
}
void Menu::Dibujar(RenderWindow &Vent){
	Vent.clear(Color(0,0,0,255));
	Vent.draw(*FondoM);
	Vent.draw(*FlechaM);
	Vent.draw(Titulo);
	Vent.draw(MenuInicio);
	Vent.draw(MenuOpciones);
	Vent.draw(MenuPuntajes);
	Vent.display();
}


Menu::~Menu ( ) {
	delete FondoMenu;
	delete FondoM;
	delete FlechaM;
	delete fuente;
	delete FlechaMenu;
}

