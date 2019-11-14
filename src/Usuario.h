/*
 * Usuario.h
 *
 *  Created on: 10 nov. 2019
 *      Author: nicop
 */

#ifndef USUARIO_H_
#define USUARIO_H_

class Pregunta;
class Respuesta;
class Notificacion;

#include <iostream>
using namespace std;
#include <vector>

class Usuario {
private:
	static int autonum;
	int id_user;
	string nombre;
	string apellido;
	string pais_origen;
	string email;
	string password;
	string url_imagen;
	vector<Pregunta *> preguntas;
	vector<Respuesta *> respuestas;
	vector<Notificacion *> notificaciones;

public:
	Usuario(string nombre, string apellido, string pais_origen, string  email, string password, string url_imagen);
	virtual ~Usuario();
	void verNotificacion();
	void crearRespuesta(Pregunta* pregunta, string titulo,string descripcion, string url_imagen, Usuario *usuario);
	void agregarPregunta(Pregunta* pregunta);
	void agregarNotificacion(Notificacion* notificacion);
	string getNombre();
	string getApellido();
	string getPaisOrigen();
	string getEmail();
	string getPassword();
	string getUrlImagen();
	int getIdUser() const;
};

#endif /* USUARIO_H_ */
