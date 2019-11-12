/*
 * Respuesta.h
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#ifndef RESPUESTA_H_
#define RESPUESTA_H_
#include "Pregunta.h"
#include "Fecha.h"
#include "Usuario.h"
#include <string>
using namespace std;


class Respuesta {
private:
	string titulo;
	string descripcion;
	string url_imagen;
	Fecha fecha;
	int likes;
	Pregunta *pregunta;
	Usuario *userRespuesta;

public:
	Respuesta();
	virtual ~Respuesta();
	int getLikes();
	void crearNotificacion();
	Usuario* getUserResp();
	Usuario* getUserPreg();
	Fecha getFecha();
};

#endif /* RESPUESTA_H_ */
