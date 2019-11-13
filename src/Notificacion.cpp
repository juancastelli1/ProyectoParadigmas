/*
 * Notificacion.cpp
 *
 *  Created on: 11 nov. 2019
 *      Author: Alumno
 */

#include "Notificacion.h"
#include "Respuesta.h"
#include "Usuario.h"
#include "Pregunta.h"

Notificacion::Notificacion(Respuesta* resp) : respuesta(resp) {
	// TODO Auto-generated constructor stub

}

Notificacion::~Notificacion() {
	// TODO Auto-generated destructor stub
}

Usuario* Notificacion::getUserRespuesta(){
	return respuesta->getUserResp();
}

Usuario* Notificacion::getUserPregunta(){
	return respuesta->getUserPreg();
}

void Notificacion::mostrarNotificacion(){
	Usuario *usuarioRespuesta = getUserRespuesta();
	Usuario *usuarioPregunta = getUserPregunta();

	cout << usuarioPregunta->getNombre();
	cout <<", el usuario " << usuarioRespuesta->getNombre();
	cout << " ha respondido tu pregunta ";
	cout << respuesta->getPregunta()->getTitulo();
	cout << endl;
}
