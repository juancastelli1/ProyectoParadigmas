/*
 * Pregunta.cpp
 *
 *  Created on: 10 nov. 2019
 *      Author: Angel
 */

#include <algorithm>
#include "Pregunta.h"
#include "Respuesta.h"
#include "Usuario.h"
#include "Estado.h"
#include "Activa.h"
#include "Fecha.h"

int Pregunta::autonum = 0;

Pregunta::Pregunta(string titulo, string descripcion, Usuario* user_preg, string url_imagen) {
	this->id_pregunta = autonum++;
	this->titulo = titulo;
	this->descripcion = descripcion;
	this->url_imagen = url_imagen;
	this->user_pregunta = user_preg;
	this->fecha = Fecha();
	this->estado = Activa::getInstancia();
	this->solucion = NULL;
}

Pregunta::Pregunta(string titulo, string descripcion, Usuario* user_preg, vector<string> tags, string url_imagen) {
	this->id_pregunta = autonum++;
	this->titulo = titulo;
	this->descripcion = descripcion;
	this->url_imagen = url_imagen;
	this->user_pregunta = user_preg;
	this->fecha = Fecha();
	this->estado = Activa::getInstancia();
	this->solucion = NULL;
	this->tags = tags;
}
Pregunta::Pregunta(string titulo, string descripcion, Usuario* user_preg, vector<string> tags, Fecha fec, string url_imagen) {
	this->id_pregunta = autonum++;
	this->titulo = titulo;
	this->descripcion = descripcion;
	this->url_imagen = url_imagen;
	this->user_pregunta = user_preg;
	this->fecha = fec;
	this->estado = Activa::getInstancia();
	this->solucion = NULL;
	this->tags = tags;
}
Usuario* Pregunta::getUserPregunta() const{
	return user_pregunta;
}
vector<Respuesta*> Pregunta::getRespuestas() const{
	return respuestas;
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
	int meses = 0;
	Fecha f;
	if(respuestas.size() > 0){
		f = respuestas.back()->getFecha();
	}
	else {
		f = this->fecha;
	}
	meses = ((Fecha::anioActual() - f.getAnio())-1)*12;
	meses += 12 - f.getMes();
	meses += Fecha::mesActual();
	return meses;
}
void Pregunta::recibirRespuesta(Respuesta* resp){
	respuestas.push_back(resp);
	estado->recibirRespuesta(this);
}
void Pregunta::marcarConSolucion(Respuesta* resp){
	solucion = resp;
	estado->marcarConSolucion(this);
}
void Pregunta::chequearEstadoSegunTiempo(){
	if (getTipoEstado() == "Activa"){
		estado->chequearEstadoSegunTiempoTranscurridoDesdeUltimaRespuesta(this);
	}
}
void Pregunta::setEstado(Estado* est){
	estado = est;
}
Pregunta::~Pregunta() {
	// TODO Auto-generated destructor stub
}

string Pregunta::getTitulo() const {
	return this->titulo;
}
string Pregunta::getDescripcion() const {
	return this->descripcion;
}
string Pregunta::getUrlImagen() const {
	return this->url_imagen;
}
Fecha Pregunta::getFecha() const {
	return this->fecha;
}
int Pregunta::getIdPregunta() const {
	return id_pregunta;
}
vector<string> Pregunta::getTags() const {
	return this->tags;
}

void Pregunta::mostrarInfoPregunta() {
	this->chequearEstadoSegunTiempo();
	cout << this->user_pregunta->getNombre()
		 << " "
		 << this->user_pregunta->getApellido()
		 << " hizo una pregunta" << endl;
	cout << "Titulo pregunta: " << this->titulo << endl;
	cout << "Descripcion: " << this->descripcion << endl;
	cout << "Estado: " << this->estado->getTipoEstado() << endl;
	cout << "Url Imagen: " << this->url_imagen << endl;
	cout << "Fecha: " << this->fecha << endl;
	cout << "Id Pregunta: " << this->id_pregunta << endl;
	cout << "Tags: -";
	for(string tag: this->tags) {
		cout << tag << "-";
	}

	cout << endl;
}

void Pregunta::ordernarRespuestas() {
	std::sort(respuestas.begin(), respuestas.end(),  greater<Respuesta*>());
}

void Pregunta::mostrarRespuestas() {
	this->ordernarRespuestas();

	cout << "---Lista de respuestas---" << endl;

	if (this->solucion != NULL) {
		cout<<"MARCADA COMO SOLUCION"<<endl;
		this->solucion->mostrarInfoRespuesta();
	}
	for (Respuesta* respuesta : this->respuestas) {
		if(respuesta!=solucion){
			respuesta->mostrarInfoRespuesta();
		}
	}
	cout << "------------------------" << endl;
	cout << endl;
}

void Pregunta::agregarTag(string tag) {
	this->tags.push_back(tag);
}
