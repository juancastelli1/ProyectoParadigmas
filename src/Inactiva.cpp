/*
 * Inactiva.cpp
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#include "Inactiva.h"
Activa * Inactiva::Instancia = NULL;

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
bool Activa::emiteNotificacion(){
	return true;
}
bool Activa::admiteRespuesta(){
	return true;
}
Inactiva::~Inactiva(){
	delete Instancia;
}
