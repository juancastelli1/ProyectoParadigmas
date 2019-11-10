/*
 * Usuario.cpp
 *
 *  Created on: 10 nov. 2019
 *      Author: nicop
 */

#include "Usuario.h"

Usuario::Usuario(string nombre, string apellido, string pais_origen, string  email, string password, string url_imagen) {
	this->nombre = nombre;
	this->apellido = apellido;
	this->pais_origen = pais_origen;
	this->email = email;
	this->password = password;
	this->url_imagen = url_imagen;
}

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}
void Usuario::verNotificacion(){
	for(unsigned int i = 0; i != notificacion.end(); ++i){
		notificacion[i].mostrarNotificacion();
	}

}
void Usuario::crearRespuesta(Pregunta pregunta, string titulo, string descripcion, string url_imagen, Usuario *usuario){
	if(pregunta->admiteRespuesta()){
		//Respuesta *respuesta = new Respuesta();
		Respuesta R1(titulo, descripcion, usuario->url_imagen, *usuario);
		R1.crearNotificacion();
		respuesta.insert(respuesta.end(), R1);
		pregunta.recibirRespuesta(R1);
	}
}
void Usuario::agregarNotificacion(Notificacion notificacion){
	notificacion.insert(notificacion.end(), notificacion);
}
