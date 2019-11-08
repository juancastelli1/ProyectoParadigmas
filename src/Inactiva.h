/*
 * Inactiva.h
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#ifndef INACTIVA_H_
#define INACTIVA_H_
#include "Pregunta.h"
#include <iostream>
using namespace std;

class Inactiva : public Estado {
private:
	static Inactiva * Instancia;
	Inactiva();
public:
	void suspenderPregunta(Pregunta * preg);
	void chequearEstadoSegunTiempoTranscurridoDesdeUltimaRespuesta(Pregunta * preg);
	void marcarConSolucion(Pregunta * preg);
	void recibirRespuesta(Pregunta * preg);
	bool emiteNotificacion();
	bool admiteRespuesta();
	string getTipoEstado();
	~Inactiva();
	static Inactiva * getInstancia();
};

#endif /* INACTIVA_H_ */
