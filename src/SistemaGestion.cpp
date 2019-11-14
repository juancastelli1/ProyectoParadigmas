/*
 * SistemaGestion.cpp
 *
 *  Created on: 11 nov. 2019
 *      Author: Alumno
 */

#include "SistemaGestion.h"

SistemaGestion::SistemaGestion() {
	// TODO Auto-generated constructor stub

}

SistemaGestion::~SistemaGestion() {
	// TODO Auto-generated destructor stub
}

void SistemaGestion::agregarPregunta(string titulo, string descripcion, string url_imagen, Usuario *user_preg){
	Pregunta* pregunta = new Pregunta(titulo, descripcion, url_imagen, user_preg);
	preguntas.push_back(pregunta);
	user_preg->agregarPregunta(pregunta);
}
void SistemaGestion::agregarRespuesta(Usuario *user_resp, Pregunta *pregunta, string titulo, string descripcion, string url_imagen){
	user_resp->crearRespuesta(pregunta, titulo, descripcion, url_imagen, user_resp);
}

void SistemaGestion::agregarUsuario(string nombre, string apellido, string pais_origen, string email, string contrasenia, string url_imagen){
	Usuario* usuario = new Usuario(nombre, apellido, pais_origen, email, contrasenia, url_imagen);
	usuarios.push_back(usuario);

}
void SistemaGestion::suspenderCuenta(Usuario *user){

}

Usuario* SistemaGestion::buscarUser(int id_user) const {
	for(Usuario* u : this->usuarios) {
		if(u->getIdUser() == id_user) {
			// Encuentra al usuario
			return u;
		}
	}
	// No existe el usuario con este id
	return NULL;
}
Pregunta* SistemaGestion::buscarPregunta(int id_pregunta) const {
	for(Pregunta* p : this->preguntas) {
		if (p->getIdPregunta() == id_pregunta) {
			// Encuentra la pregunta
			return p;
		}
	}
	// No existe la pregnta con este id
	return NULL;
}
