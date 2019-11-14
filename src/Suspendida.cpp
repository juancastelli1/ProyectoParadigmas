/*
 * Suspendida.cpp
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#include "Suspendida.h"

Suspendida * Suspendida::Instancia = NULL;

Suspendida::Suspendida(){}
Suspendida * Suspendida::getInstancia(){
	 if (Instancia == NULL)
	    {
	        Instancia = new Suspendida();
	    }
	    return Instancia;
}
string Suspendida::getTipoEstado(){
	return "Suspendida";
}
bool Suspendida::emiteNotificacion(){
	return false;
}
bool Suspendida::admiteRespuesta(){
	return true;
}
void Suspendida::suspenderPregunta(Pregunta * preg){
	// Mantener estado
}
void Suspendida::marcarConSolucion(Pregunta * preg){
	// Mantener estado
}
void Suspendida::recibirRespuesta(Pregunta * preg){
	// Mantener estado
}
void Suspendida::chequearEstadoSegunTiempoTranscurridoDesdeUltimaRespuesta(Pregunta * preg){
	// MantenerEstado
}
Suspendida::~Suspendida(){
	delete Instancia;
}
