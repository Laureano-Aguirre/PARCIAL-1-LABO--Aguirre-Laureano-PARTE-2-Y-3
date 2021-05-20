/*
 * Servicios.h
 *
 *  Created on: 13 may. 2021
 *      Author: Lau
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_
#define TAMS 25
typedef struct
{
	int id;
	char descripcion[25];
	float precio;
	int isEmpty;
}eServicios;

void hardcodearServicios(eServicios arrayServicios[], int tam);
int buscarServiciosID(eServicios arrayServicios [], int tam, int id);
void mostrarServicios(eServicios arrayServicios[], int tam);
void mostrarServicio(eServicios arrayServicios[], int pS);


#endif /* SERVICIOS_H_ */
