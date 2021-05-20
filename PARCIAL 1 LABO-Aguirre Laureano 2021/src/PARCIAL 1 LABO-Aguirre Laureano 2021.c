/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Aguirre.h"
#include "TrabajoFechaYServicio.h"
#define S 4
#define F 5
#define T 5
#define B 5

int main(void)
{
	setbuf(stdout, NULL);

	eServicios arrayServicios[S];
	eFecha arrayFecha[F];
	eTrabajo arrayTrabajo[T];
	eBicicleta arrayBicicleta[B];
	int opcion;

	hardcodearFecha(arrayFecha, F);
	hardcodearServicios(arrayServicios, S);
	hardcodearTrabajo(arrayTrabajo, T);

	do
	{
		getInt(" \n  Menu de opciones: "
				"\n 1. Alta  trabajo"
				"\n 2. Modificacion trabajo"
				"\n 3. Baja trabajo"
				"\n 4. Listado trabajos"
				"\n 5. Listado servicios"
				"\n 6. Listar total de pesos por los servicios prestados"
				"\n 7. Salir"
				"\n Ingresar la operacion que desea ejecutar: ", &opcion);

		switch(opcion)
		{
		case 1:
			altaTrabajo(arrayTrabajo, T, arrayServicios, S, arrayFecha, F);
			break;
		case 2:
			modificarTrabajo(arrayTrabajo, T, arrayServicios, S, arrayFecha, F);
			break;
		case 3:
			borrarTrabajo(arrayTrabajo, T, arrayServicios, S, arrayFecha, F);
			break;
		case 4:
			mostrarTrabajos(arrayTrabajo, T, arrayServicios, S, arrayFecha, F);
			break;
		case 5:
			mostrarServicios(arrayServicios, S);
			break;
		case 6:
			cantidadTotalPesos(arrayTrabajo, T, arrayServicios, S);
			break;
		case 7:
			puts("\n Vuelva pronto.");
			break;
		}

		if(opcion<1 || opcion>7)
		{
			puts("\n Operacion ingresada incorrecta");
		}
		fflush(stdin);
		getchar();
		system("cls");

	}while(opcion !=7);

	//Profesora, le queria avisar que por un error de eclipse, cuando elige la opcion 2, 3 o 4, le aparece opcion incorrecta, cuando deberia aparecerle que no se puede
	//modificar ya que no hay datos cargados, si se fija esta perfectamente programado, pero nose porque motivo la consola muestra un mensaje que deberia aparecer
	//unicamente si ingresa una opcion mayor a 7 o menor a 1.

	return EXIT_SUCCESS;
}
