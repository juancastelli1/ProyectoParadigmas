/*
 * Solucionada.h
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#ifndef SOLUCIONADA_H_
#define SOLUCIONADA_H_
#include "Estado.h"
#include "Pregunta.h"
#include <iostream>
using namespace std;

class Solucionada : public Estado {
private:
	static Solucionada * Instancia;
	Solucionada();
public:
	void suspenderPregunta(Pregunta * preg);
	void chequearEstadoSegunTiempoTranscurridoDesdeUltimaRespuesta(Pregunta * preg);
	void marcarConSolucion(Pregunta * preg);
	void recibirRespuesta(Pregunta * preg);
	bool emiteNotificacion();
	bool admiteRespuesta();
	string getTipoEstado();
	~Solucionada();
	static Solucionada * getInstancia();
};

#endif /* SOLUCIONADA_H_ */
