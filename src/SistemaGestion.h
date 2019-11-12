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
	vector<Usuario> usuarios;
	vector<Pregunta> preguntas;
public:
	SistemaGestion();
	virtual ~SistemaGestion();
	void agregarPregunta(string titulo, string descripcion, string url_imagen, Usuario *user_preg);
	void agregarRespuesta(Usuario *user_resp, Pregunta *pregunta, string descripcion, string url_imagen);
	void agregarUsuario(string nombre, string apellido, string pais_origen, string email, string contrasenia, string url_imagen);
	void suspenderCuenta(Usuario *user);

};

#endif /* SISTEMAGESTION_H_ */