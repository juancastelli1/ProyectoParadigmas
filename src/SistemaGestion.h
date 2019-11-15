/*
 * SistemaGestion.h
 *
 *  Created on: 11 nov. 2019
 *      Author: Alumno
 */

#ifndef SISTEMAGESTION_H_
#define SISTEMAGESTION_H_
#include <iostream>
using namespace std;
#include "Usuario.h"
#include "Pregunta.h"
#include <vector>

class SistemaGestion {
private:
	vector<Usuario*> usuarios;
	vector<Pregunta*> preguntas;
public:
	SistemaGestion();
	virtual ~SistemaGestion();
	void agregarPregunta(string titulo, string descripcion, Usuario *user_preg, string url_imagen = "no img");
	void agregarPregunta(string titulo, string descripcion, Usuario *user_preg, vector<string> tags, string url_imagen = "no img");
	void agregarRespuesta(Usuario *user_resp, Pregunta *pregunta, string titulo, string descripcion, string url_imagen = "no img");
	void agregarUsuario(string nombre, string apellido, string pais_origen, string email, string contrasenia, string url_imagen = "no img");
	void suspenderCuenta(Usuario *user);
	Usuario* buscarUser(int id_user) const;
	Pregunta* buscarPregunta(int id_pregunta) const;
	void mostrarListaUsers() const;
	void mostrarListaPreguntas() const;
	void mostrarListaPreguntas(string tag) const;
	void darLike(Respuesta* respuesta);
	void agregarTag(Pregunta* pregunta, string tag);

};

#endif /* SISTEMAGESTION_H_ */
