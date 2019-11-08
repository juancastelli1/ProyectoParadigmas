/*
 * Respuesta.cpp
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#include "Respuesta.h"

Respuesta::Respuesta(
		Pregunta *pregunta,
		string titulo,
		string descripcion,
		string url_imagen = "no img",
		Usuario *userRespuesta)
{
	this->pregunta = pregunta;
	this->titulo = titulo;
	this->descripcion = descripcion;
	this->url_imagen= url_imagen;
	this->userRespuesta = userRespuesta;

	this->fecha = Fecha(); // supongo constructor da fecha del momento
	this->likes = 0;
}

Respuesta::~Respuesta() {
	// TODO Auto-generated destructor stub
}

int Respuesta::getLikes(){
	return likes;
}

Usuario* Respuesta::getUserPreg(){
	return pregunta->getUserPregunta();
}

Usuario* Respuesta::getUserResp(){
	return  userRespuesta;
}

void Respuesta::crearNotificacion(){

	if (pregunta->emiteNotificacion() ) {

		Notificacion notificacion = new Notificacion(this);

		Usuario *usuario_pregunta = pregunta->getUserPregunta();
		usuario_pregunta->AgregarNotificacion(notificacion);

	}
}
