/*
 * Inactiva.cpp
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#include "Inactiva.h"
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
