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
#include "time.h"
#include "Fecha.h"
class Estado;
class Respuesta;
class Usuario;
using namespace std;

class Pregunta {
	static int autonum;
	int id_pregunta;
	string titulo;
	string descripcion;
	string url_imagen;
	Fecha fecha;
	vector<string> tags;
	Usuario * user_pregunta;
	vector<Respuesta*> respuestas;
	Estado* estado;
	Respuesta * solucion;
public:
	Pregunta(string titulo, string descripcion, Usuario* user_preg, string url_imagen = "no img" );
	Pregunta(string titulo, string descripcion, Usuario* user_preg, vector<string> tags, string url_imagen = "no img" );
	~Pregunta();

	Usuario* getUserPregunta() const;
	vector<Respuesta*> getRespuestas() const;
	vector<string> getTags() const;
	void mostrarInfoPregunta() const; // Imprime por pantalla la informacion de la pregunta

	int getMesesDesdeUltimaRespuesta() const;
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

	string getTitulo() const;
	string getDescripcion() const;
	string getUrlImagen() const;
	Fecha getFecha() const;
	int getIdPregunta() const;
	void ordernarRespuestas();
	void mostrarRespuestas();
};

#endif /* PREGUNTA_H_ */
