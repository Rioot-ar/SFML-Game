<<<<<<< HEAD
#include "Puntaje.h"
#include <SFML/Graphics.hpp>
#include <cstring>
#include <fstream>
#include "Menu.h"
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;




Puntaje::Puntaje(int PP): m_entrada(*fuente)  {

	//Fondo de la escena
	FondoEscena->loadFromFile("Recursos/Estructuras/FondoFinal.jpg");
	FondoE->setTexture(*FondoEscena);
	FondoE->setPosition(0,0);
	FondoE->setScale(TamanioVentana.x/FondoEscena->getSize().x,TamanioVentana.y/FondoEscena->getSize().y);
	
	
	m_Puntos=PP;//Puntos que recibe el constructor
	
	///Configuracion de los Text que se mostraran en pantalla
	IngrN.setFont(*fuente);
	IngrN.setCharacterSize(50);
	IngrN.setString("Ingrese Su Nombre");
	IngrN.setOrigin(IngrN.getGlobalBounds().width/2,0);
	
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
	
	//Cargo texto con el puntaje recibido
	int aux=m_Puntos;
	SusP.setFont(*fuente);
	SusP.setCharacterSize(45);
	SusP.setString("Usted Obtuvo "+to_string(aux)+" Puntos");
	SusP.setOrigin(SusP.getGlobalBounds().width/2,0);
	
	///Cargo los puntos en un vector
	Ar.open("Recursos/Utiles/Puntuaciones.dat",ios::binary|ios::ate|ios::in|ios::out);
	int bytes = Ar.tellg();
	int cantPuntajes = bytes/sizeof(Puntos);
	Ar.seekg(0);
	Puntos auxp;
	for(int i=0;i<cantPuntajes;i++) {  
		Ar.read(reinterpret_cast<char*>(&auxp),sizeof(Puntos));
		m_tPuntos.push_back(auxp);
	}
	//Inserto puntos y nombres en strings distintos
	string Pun="";
	string Nom="";
	for(size_t i=0;i<m_tPuntos.size();i++) {  
		int aux=m_tPuntos[i].Puntuacion;
		Nom=Nom+"\n"+m_tPuntos[i].Nombre;
		Pun=Pun+"\n"+to_string(aux);
	}
	
	//Inserto los strings en los objetos Text
	MostrarNPuntuaciones.setString(Nom);//Nombres
	MostrarPuntuaciones.setString(Pun);//Puntos
	
	//Musica
	MusicaPrincipal.openFromFile("Recursos/Utiles/Puntajes.ogg");
	MusicaPrincipal.setLoop(true);
	MusicaPrincipal.setVolume(50);
	MusicaPrincipal.play();
}



//Funcion para ordenar puntos
bool OrdenarPuntos(Puntos a, Puntos b){
	return a.Puntuacion > b.Puntuacion;	
}	
	
//F
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
	P=0;//P=0 para mostrar todos los puntajes
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
	FondoE->setScale(TamanioVentana.x/FondoEscena->getSize().x,TamanioVentana.y/FondoEscena->getSize().y);
	e=game.ObtenerEvento();
	///m_Puntos es el entero recibido en el constructor, indica los puntos que hizo el jugador. En el caso de que m_Puntos = 0 solo se tienen que mostrar los puntajes.
	if(m_Puntos>0){
		//Actualizo textos
		IngrN.setPosition(Vector2f( TamanioVentana.x/2,TamanioVentana.y*0.20));
		SusP.setPosition(Vector2f( TamanioVentana.x/2,0 ));
		m_entrada.setOrigin(m_entrada.getGlobalBounds().width,0);
		m_entrada.setPosition(TamanioVentana.x/2,TamanioVentana.y*0.5);	
		
		//Bucle para recibir el nombre del jugador
		while(game.Ventana.pollEvent(*e)) {
			if (e->type==Event::KeyPressed && e->key.code==Keyboard::Return) {
				m_Nombre=m_entrada.getValue();
				m_entrada.reset();
				CargarPuntaje(m_Nombre,m_Puntos,m_tPuntos,MostrarNPuntuaciones,MostrarPuntuaciones);
			} else {m_entrada.processEvent(*e);}
		}
		m_entrada.update();
		
	}else{
		//Actualizo texto de puntajes
		TituloPuntuaciones.setCharacterSize(TamanioVentana.x*0.062);
		TituloPuntuaciones.setOrigin(TituloPuntuaciones.getGlobalBounds().width/2,0);
		
		MostrarNPuntuaciones.setCharacterSize(TamanioVentana.x*0.028);
		MostrarNPuntuaciones.setOrigin(MostrarNPuntuaciones.getGlobalBounds().width/2,0);
		
		MostrarPuntuaciones.setCharacterSize(TamanioVentana.x*0.028);
		MostrarPuntuaciones.setOrigin(MostrarPuntuaciones.getGlobalBounds().width/2,0);
		
		TituloPuntuaciones.setPosition(Vector2f( TamanioVentana.x/2,0));
		MostrarNPuntuaciones.setPosition(Vector2f( TamanioVentana.x*0.25,TamanioVentana.y*0.20 ));
		MostrarPuntuaciones.setPosition(Vector2f( TamanioVentana.x*0.75,TamanioVentana.y*0.20 ));
	}
	//Volver al menu
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		game.SetEscena(new Menu);
	}
}


