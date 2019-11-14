#include <iostream>
#include "SistemaGestion.h"
using namespace std;

int main() {
	SistemaGestion Sistema = SistemaGestion();

	Sistema.agregarUsuario("Juan", "Perez", "Argentina", "juanperez@email.com", "JuanPerez");
	Sistema.agregarUsuario("Hemano de Juan", "Perez", "Argentina", "juanperez@email.com", "JuanPerez");

	Sistema.mostrarListaUsers();

	Usuario* userElegido = Sistema.buscarUser(0);

	Sistema.agregarPregunta("Titulo", "descripcion", userElegido);

	Sistema.mostrarListaPreguntas();

	return 0;
}
