/*
 * Activa.cpp
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#include "Activa.h"
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
	preg->estado = Suspendida::getInstancia();
}
void Activa::marcarConSolucion(Pregunta * preg){

}
void Activa::recibirRespuesta(Pregunta * preg){
	if (admiteRespuesta()){
		preg->
	}
}
void Activa::chequearEstadoSegunTiempoTranscurridoDesdeUltimaRespuesta(Pregunta * preg){
	if(preg->getMesesDesdeUltimaRespuesta()>=6){
		preg->estado = Inactiva::getInstancia();
	}
}
Activa::~Activa(){
	delete Instancia;
}
