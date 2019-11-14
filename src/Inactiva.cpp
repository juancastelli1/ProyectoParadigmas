/*
 * Inactiva.cpp
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#include "Inactiva.h"
#include "Activa.h"
#include "Suspendida.h"
#include "Solucionada.h"
Inactiva * Inactiva::Instancia = NULL;

Inactiva::Inactiva(){}
Inactiva * Inactiva::getInstancia(){
	 if (Instancia == NULL)
	    {
	        Instancia = new Inactiva();
	    }
	    return Instancia;
}
string Inactiva::getTipoEstado(){
	return "Inactiva";
}
bool Inactiva::emiteNotificacion(){
	return true;
}
bool Inactiva::admiteRespuesta(){
	return true;
}
Inactiva::~Inactiva(){
	delete Instancia;
}

void Inactiva::suspenderPregunta(Pregunta * preg) {
	preg->setEstado(Suspendida::getInstancia());
}
void Inactiva::chequearEstadoSegunTiempoTranscurridoDesdeUltimaRespuesta(Pregunta * preg) {
	// Mantener estado
}
void Inactiva::marcarConSolucion(Pregunta * preg) {
	preg->setEstado(Solucionada::getInstancia());
}
void Inactiva::recibirRespuesta(Pregunta * preg) {
	preg->setEstado(Activa::getInstancia());
}