void Puntaje::Dibujar (RenderWindow & Vent) {
	Vent.clear(Color(40,25,0,255));
	Vent.draw(*FondoE);
	//si m_Puntos es mayor a 0, entonces muestro el mensaje para que ingrese nombre
	if(m_Puntos>0){
		Vent.draw(IngrN);
		Vent.draw(m_entrada);
		Vent.draw(SusP);
		
	}else{
		Vent.draw(TituloPuntuaciones);
		Vent.draw(MostrarNPuntuaciones);
		Vent.draw(MostrarPuntuaciones);
	}

	Vent.display();
}


//Guardo los puntos
Puntaje::~Puntaje() {
	Puntos aux;
	Ar.seekp(0);
	for(int i=0;i<m_tPuntos.size();i++) {  
		aux=m_tPuntos[i];
		Ar.write(reinterpret_cast<char*>(&aux),sizeof(aux));
	}
	Ar.close();
}

=======
#include "Puntaje.h"
#include <SFML/Graphics.hpp>
#include <cstring>
#include <fstream>
#include "Menu.h"
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;




Puntaje::Puntaje(int PP): m_entrada(*fuente)  {

	//Fondo de la escena
	FondoEscena->loadFromFile("Recursos/Estructuras/FondoFinal.jpg");
	FondoE->setTexture(*FondoEscena);
	FondoE->setPosition(0,0);
	FondoE->setScale(TamanioVentana.x/FondoEscena->getSize().x,TamanioVentana.y/FondoEscena->getSize().y);
	
	
	m_Puntos=PP;//Puntos que recibe el constructor
	
	///Configuracion de los Text que se mostraran en pantalla
	IngrN.setFont(*fuente);
	IngrN.setCharacterSize(50);
	IngrN.setString("Ingrese Su Nombre");
	IngrN.setOrigin(IngrN.getGlobalBounds().width/2,0);
	
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
	
	//Cargo texto con el puntaje recibido
	int aux=m_Puntos;
	SusP.setFont(*fuente);
	SusP.setCharacterSize(45);
	SusP.setString("Usted Obtuvo "+to_string(aux)+" Puntos");
	SusP.setOrigin(SusP.getGlobalBounds().width/2,0);
	
	///Cargo los puntos en un vector
	Ar.open("Recursos/Utiles/Puntuaciones.dat",ios::binary|ios::ate|ios::in|ios::out);
	int bytes = Ar.tellg();
	int cantPuntajes = bytes/sizeof(Puntos);
	Ar.seekg(0);
	Puntos auxp;
	for(int i=0;i<cantPuntajes;i++) {  
		Ar.read(reinterpret_cast<char*>(&auxp),sizeof(Puntos));
		m_tPuntos.push_back(auxp);
	}
	//Inserto puntos y nombres en strings distintos
	string Pun="";
	string Nom="";
	for(size_t i=0;i<m_tPuntos.size();i++) {  
		int aux=m_tPuntos[i].Puntuacion;
		Nom=Nom+"\n"+m_tPuntos[i].Nombre;
		Pun=Pun+"\n"+to_string(aux);
	}
	
	//Inserto los strings en los objetos Text
	MostrarNPuntuaciones.setString(Nom);//Nombres
	MostrarPuntuaciones.setString(Pun);//Puntos
	
	//Musica
	MusicaPrincipal.openFromFile("Recursos/Utiles/Puntajes.ogg");
	MusicaPrincipal.setLoop(true);
	MusicaPrincipal.setVolume(volumenFondo);
	MusicaPrincipal.play();
}



