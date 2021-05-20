/*
 * Fecha.h
 *
 *  Created on: 19 may. 2021
 *      Author: Lau
 */

#ifndef FECHA_H_
#define FECHA_H_
typedef struct
{
	int idFecha;
	int dia;
	int mes;
	int anio;
	int isEmpty;
}eFecha;

void hardcodearFecha(eFecha arrayFecha[], int tam);
int buscarLibreFecha(eFecha arrayFecha[], int tam);
int validarDia(int dia);
int validarMes(int mes);
int validarAnio(int anio);


#endif /* FECHA_H_ */
