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
	virtual void suspenderPregunta(Pregunta * preg) = 0;
	virtual void chequearEstadoSegunTiempoTranscurridoDesdeUltimaRespuesta(Pregunta * preg) = 0;
	virtual void marcarConSolucion(Pregunta * preg) = 0;
	virtual void recibirRespuesta(Pregunta * preg) = 0;
	virtual bool emiteNotificacion() = 0;
	virtual bool admiteRespuesta() = 0;
	virtual string getTipoEstado() = 0;
	virtual ~Estado();
};

#endif /* ESTADO_H_ */
