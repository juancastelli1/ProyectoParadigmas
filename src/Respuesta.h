/*
 * Respuesta.h
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#ifndef RESPUESTA_H_
#define RESPUESTA_H_
#include <string>
#include "Fecha.h"
class Pregunta;
class Usuario;
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
	Respuesta(
			Pregunta *pregunta,
			string titulo,
			string descripcion,
			Usuario *userRespuesta,
			string url_imagen = "no img"
	);
	virtual ~Respuesta();
	int getLikes();
	void crearNotificacion();
	Usuario* getUserResp();
	Usuario* getUserPreg();
	Pregunta* getPregunta();
	Fecha getFecha();
};

#endif /* RESPUESTA_H_ */
