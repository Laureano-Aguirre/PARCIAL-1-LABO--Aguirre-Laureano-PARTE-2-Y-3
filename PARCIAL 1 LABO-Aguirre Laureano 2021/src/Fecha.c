/*
 * Fecha.c
 *
 *  Created on: 19 may. 2021
 *      Author: Lau
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Fecha.h"
#include "Aguirre.h"
#define VACIO 1
#define OCUPADO 0

void hardcodearFecha(eFecha arrayFecha[], int tam)
{
	int i;
	int contador;

	contador=0;

	for(i=0;i<tam;i++)
	{
		arrayFecha[i].isEmpty=VACIO;
		arrayFecha[i].idFecha=contador++;
	}
}

int buscarLibreFecha(eFecha arrayFecha[], int tam)
{
	int i;
	int retorno;

	retorno=-1;

	for(i=0;i<tam;i++)
	{
		if(arrayFecha[i].isEmpty==VACIO)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}

int validarDia(int dia)
{
	int retornoD;

	retornoD=1;

	while(dia>31 || dia<1)
	{
		puts("\n Dia ingresado incorrecto");
		retornoD=-1;
	}
	return retornoD;
}

int validarMes(int mes)
{
	int retornoM;

	retornoM=1;

	while(mes>12 || mes<1)
	{
		puts("\n Mes ingresado incorrecto");
		retornoM=-1;
	}
	return retornoM;
}
int validarAnio(int anio)
{
	int retornoA;

	retornoA=1;

	while(anio>2022 || anio<2021)
	{
		puts("\n Anio ingresado incorrecto");
		retornoA=-1;
	}
	return retornoA;
}
