/*
 * TrabajoFechaYServicio.h
 *
 *  Created on: 19 may. 2021
 *      Author: Lau
 */

#ifndef TRABAJOFECHAYSERVICIO_H_
#define TRABAJOFECHAYSERVICIO_H_
#include "Servicios.h"
#include "ArrayTrabajo.h"
#include "Fecha.h"

int buscarServicioTrabajo(eTrabajo arrayTrabajo[], int pT, eServicios arrayServicios [], int tam);
int buscarFechaTrabajo(eTrabajo arrayTrabajo[], int pT, eFecha arrayFecha[], int tam);
int buscarBicicletaTrabajo(eTrabajo arrayTrabajo[], int pT, eBicicleta arrayBicicleta[],int tam);
void altaTrabajo(eTrabajo arrayTrabajo[], int tamT, eServicios arrayServicios[], int tamS, eFecha arrayFecha[], int tamF, eBicicleta arrayBicicleta[], int tamB);
void modificarTrabajo(eTrabajo arrayTrabajo[], int tamT, eServicios arrayServicios[], int tamS, eFecha arrayFecha[], int tamF, eBicicleta arrayBicicleta[], int tamB);
void mostrarTrabajos(eTrabajo arrayTrabajo[], int tamT, eServicios arrayServicios[], int tamS, eFecha arrayFecha[], int tamF, eBicicleta arrayBicicleta[], int tamB);
void mostrarTrabajo(eTrabajo arrayTrabajo[], int pT, eServicios arrayServicios[], int pS, eFecha arrayFecha[], int pF,eBicicleta arrayBicicleta[], pB);
void borrarTrabajo(eTrabajo arrayTrabajo[], int tamT, eServicios arrayServicios[], int tamS, eFecha arrayFecha[], int tamF, eBicicleta arrayBicicleta[], int tamB);
void cantidadTotalPesos(eTrabajo arrayTrabajo[], int tamT, eServicios arrayServicios[], int tamS);
void MostrarOrdenPorMarca(eBicicleta arrayBicicleta[], int tamB, eTrabajo arrayTrabajo[], int tamT, eServicios arrayServicios[], int tamS, eFecha arrayFecha[], int tamF);
void mostrarServicioBicicleta(eServicios arrayServicios, int pS, eBicicleta arrayBicicleta[], int pB);
void mostrarServiciosBicicleta(eServicios arrayServicios, int pS, eBicicleta arrayBicicleta[], int pB);

#endif /* TRABAJOFECHAYSERVICIO_H_ */
