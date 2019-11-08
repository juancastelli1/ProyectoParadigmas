/*
 * Suspendida.h
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#ifndef SUSPENDIDA_H_
#define SUSPENDIDA_H_
#include "Pregunta.h"
#include <iostream>
using namespace std;

class Suspendida : public Estado {
private:
	static Suspendida * Instancia;
	Suspendida();
public:
	void suspenderPregunta(Pregunta * preg);
	void chequearEstadoSegunTiempoTranscurridoDesdeUltimaRespuesta(Pregunta * preg);
	void marcarConSolucion(Pregunta * preg);
	void recibirRespuesta(Pregunta * preg);
	bool emiteNotificacion();
	bool admiteRespuesta();
	string getTipoEstado();
	~Suspendida();
	static Suspendida * getInstancia();
};

#endif /* SUSPENDIDA_H_ */
