/*
 * Activa.cpp
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#include "Activa.h"
#include "Inactiva.h"
#include "Suspendida.h"
#include "Solucionada.h"

Activa * Activa::Instancia = NULL;

Activa::Activa(){}
Activa * Activa::getInstancia(){
	 if (Instancia == NULL)
	    {
	        Instancia = new Activa();
	    }
	    return Instancia;
}
bool Activa::emiteNotificacion(){
	return true;
}
bool Activa::admiteRespuesta(){
	return true;
}
string Activa::getTipoEstado(){
	return "Activa";
}
void Activa::suspenderPregunta(Pregunta * preg){
	preg->setEstado(Suspendida::getInstancia());
}
void Activa::marcarConSolucion(Pregunta * preg){
	preg->setEstado(Solucionada::getInstancia());
}
void Activa::recibirRespuesta(Pregunta * preg){
	// Mantener estado
}
void Activa::chequearEstadoSegunTiempoTranscurridoDesdeUltimaRespuesta(Pregunta * preg){
	if(preg->getMesesDesdeUltimaRespuesta()>=6){
		preg->setEstado(Inactiva::getInstancia());
	}
}
Activa::~Activa(){
	delete Instancia;
}
