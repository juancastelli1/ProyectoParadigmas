/*
 * Notificacion.h
 *
 *  Created on: 11 nov. 2019
 *      Author: Alumno
 */

#include <iostream>
using namespace std;
#include "Respuesta.h"
#include "Usuario.h"
#include <vector>

#ifndef NOTIFICACION_H_
#define NOTIFICACION_H_

class Notificacion {
	Respuesta *respuesta:
private:
	Usuario* getUserPregunta();
	Usuario* getUserRespuesta();
public:
	Notificacion();
	virtual ~Notificacion();
	void mostrarNotificacion();
};

#endif /* NOTIFICACION_H_ */
