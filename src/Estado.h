/*
 * Estado.h
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#ifndef ESTADO_H_
#define ESTADO_H_
#include "Pregunta.h"
#include <iostream>
using namespace std;

class Estado {
public:
	void suspenderPregunta(Pregunta * preg) = 0;
	void chequearEstadoSegunTiempoTranscurridoDesdeUltimaRespuesta(Pregunta * preg) = 0;
	void marcarConSolucion(Pregunta * preg) = 0;
	void recibirRespuesta(Pregunta * preg) = 0;
	bool emiteNotificacion() = 0;
	bool admiteRespuesta() = 0;
	string getTipoEstado() = 0;

};

#endif /* ESTADO_H_ */
