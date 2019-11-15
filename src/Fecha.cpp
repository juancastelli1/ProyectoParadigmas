/*
 * FechaClase.cpp
 *
 *  Created on: 29 de ago. de 2019
 *      Author: Alumno
 */

#include "Fecha.h"
#include <ctime>
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

Fecha::Fecha(int d, int m, int a) {
	this->dia = d;
	this->mes = m;
	this->anio = a;
	if(Validar() != true){
		dia = 1;
		mes = 1;
		anio = 2000;
	};
}
Fecha::Fecha() {
	this->dia = diaActual();
	this->mes = mesActual();
	this->anio = anioActual();
	if(Validar() != true){
		dia = 1;
		mes = 1;
		anio = 2000;
	};
}
Fecha::Fecha(const Fecha &f1){
	dia = f1.dia;
	mes = f1.mes;
	anio = f1.anio;
	if(Validar() != true){
		dia = 1;
		mes = 1;
		anio = 2000;
	};
}
Fecha::~Fecha() {
	dia = -1;
	mes = -1;
	anio = -1;
}
int Fecha::DiasDelMes(){
	switch(mes){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;
		case 2:
			if(this->esAnioBisciesto(anio)){
				return 29;
			}else{
				return 28;
			}
			break;
	}
	return -1;
}
bool Fecha::esAnioBisciesto(int a){
	if(a%100 == 0){
		if(a%400 == 0){
			return true;
		}
	}else{
		if(a%4 == 0){
			return true;
		}
	}
	return false;
}
void Fecha::mostrar(){
	cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
bool Fecha::Validar() {
	if (anio>=0 && anio<=2019){
		if(mes<=12 && mes>=1){
			switch(mes){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if(dia>=1 && dia<=31){
					return true;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if(dia>=1 && dia<=30){
					return true;
				}
				break;
			case 2:
				if(this->esAnioBisciesto(anio)){
					if(dia>=1 && dia<=29){
						return true;
					}
				}else{
					if(dia>=1 && dia<=28){
						return true;
					}
				}
				break;
			}
		}
	}
	return false;
}

void Fecha::incrementarFecha(int cantdias){
	int diastot = dia + cantdias;
	while (diastot >= 365){
		if(this->esAnioBisciesto(anio)){
			diastot = diastot - 366;
		}else{
			diastot = diastot - 365;
		}
		anio = anio + 1;
	}
	while (diastot > DiasDelMes()){
		diastot = diastot - DiasDelMes();
		mes = mes + 1;
	}
	dia = diastot;
}
int Fecha::diaActual(){
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	return timePtr->tm_mday;
}
int Fecha::mesActual(){
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	return timePtr->tm_mon+1;
}
int Fecha::anioActual(){
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	return timePtr->tm_year+1900;
}
int Fecha::getDia(){
	return dia;
}
int Fecha::getMes(){
	return mes;
}
int Fecha::getAnio(){
	return anio;
}

ostream& operator << (ostream & salida, Fecha f) {
	salida << f.dia << "/" << f.mes << "/" << f.anio;
	return salida;
}
