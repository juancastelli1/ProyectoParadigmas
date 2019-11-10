/*
 * Usuario.h
 *
 *  Created on: 10 nov. 2019
 *      Author: nicop
 */

#ifndef USUARIO_H_
#define USUARIO_H_

#include "Pregunta.h"
#include "Respuesta.h"
#include "Notificacion.h"

#include <iostream>
using namespace std;
#include <vector>

class Usuario {
private:
	string nombre;
	string apellido;
	string pais_origen;
	string email;
	string password;
	string url_imagen;
	vector<Pregunta *> pregunta;
	vector<Respuesta *> respuesta;
	vector<Notificacion> notificacion;

public:
	Usuario(string nombre, string apellido, string pais_origen, string  email, string password, string url_imagen);
	virtual ~Usuario();
	void verNotificacion();
	void crearRespuesta(Pregunta pregunta, string titulo,string descripcion, string url_imagen, Usuario *usuario);
	void agregarNotificacion(Notificacion notificacion);
};

#endif /* USUARIO_H_ */
