#include "Puntaje.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>
#include <fstream>
#include "Menu.h"
using namespace std;
using namespace sf;




Puntaje::Puntaje(int PP): m_entrada(*fuente)  {
	
	w=new RenderWindow(VideoMode(800,600),"Nuevo Juego");
	m_Puntos=PP;
	IngrN.setFont(*fuente);
	IngrN.setCharacterSize(50);
	IngrN.setString("Ingrese Su Nombre");
	IngrN.setOrigin(IngrN.getGlobalBounds().width/2,0);
	
	
	int aux=m_Puntos;
	SusP.setFont(*fuente);
	SusP.setCharacterSize(45);
	SusP.setString("Usted Obtuvo "+to_string(aux)+" Puntos");
	SusP.setOrigin(SusP.getGlobalBounds().width/2,0);
	
	TituloPuntuaciones.setFont(*fuente);
	TituloPuntuaciones.setCharacterSize(50);
	TituloPuntuaciones.setString("Tabla de Puntuaciones");
	TituloPuntuaciones.setOrigin(TituloPuntuaciones.getGlobalBounds().width/2,0);

	MostrarNPuntuaciones.setFont(*fuente);
	MostrarNPuntuaciones.setCharacterSize(20);
	MostrarNPuntuaciones.setOrigin(MostrarNPuntuaciones.getGlobalBounds().width/2,0);
	
	MostrarPuntuaciones.setFont(*fuente);
	MostrarPuntuaciones.setCharacterSize(20);
	MostrarPuntuaciones.setOrigin(MostrarNPuntuaciones.getGlobalBounds().width,0);
	
	///Cargo los puntos en un vector.
	Ar.open("Recursos/Puntuaciones.dat",ios::binary|ios::ate|ios::in|ios::out);
	int bytes = Ar.tellg();
	int cantPuntajes = bytes/sizeof(Puntos);
	Ar.seekg(0);
	Puntos auxp;
	for(int i=0;i<cantPuntajes;i++) {  
		Ar.read(reinterpret_cast<char*>(&auxp),sizeof(Puntos));
		m_tPuntos.push_back(auxp);
	}

	string Pun="";
	string Nom="";
	for(size_t i=0;i<m_tPuntos.size();i++) {  
		int aux=m_tPuntos[i].Puntuacion;
		Nom=Nom+"\n"+m_tPuntos[i].Nombre;
		Pun=Pun+"\n"+to_string(aux);
	}
	
	MostrarPuntuaciones.setString(Pun);
	MostrarNPuntuaciones.setString(Nom);
}




bool OrdenarPuntos(Puntos a, Puntos b){
	return a.Puntuacion > b.Puntuacion;	
}	
	
void CargarPuntaje(string Nom, int &P, vector<Puntos> &v, Text &N,Text &Pu) {
	Puntos Agr;
	Agr.Puntuacion=P;
	strcpy(Agr.Nombre,Nom.c_str());
	
	
	///Solo se guardaran los 10 puntajes mas altos
	if(v.size()>=10){
		v.push_back(Agr);
		sort(v.begin(),v.end(),OrdenarPuntos);
		v.resize(10);
	}else{
		v.push_back(Agr);
		sort(v.begin(),v.end(),OrdenarPuntos);
	}
	P=0;
	string Pun="";
	string Nomb="";
	for(size_t i=0;i<v.size();i++) {  
		int aux=v[i].Puntuacion;
		Nomb=Nomb+"\n"+v[i].Nombre;
		Pun=Pun+"\n"+to_string(aux);
	}
	N.setString(Nomb);
	Pu.setString(Pun);
}

void Puntaje::Actualizar (Juego & game) {
	TamanioVentana = Vector2f(game.Ventana.getSize());
	game.Ventana.setView(View(Vector2f(TamanioVentana.x/2,TamanioVentana.y/2),TamanioVentana));
	w->setView(game.Ventana.getView());
	
	TamanioVentana = Vector2f(w->getSize());
	///m_Puntos es el entero recibido en el constructor, indica los puntos que hizo el jugador. En el caso de que m_Puntos = 0 solo se tienen que mostrar los puntajes.
	if(m_Puntos>0){
		IngrN.setPosition(Vector2f( TamanioVentana.x/2,TamanioVentana.y*0.20));
		SusP.setPosition(Vector2f( TamanioVentana.x/2,0 ));
		m_entrada.setOrigin(m_entrada.getGlobalBounds().width,0);
		m_entrada.setPosition(TamanioVentana.x/2,TamanioVentana.y*0.5);	
		Event e;
		while(w->pollEvent(e)){
			if (e.type==Event::KeyPressed && e.key.code==Keyboard::Return) { 
				m_Nombre=m_entrada.getValue();
				m_entrada.reset();
				CargarPuntaje(m_Nombre,m_Puntos,m_tPuntos,MostrarNPuntuaciones,MostrarPuntuaciones);
			} else {m_entrada.processEvent(e);}
		}
		m_entrada.update();
	}else{
		/*
		TituloPuntuaciones.setCharacterSize(TamanioVentana.x*0.062);
		MostrarNPuntuaciones.setCharacterSize(TamanioVentana.x*0.025);
		MostrarPuntuaciones.setCharacterSize(TamanioVentana.x*0.025);
		*/
		TituloPuntuaciones.setPosition(Vector2f( TamanioVentana.x/2,0));
		MostrarNPuntuaciones.setPosition(Vector2f( 0,TamanioVentana.y*0.20 ));
		MostrarPuntuaciones.setPosition(Vector2f( TamanioVentana.x/2,TamanioVentana.y*0.20 ));
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		game.SetEscena(new Menu);
	}
}

void Puntaje::Dibujar (RenderWindow & Vent) {
	w->clear(Color(40,25,0,255));
	if(m_Puntos>0){
		w->draw(IngrN);
		w->draw(m_entrada);
		w->draw(SusP);
	}else{
		w->draw(TituloPuntuaciones);
		w->draw(MostrarNPuntuaciones);
		w->draw(MostrarPuntuaciones);
	}

	w->display();
}

Puntaje::~Puntaje() {
	Puntos aux;
	Ar.seekp(0);
	for(int i=0;i<m_tPuntos.size();i++) {  
		aux=m_tPuntos[i];
		Ar.write(reinterpret_cast<char*>(&aux),sizeof(aux));
	}
	Ar.close();
	delete w;
}

