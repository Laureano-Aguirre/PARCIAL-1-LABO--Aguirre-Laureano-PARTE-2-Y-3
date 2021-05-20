/*
 * Bicicleta.c
 *
 *  Created on: 20 may. 2021
 *      Author: Lau
 */

#include "Bicicleta.h"
#include "Aguirre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define VACIO 1
#define OCUPADO 0


void hardcodearBicicletas(eBicicleta arrayBicicleta [], int tam)
{
	int i;

	eBicicleta bicicletasLocal[5]={{25,"Vinta", 21, "Rojo",OCUPADO},
            						{26, "Molet", 22, "Verde",OCUPADO},
									{27, "Boula", 23, "Amarillo",OCUPADO},
									{28, "Penco", 24, "Celeste",OCUPADO},
									{29, "Matel", 25, "Naranja",OCUPADO}};


	for(i=0;i<tam;i++)
	{
		arrayBicicleta[i]=bicicletasLocal[i];
	}
}

int buscarBicicletaID(eBicicleta arrayBicicleta[], int tam, int idBicicleta)
{
	int i;
	int pos;

	pos=-1;

	for(i=0;i<tam;i++)
	{
		if(arrayBicicleta[i].idBicicleta==idBicicleta)
		{
			pos=i;
			break;
		}
	}
	return pos;
}

void mostrarBicicleta(eBicicleta arrayBicicleta[], int pB)
{
	printf("\n%d %14s %15d %15s", arrayBicicleta[pB].idBicicleta,
	                           arrayBicicleta[pB].marca,
	                           arrayBicicleta[pB].rodadoBicicleta,
							   arrayBicicleta[pB].color);
}

void mostrarBicicletas(eBicicleta arrayBicicleta[], int tam)
{
	int i;

	puts("\nID           marca           rodado           color");
	for(i=0;i<tam;i++)
	{
		if(arrayBicicleta[i].isEmpty==OCUPADO)
		{
			mostrarBicicleta(arrayBicicleta, i);
		}
	}
}



