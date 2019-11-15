/*
 * SistemaGestion.cpp
 *
 *  Created on: 11 nov. 2019
 *      Author: Alumno
 */

#include <algorithm>
#include <vector>
#include "SistemaGestion.h"
#include "Respuesta.h"

SistemaGestion::SistemaGestion() {
	// TODO Auto-generated constructor stub

}

SistemaGestion::~SistemaGestion() {
	// TODO Auto-generated destructor stub
}

void SistemaGestion::agregarPregunta(string titulo, string descripcion, Usuario *user_preg, string url_imagen){
	Pregunta* pregunta = new Pregunta(titulo, descripcion, user_preg, url_imagen);
	preguntas.push_back(pregunta);
	user_preg->agregarPregunta(pregunta);
}

void SistemaGestion::agregarPregunta(string titulo, string descripcion, Usuario *user_preg, vector<string> tags, string url_imagen) {
	Pregunta* pregunta = new Pregunta(titulo, descripcion, user_preg, tags, url_imagen);
	preguntas.push_back(pregunta);
	user_preg->agregarPregunta(pregunta);
}

void SistemaGestion::agregarPregunta(string titulo, string descripcion, Usuario *user_preg, vector<string> tags, Fecha fec, string url_imagen) {
	Pregunta* pregunta = new Pregunta(titulo, descripcion, user_preg, tags,fec, url_imagen);
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
	user->suspenderUser();
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
void SistemaGestion::mostrarListaUsers() const {
	cout << "---Usuarios---" << endl;
	for (Usuario* user : this->usuarios) {
		user->mostrarInfoUser();
	}
	cout << "--------------" << endl;
	cout << endl;
}

void SistemaGestion::mostrarListaPreguntas() const {
	cout << "---Lista de preguntas---" << endl;
	for (Pregunta* p : this->preguntas) {
		p->mostrarInfoPregunta();
		cout << endl;
		cout << "------------------------" << endl;
		cout << endl;
	}
	cout << endl;
}

void SistemaGestion::mostrarListaPreguntas(string tag) const {
	cout << "---Lista de preguntas con el tag " << tag << "---" << endl;

	vector<string> tagsPregunta;
	for (Pregunta* p : this->preguntas) {
		// Chequear existencia del tag en la pregunta
		tagsPregunta = p->getTags();
		if(std::find(tagsPregunta.begin(), tagsPregunta.end(), tag) != tagsPregunta.end()) {
			p->mostrarInfoPregunta();
		}
	}
	cout << "------------------------" << endl;
	cout << endl;
}
void SistemaGestion::darLike(Respuesta* respuesta) {
	respuesta->darLike();
}

void SistemaGestion::agregarTag(Pregunta* pregunta, string tag) {
	pregunta->agregarTag(tag);
}

Respuesta* SistemaGestion::buscarRespuesta(Pregunta* pregunta, int id_respuesta) const {
	for (Respuesta* respuesta : pregunta->getRespuestas()) {
		if (respuesta->getIdRespuesta() == id_respuesta) {
			return respuesta;
		}
	}
	return NULL;
}
