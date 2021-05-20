/*
 * ArrayTrabajo.C
 *
 *  Created on: 13 may. 2021
 *      Author: Lau
 */
#include "ArrayTrabajo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Aguirre.h"
#define VACIO 1
#define OCUPADO 0

void hardcodearTrabajo(eTrabajo arrayTrabajo[], int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		arrayTrabajo[i].isEmpty=VACIO;
	}
}

int buscarLibreTrabajo(eTrabajo arrayTrabajo[], int tam)
{
	int i;
	int retorno;

	retorno=-1;

	for(i=0;i<tam;i++)
	{
		if(arrayTrabajo[i].isEmpty==VACIO)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}

int trabajo_len(eTrabajo arrayTrabajo[], int tam)
{
	int i;
	int len;

	len=0;

	for(i=0;i<tam;i++)
	{
		if(arrayTrabajo[i].isEmpty==OCUPADO)
		{
			len++;
		}
	}
	return len;
}

int buscarTrabajoID(eTrabajo arrayTrabajo[], int tam, int id)
{
	int i;
	int pos;

	pos=-1;

	for(i=0;i<tam;i++)
	{
		if(arrayTrabajo[i].id==id)
		{
			pos=i;
			break;
		}
	}
	return pos;
}
int asignarTrabajoID(eTrabajo arrayTrabajo[], int tam)
{
	int id;
	int i;
	int max;

	max=-1;

	for(i=0;i<tam;i++)
	{
		if(arrayTrabajo[i].id>max)
		{
			max=arrayTrabajo[i].id;
		}
	}
	id=max+1;

	return id;
}
