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
string Activa::getTipoEstado(){
	return "Activa";
}
bool Activa::emiteNotificacion(){
	return true;
}
bool Activa::admiteRespuesta(){
	return true;
}
Activa::~Activa(){
	delete Instancia;
}