//Funcion para ordenar puntos
bool OrdenarPuntos(Puntos a, Puntos b){
	return a.Puntuacion > b.Puntuacion;	
}	
	
//F
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
	P=0;//P=0 para mostrar todos los puntajes
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
	FondoE->setScale(TamanioVentana.x/FondoEscena->getSize().x,TamanioVentana.y/FondoEscena->getSize().y);
	e=game.ObtenerEvento();
	///m_Puntos es el entero recibido en el constructor, indica los puntos que hizo el jugador. En el caso de que m_Puntos = 0 solo se tienen que mostrar los puntajes.
	if(m_Puntos>0){
		//Actualizo textos
		IngrN.setPosition(Vector2f( TamanioVentana.x/2,TamanioVentana.y*0.20));
		SusP.setPosition(Vector2f( TamanioVentana.x/2,0 ));
		m_entrada.setOrigin(m_entrada.getGlobalBounds().width,0);
		m_entrada.setPosition(TamanioVentana.x/2,TamanioVentana.y*0.5);	
		
		//Bucle para recibir el nombre del jugador
		while(game.Ventana.pollEvent(*e)) {
			if (e->type==Event::KeyPressed && e->key.code==Keyboard::Return) {
				m_Nombre=m_entrada.getValue();
				m_entrada.reset();
				CargarPuntaje(m_Nombre,m_Puntos,m_tPuntos,MostrarNPuntuaciones,MostrarPuntuaciones);
			} else {m_entrada.processEvent(*e);}
		}
		m_entrada.update();
		
	}else{
		//Actualizo texto de puntajes
		TituloPuntuaciones.setCharacterSize(TamanioVentana.x*0.062);
		TituloPuntuaciones.setOrigin(TituloPuntuaciones.getGlobalBounds().width/2,0);
		
		MostrarNPuntuaciones.setCharacterSize(TamanioVentana.x*0.028);
		MostrarNPuntuaciones.setOrigin(MostrarNPuntuaciones.getGlobalBounds().width/2,0);
		
		MostrarPuntuaciones.setCharacterSize(TamanioVentana.x*0.028);
		MostrarPuntuaciones.setOrigin(MostrarPuntuaciones.getGlobalBounds().width/2,0);
		
		TituloPuntuaciones.setPosition(Vector2f( TamanioVentana.x/2,0));
		MostrarNPuntuaciones.setPosition(Vector2f( TamanioVentana.x*0.25,TamanioVentana.y*0.20 ));
		MostrarPuntuaciones.setPosition(Vector2f( TamanioVentana.x*0.75,TamanioVentana.y*0.20 ));
	}
	//Volver al menu
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		game.SetEscena(new Menu);
	}
}


void Puntaje::Dibujar (RenderWindow & Vent) {
	Vent.clear(Color(40,25,0,255));
	Vent.draw(*FondoE);
	//si m_Puntos es mayor a 0, entonces muestro el mensaje para que ingrese nombre
	if(m_Puntos>0){
		Vent.draw(IngrN);
		Vent.draw(m_entrada);
		Vent.draw(SusP);
		
	}else{
		Vent.draw(TituloPuntuaciones);
		Vent.draw(MostrarNPuntuaciones);
		Vent.draw(MostrarPuntuaciones);
	}

	Vent.display();
}


//Guardo los puntos
Puntaje::~Puntaje() {
	Puntos aux;
	Ar.seekp(0);
	for(int i=0;i<m_tPuntos.size();i++) {  
		aux=m_tPuntos[i];
		Ar.write(reinterpret_cast<char*>(&aux),sizeof(aux));
	}
	Ar.close();
}

>>>>>>> 04796e6 (Volumen maestro y debug_win32)
