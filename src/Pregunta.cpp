/*
 * Pregunta.cpp
 *
 *  Created on: 10 nov. 2019
 *      Author: Angel
 */

#include "Pregunta.h"

Pregunta::Pregunta() {
	// TODO Auto-generated constructor stub

}
Usuario* Pregunta::getUserPregunta() const{
	return user_pregunta;
}
vector<Respuesta*> Pregunta::getRespuestas() const{
	return respuestas;
}
vector<string> Pregunta::getTags() const{
	return tags;
}
void Pregunta::suspenderPregunta(){
	estado->suspenderPregunta(this);
}
bool Pregunta::admiteRespuesta() const{
	return estado->admiteRespuesta();
}
bool Pregunta::emiteNotificacion() const{
	return estado->emiteNotificacion();
}
string Pregunta::getTipoEstado() const{
	return estado->getTipoEstado();
}
int Pregunta::getMesesDesdeUltimaRespuesta() const{
	int meses;
	Fecha f = respuestas.back()->getFecha();
	while(f.mes != Fecha::mesActual() & f.anio != Fecha::anioActual()){
		f.incrementarFecha(f.DiasDelMes());
		meses = 1;
	}
	return meses;
}
void Pregunta::recibirRespuesta(Respuesta* resp){
	respuestas.push_back(resp);
}
void Pregunta::marcarConSolucion(Respuesta* resp){
	solucion = resp;
}
void Pregunta::chequearEstadoSegunTiempo(){
	if (getTipoEstado() == "Activa"){
		estado->chequearEstadoSegunTiempoTranscurridoDesdeUltimaRespuesta(this);
	}
}
void Pregunta::suspenderPregunta(){
	estado->suspenderPregunta(this);
}
void Pregunta::setEstado(Estado* est){}
Pregunta::~Pregunta() {
	// TODO Auto-generated destructor stub
}

