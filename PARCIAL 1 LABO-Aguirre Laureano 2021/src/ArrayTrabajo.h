/*
 * ArrayTrabajo.h
 *
 *  Created on: 13 may. 2021
 *      Author: Lau
 */

#ifndef ARRAYTRABAJO_H_
#define ARRAYTRABAJO_H_

typedef struct
{
	int id;
	int idBicicleta;
	int idServicio;
	int idFecha;
	int isEmpty;
}eTrabajo;

void hardcodearTrabajo(eTrabajo arrayTrabajo[], int tam);
int buscarLibreTrabajo(eTrabajo arrayTrabajo[], int tam);
int trabajo_len(eTrabajo arrayTrabajo[], int tam);
int buscarTrabajoID(eTrabajo arrayTrabajo[], int tam, int id);
int asignarTrabajoID(eTrabajo arrayTrabajo[], int tam);



#endif /* ARRAYTRABAJO_H_ */
