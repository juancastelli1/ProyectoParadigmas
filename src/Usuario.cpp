/*
 * Usuario.cpp
 *
 *  Created on: 10 nov. 2019
 *      Author: nicop
 */

#include "Usuario.h"
#include "Pregunta.h"
#include "Respuesta.h"
#include "Notificacion.h"

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
	for(Notificacion* notif : this->notificaciones) {
		notif->mostrarNotificacion();
	}

}
void Usuario::crearRespuesta(Pregunta* pregunta, string titulo, string descripcion, string url_imagen, Usuario *usuario){
	if(pregunta->admiteRespuesta()){
		Respuesta* R1 = new Respuesta(pregunta, titulo, descripcion, usuario, url_imagen);
		R1->crearNotificacion();
		respuestas.push_back(R1);
		pregunta->recibirRespuesta(R1);
	}
}
void Usuario::agregarNotificacion(Notificacion* notificacion){
	notificaciones.push_back(notificacion);
}

string Usuario::getNombre(){
	return this->nombre;
}
string Usuario::getApellido(){
	return this->apellido;
}
string Usuario::getPaisOrigen(){
	return this->pais_origen;
}
string Usuario::getEmail(){
	return this->email;
}
string Usuario::getPassword(){
	return this->password;
}
string Usuario::getUrlImagen(){
	return this->url_imagen;
}
