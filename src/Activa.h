/*
 * Activa.h
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#ifndef ACTIVA_H_
#define ACTIVA_H_
#include "Pregunta.h"
#include <iostream>
using namespace std;

class Activa : public Estado {
private:
	static Activa * Instancia;
	Activa();
public:
	void suspenderPregunta(Pregunta * preg);
	void chequearEstadoSegunTiempoTranscurridoDesdeUltimaRespuesta(Pregunta * preg);
	void marcarConSolucion(Pregunta * preg);
	void recibirRespuesta(Pregunta * preg);
	bool emiteNotificacion();
	bool admiteRespuesta();
	string getTipoEstado();
	~Activa();
	static Activa * getInstancia();
};

#endif /* ACTIVA_H_ */
