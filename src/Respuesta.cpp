/*
 * Respuesta.cpp
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#include "Respuesta.h"
#include "Pregunta.h"
#include "Notificacion.h"
#include "Usuario.h"

int Respuesta::autonum = 0;

Respuesta::Respuesta(
		Pregunta *pregunta,
		string titulo,
		string descripcion,
		Usuario *userRespuesta,
		string url_imagen
		)
{
	this->id_respuesta = autonum++;
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
Fecha Respuesta::getFecha(){
	return fecha;
}
Usuario* Respuesta::getUserPreg(){
	return pregunta->getUserPregunta();
}

Usuario* Respuesta::getUserResp(){
	return  userRespuesta;
}

void Respuesta::crearNotificacion(){

	if (pregunta->emiteNotificacion() ) {

		Notificacion* notificacion = new Notificacion(this);

		Usuario *usuario_pregunta = pregunta->getUserPregunta();
		usuario_pregunta->agregarNotificacion(notificacion);

	}
}


Pregunta* Respuesta::getPregunta() const{
	return this->pregunta;
}

int Respuesta::getIdRespuesta() const {
	return id_respuesta;
}

void Respuesta::darLike() {
	this->likes++;
}

bool Respuesta::operator< (const Respuesta &otraRespuesta) const {
	return this->likes < otraRespuesta.likes;
}

void Respuesta::mostrarInfoRespuesta() const{
	cout << this->userRespuesta->getNombre()
		 << " "
		 << this->userRespuesta->getApellido()
		 << " escribio una respuesta" << endl;

	cout << "Titulo Respuesta: " << this->titulo << endl;
	cout << "Descripcion: " << this->descripcion << endl;
	cout << "Url Imagen: " << this->url_imagen << endl;
	cout << "Id Respuesta: " << this->id_respuesta << endl;
	cout << "Fecha de respuesta: " << this->fecha << endl;
	cout << "Likes: " << this->likes << endl;
	cout << endl;
}
