#include <iostream>
#include "SistemaGestion.h"
using namespace std;

int main() {
	SistemaGestion Sistema = SistemaGestion();

	Sistema.agregarUsuario("Juan", "Perez", "Argentina", "juanperez@email.com", "JuanPerez");
	Sistema.agregarUsuario("Hemano de Juan", "Perez", "Argentina", "juanperezhermano@email.com", "JuanPerezH");
	Sistema.agregarUsuario("Primo de Juan", "Perez", "Argentina", "juanperezprimo@email.com", "JuanPerezP");
	Sistema.agregarUsuario("Esposa de Juan", "Perez", "Argentina", "juanperezEsposa@email.com", "JuanPerezE");

	Sistema.mostrarListaUsers();

	Usuario* userElegido = Sistema.buscarUser(0); // Selecciona a Juan Perez
	vector<string> tagsDePregunta;
	tagsDePregunta.push_back("Un tag");
	tagsDePregunta.push_back("Otro tag");
	Sistema.agregarPregunta("Titulo", "descripcion", userElegido, tagsDePregunta); // Pregunta de Juan Perez

	Sistema.mostrarListaPreguntas();

	userElegido = Sistema.buscarUser(1);  // Selecciona a Hermano de Juan Perez
	Pregunta* preguntaELegida = Sistema.buscarPregunta(0); // Selecciona la pregunta de Juan Perez
	Sistema.agregarRespuesta(userElegido, preguntaELegida, "Mi respuesta", "mi descripcion");

	userElegido = Sistema.buscarUser(2);  // Selecciona a primo de Juan Perez
	Sistema.agregarRespuesta(userElegido, preguntaELegida, "Respuesta de primo", "mi descripcion");

	userElegido = Sistema.buscarUser(3);  // Selecciona a primo de Juan Perez
	Sistema.agregarRespuesta(userElegido, preguntaELegida, "Respuesta de Esposa", "Es La Que Mas Likes Tiene");


	userElegido = Sistema.buscarUser(0);//Selecciono a Juan Perez

	cout<<"-- Sus Notificaciones--"<<endl<<endl<<endl;
	userElegido->verNotificacion();

	cout<<"-- No Hay Mas Notificaciones--"<<endl<<endl<<endl;

	Respuesta* respuestaElegida = Sistema.buscarRespuesta(preguntaELegida, 2);
	Sistema.darLike(respuestaElegida);
	Sistema.darLike(respuestaElegida);
	Sistema.darLike(respuestaElegida);

	respuestaElegida = Sistema.buscarRespuesta(preguntaELegida, 1);

	Sistema.darLike(respuestaElegida);

	preguntaELegida->marcarConSolucion(respuestaElegida);

	preguntaELegida->mostrarRespuestas();
	Sistema.suspenderCuenta(userElegido);

	Fecha f1(20,6,2018);
	userElegido = Sistema.buscarUser(3); // Selecciona a La Esposa Juan Perez
	Sistema.agregarPregunta("Donde esta Juan?", "descripcion", userElegido, tagsDePregunta,f1); // Pregunta de Esposa de Juan Perez



	Sistema.mostrarListaPreguntas();

	cout<<"-- Pregunta con User Suspendido--"<<endl<<endl<<endl;
	Sistema.mostrarListaPreguntas();
	return 0;
}
