/*
 * Notificacion.cpp
 *
 *  Created on: 11 nov. 2019
 *      Author: Alumno
 */

#include "Notificacion.h"

Notificacion::Notificacion() {
	// TODO Auto-generated constructor stub

}

Notificacion::~Notificacion() {
	// TODO Auto-generated destructor stub
}

Usuario* Notificacion::getUserRespuesta(){
	Usuario *usuario = Usuario->getUserPreg();
	return usuario;
}

Usuario* Notificacion::getUserPregunta(){
	Usuario *usuario = Usuario->getUserResp();
	return usuario;
}

void Notificacion::mostrarNotificacion(){
	Usuario *usuarioRespuesta = getUserRespuesta();
	Usuario *usuarioPregunta = getUserPregunta();
	cout<<usuarioPregunta->getNombre() <<", el usuario " << usuarioRespuesta->getNombre() << "ha respondido tu pregunta"<< respuesta->getUserPreg()->getTitulo()<<endl;
}
