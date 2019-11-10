/*
 * Pregunta.h
 *
 *  Created on: 10 nov. 2019
 *      Author: Angel
 */

#ifndef PREGUNTA_H_
#define PREGUNTA_H_
#include <string>
#include <vector>
#include "Fecha.h"
#include "Estado.h"
#include "Respuesta.h"
#include "Usuario.h"
using namespace std;

class Pregunta {
	string titulo;
	string descripcion;
	string url_imagen;
	Fecha fecha;
	vector<string> tags;
	Usuario user_pregunta;
	vector<Respuesta*> respuestas;
	Estado* estado;
public:
	Pregunta();
	~Pregunta();

	Usuario* getUserPregunta() const;
	vector<Respuesta*> getRespuestas() const;
	vector<string> getTags() const;
	void mostrarInfoPregunta() const; // Imprime por pantalla la informacion de la pregunta

	int getMesesDesdeUltimaRespuesta() const;
	void ordenarRespuestas();
	void agregarTag(string tag);

	// Metodos del estado
	bool admiteRespuesta() const;
	bool emiteNotificacion() const;
	string getTipoEstado() const;
	void recibirRespuesta(Respuesta* resp);
	void marcarConSolucion(Respuesta* resp);
	void chequearEstadoSegunTiempo();
	void suspenderPregunta();
	void setEstado(Estado* est);
};

#endif /* PREGUNTA_H_ */
