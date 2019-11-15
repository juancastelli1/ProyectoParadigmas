/*
 * Fecha.h
 *
 *  Created on: 10 nov. 2019
 *      Author: Angel
 */

#ifndef FECHA_H_
#define FECHA_H_
#include <iostream>
using namespace std;

class Fecha {
private:
	int dia;
	int mes;
	int anio;
	bool esAnioBisciesto(int a);
	bool Validar();
public:
	Fecha(int d, int m, int a);
	Fecha();
	Fecha(const Fecha &f1);
	virtual ~Fecha();
	int DiasDelMes();
	void incrementarFecha(int cantdias);
	void mostrar();
	static int diaActual();
	static int mesActual();
	static int anioActual();
	int getDia();
	int getMes();
	int getAnio();
	friend ostream& operator << (ostream & salida, Fecha f);
};


#endif /* FECHA_H_ */
