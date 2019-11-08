/*
 * Solucionada.cpp
 *
 *  Created on: 8 de nov. de 2019
 *      Author: Alumno
 */

#include "Solucionada.h"

Solucionada * Solucionada::Instancia = NULL;

Solucionada::Solucionada(){}
Solucionada * Solucionada::getInstancia(){
	 if (Instancia == NULL)
	    {
	        Instancia = new Solucionada();
	    }
	    return Instancia;
}
string Solucionada::getTipoEstado(){
	return "Solucionada";
}
bool Solucionada::emiteNotificacion(){
	return false;
}
bool Solucionada::admiteRespuesta(){
	return false;
}
Solucionada::~Solucionada(){
	delete Instancia;
}
