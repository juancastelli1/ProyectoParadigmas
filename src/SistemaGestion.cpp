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
	Pregunta pregunta(titulo, descripcion, url_imagen, user_preg);
	preguntas.Insert(preguntas.end(), pregunta);
}
void SistemaGestion::agregarRespuesta(Usuario *user_resp, Pregunta *pregunta, string descripcion, string url_imagen){

}

void SistemaGestion::agregarUsuario(string nombre, string apellido, string pais_origen, string email, string contrasenia, string url_imagen){
	Usuario usuario(nombre, apellido, pais_origen, email, contrasenia, url_imagen);
	usuarios.Insert(usuarios.end(), usuario);

}
void SistemaGestion::suspenderCuenta(Usuario *user){

}
