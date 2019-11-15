#include <iostream>
#include "SistemaGestion.h"
using namespace std;

int main() {
	SistemaGestion Sistema = SistemaGestion();

	Sistema.agregarUsuario("Juan", "Perez", "Argentina", "juanperez@email.com", "JuanPerez");
	Sistema.agregarUsuario("Hemano de Juan", "Perez", "Argentina", "juanperezhermano@email.com", "JuanPerezH");

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


	preguntaELegida->mostrarRespuestas();
	return 0;
}
