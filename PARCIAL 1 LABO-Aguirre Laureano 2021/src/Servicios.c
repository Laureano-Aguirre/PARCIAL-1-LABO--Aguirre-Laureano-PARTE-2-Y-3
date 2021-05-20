/*
 * Servicios.c
 *
 *  Created on: 13 may. 2021
 *      Author: Lau
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Servicios.h"
#include "Aguirre.h"
#define TS 25
#define VACIO 1
#define OCUPADO 0


void hardcodearServicios(eServicios arrayServicios[], int tam)
{

    int i;

    eServicios ServiciosLocal[4]={{20000,"Limpieza", 250, OCUPADO},
                                       {20001, "Parche", 300, OCUPADO},
                                       {20002, "Centrado", 400, OCUPADO},
                                       {20003, "Cadena", 350, OCUPADO}};

    for(i=0; i<tam; i++)
    {
        arrayServicios[i]=ServiciosLocal[i];
    }
}

int buscarServiciosID(eServicios arrayServicios [], int tam, int id)
{
	int i;
	int pos;

	pos=-1;

	for(i=0;i<tam;i++)
	{
		if(arrayServicios[i].id==id)
		{
			pos=i;
			break;
		}
	}
	return pos;
}

void mostrarServicio(eServicios arrayServicios[], int pS)
{
    printf("\n%d %14s %15.2f", arrayServicios[pS].id,
                               arrayServicios[pS].descripcion,
                               arrayServicios[pS].precio);

}

void mostrarServicios(eServicios arrayServicios[], int tam)
{
    int i;

    puts("ID           servicio          precio");
    for(i=0;i<tam;i++)
    {
        if(arrayServicios[i].isEmpty==OCUPADO)
        {
            mostrarServicio(arrayServicios, i);
        }
    }
}
