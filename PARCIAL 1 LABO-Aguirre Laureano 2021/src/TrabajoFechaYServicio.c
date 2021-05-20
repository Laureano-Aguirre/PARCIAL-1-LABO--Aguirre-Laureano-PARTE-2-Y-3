/*
 * TrabajoFechaYServicio.c
 *
 *  Created on: 19 may. 2021
 *      Author: Lau
 */

#include "TrabajoFechaYServicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Aguirre.h"
#define VACIO 1
#define OCUPADO 0

int buscarServicioTrabajo(eTrabajo arrayTrabajo[], int pT, eServicios arrayServicios [], int tam)
{
	int i;
	int pS;

	pS=-1;

	for(i=0;i<tam;i++)
	{
		if(arrayServicios[i].isEmpty==OCUPADO)
		{
			if(arrayServicios[i].id==arrayTrabajo[pT].idServicio)
			{
				pS=i;
				break;
			}
		}
	}
	return pS;
}

int buscarFechaTrabajo(eTrabajo arrayTrabajo[], int pT, eFecha arrayFecha[], int tam)
{
	int i;
	int pF;

	pF=-1;

	for(i=0;i<tam;i++)
	{
		if(arrayFecha[i].isEmpty==OCUPADO)
		{
			if(arrayFecha[i].idFecha==arrayTrabajo[pT].idFecha)
			{
				pF=i;
				break;
			}
		}
	}
	return pF;
}

int buscarBicicletaTrabajo(eTrabajo arrayTrabajo[], int pT, eBicicleta arrayBicicleta[],int tam)
{
	int i;
	int pB;

	pB=-1;

	for(i=0;i<tam;i++)
	{
		if(arrayBicicleta[i].isEmpty==OCUPADO)
		{
			if(arrayBicicleta[i].idBicicleta==arrayTrabajo[pT].idBicicleta)
			{
				pB=i;
				break;
			}
		}
	}
	return pB;
}

void altaTrabajo(eTrabajo arrayTrabajo[], int tamT, eServicios arrayServicios[], int tamS, eFecha arrayFecha[], int tamF, eBicicleta arrayBicicleta[], int tamB)
{

	int libreT;
	int libreF;
	char marcaBicicleta[25];
	int rodadoBicicleta;
	int idServicio;
	int idFecha;
	int id;
	int dia;
	int mes;
	int anio;
	int pS;
	int validacionD;
	int validacionM;
	int validacionA;


	libreT=buscarLibreTrabajo(arrayTrabajo, tamT);
	libreF=buscarLibreFecha(arrayFecha, tamF);

	if(libreT!=-1 && libreF!=-1)
	{
		id=asignarTrabajoID(arrayTrabajo, tamT);
		/*getString("\n Ingresar la marca de la bicicleta: ", marcaBicicleta);
		getInt("\n Ingresar el rodado de la bicicleta: ", &rodadoBicicleta);*/
		mostrarServicios(arrayServicios, tamS);
		getInt("\n Ingresar el servicio que desea: ", &idServicio);
		pS=buscarServiciosID(arrayServicios, tamS, idServicio);
		while(pS==-1)
		{
			getInt("\n Error, id incorrecto, elija el servicio nuevamente: ", &idServicio);
			pS=buscarServiciosID(arrayServicios, tamS, idServicio);
		}
		getInt("\n Ingresar el dia: ", &dia);
		validacionD=validarDia(dia);
		while(validacionD!=1)
		{
			getInt("\n Error, re ingrese el dia: ", &dia);
			validacionD=validarDia(dia);
		}
		getInt("\n Ingresar el mes: ", &mes);
		validacionM=validarMes(mes);
		while(validacionM!=1)
		{
			getInt("\n Error, re ingrese el mes: ", &mes);
			validacionM=validarMes(mes);
		}
		getInt("\n Ingresar el anio: ", &anio);
		validacionA=validarAnio(anio);
		while(validacionA!=1)
		{
			getInt("\n Error, re ingrese el anio: ", &anio);
			validacionA=validarAnio(anio);
		}


		/*strcpy(arrayTrabajo[libreT].marcaBicicleta, marcaBicicleta);
		arrayTrabajo[libreT].rodadoBicicleta=rodadoBicicleta;*/
		arrayTrabajo[libreT].idServicio=idServicio;
		arrayTrabajo[libreT].idFecha=arrayFecha[libreF].idFecha;
		arrayTrabajo[libreT].isEmpty=OCUPADO;
		arrayFecha[libreF].dia=dia;
		arrayFecha[libreF].mes=mes;
		arrayFecha[libreF].anio=anio;
		arrayFecha[libreF].isEmpty=OCUPADO;
		puts("\n Trabajo cargado exitosamente");
	}
	else
	{
		puts("\n No se encontro un espacio libre para ingresar");
	}

}

void modificarTrabajo(eTrabajo arrayTrabajo[], int tamT, eServicios arrayServicios[], int tamS, eFecha arrayFecha[], int tamF, eBicicleta arrayBicicleta[], int tamB)
{

	int len;
	int idT;
	int pT;
	int pS;
	int pF;
	int pB;
	char marcaBicicleta [25];
	int idServicio;
	int libreT;

	len=trabajo_len(arrayTrabajo, tamT);

	if(len>0)
	{
		getInt("\n Ingresar ID del trabajo a modificar: ", &idT);
		pT=buscarTrabajoID(arrayTrabajo, tamT, idT);

		if(pT!=-1)
		{
			puts("\n Trabajo encontrado");
			pS=buscarServicioTrabajo(arrayTrabajo, pT, arrayServicios, tamS);
			pF=buscarFechaTrabajo(arrayTrabajo,pT, arrayFecha, tamF);
			pB=buscarBicicletaTrabajo(arrayTrabajo, pT, arrayBicicleta, tamB);
			mostrarTrabajo(arrayTrabajo, pT, arrayServicios, pS, arrayFecha, pF, arrayBicicleta, pB);
			idT=asignarTrabajoID(arrayTrabajo, tamT);
			//getString("\n Re ingrese la marca de la bicicleta: ", marcaBicicleta);
			mostrarServicios(arrayServicios, tamS);
			getInt("\n Ingrese el servicio que desea: ", &idServicio);
			pS=buscarServiciosID(arrayServicios, tamS, idServicio);
			while(pS==-1)
			{
				getInt("\n Error, id incorrecto, elija el servicio nuevamente: ", &idServicio);
				pS=buscarServiciosID(arrayServicios, tamS, idServicio);
			}
			//strcpy(arrayTrabajo[libreT].marcaBicicleta, marcaBicicleta);
			arrayTrabajo[libreT].idServicio=idServicio;
			puts("\n El trabajo ha sido modificado exitosamente");
		}
	}
	else
	{
		puts("\n No hay trabajos para modificar");
	}

}

void mostrarTrabajos(eTrabajo arrayTrabajo[], int tamT, eServicios arrayServicios[], int tamS, eFecha arrayFecha[], int tamF, eBicicleta arrayBicicleta[], int tamB)
{
    int i;
    int len;
    int pS;
    int pF;
    int pB;

    len=trabajo_len(arrayTrabajo, tamT);

    if(len>0)
    {
        puts("\n    ID          marca          rodado          servicio          precio          fecha");

        for(i=0;i<tamT;i++)
        {
            if(arrayTrabajo[i].isEmpty==OCUPADO)
            {
                pS=buscarServicioTrabajo(arrayTrabajo, i, arrayServicios, tamS);
                if(pS!=-1)
                {
                    pF=buscarFechaTrabajo(arrayTrabajo, i, arrayFecha, tamF);
                    if(pF!=-1)
                    {
                        pB=buscarBicicletaTrabajo(arrayTrabajo, i, arrayBicicleta, tamB);
                        if(pB!=-1)
                        {
                        	mostrarTrabajo(arrayTrabajo, i, arrayServicios, pS, arrayFecha, pF, arrayBicicleta, pB);
                        }
                    }
                }
            }
        }
    }
    else
    {
    	puts("\n No hay trabajos ingresados");
    }
}

void mostrarTrabajo(eTrabajo arrayTrabajo[], int pT, eServicios arrayServicios[], int pS, eFecha arrayFecha[], int pF, eBicicleta arrayBicicleta[], pB)
{
    printf("\n%6d %14s %15d %17s %15.2f %7d-%d-%d", arrayTrabajo[pT].id,
                                                  arrayBicicleta[pB].marca,
                                                  arrayBicicleta[pB].rodadoBicicleta,
                                                  arrayServicios[pS].descripcion,
                                                  arrayServicios[pS].precio,
                                                  arrayFecha[pF].dia,
                                                  arrayFecha[pF].mes,
                                                  arrayFecha[pF].anio);
}
void borrarTrabajo(eTrabajo arrayTrabajo[], int tamT, eServicios arrayServicios[], int tamS, eFecha arrayFecha[], int tamF, eBicicleta arrayBicicleta[], int tamB)
{
	int len;
	int pT;
	int pS;
	int pF;
	int pB;
	int idT;
	int respuesta;


	len=trabajo_len(arrayTrabajo, tamT);

	if(len>0)
	{
		getInt("\n Ingresar id del trabajo a borrar: ", &idT);
		pT=buscarTrabajoID(arrayTrabajo, tamT, idT);

		if(pT!=-1)
		{
			pS=buscarServicioTrabajo(arrayTrabajo, pT, arrayServicios, tamS);
			pF=buscarFechaTrabajo(arrayTrabajo, pT, arrayFecha, tamF);
			pB=buscarBicicletaTrabajo(arrayTrabajo, pT, arrayBicicleta, tamB);
			puts("\n    ID          marca          rodado          servicio          precio          fecha");
			mostrarTrabajo(arrayTrabajo, pT, arrayServicios, pS, arrayFecha, pF, arrayBicicleta, pB);

			getInt("\n Desea eliminar este trabajo?"
					"\n Ingrese 1 para si o 2 no: ", &respuesta);
			while(respuesta!=1 && respuesta!=2)
			{
				getInt("\n Error, desea eliminar este trabajo?"
						"\n Ingrese 1 para si o 2 no: ", &respuesta);
			}
			if(respuesta==1)
			{
				arrayTrabajo[pT].isEmpty=VACIO;

				puts("\n Trabajo borrado");
			}
			else
			{
				puts("\n Cancelando...");
			}
		}
		else
		{
			puts("\n No se encontro ningun trabajo");
		}

	}
	else
	{
		puts("\n No hay trabajos para borrar.");
	}
}

void cantidadTotalPesos(eTrabajo arrayTrabajo[], int tamT, eServicios arrayServicios[], int tamS)
{
	int i;
	int pS;
	float sumaPrecios;
	int len;

	len=trabajo_len(arrayTrabajo, tamT);

	sumaPrecios=0;

	if(len>0)
	{
		for(i=0;i<tamT;i++)
		{
			if(arrayTrabajo[i].isEmpty==OCUPADO)
			{
				pS=buscarServicioTrabajo(arrayTrabajo, i, arrayServicios, tamS);

				if(pS!=-1)
				{
					sumaPrecios=sumaPrecios+arrayServicios[pS].precio;
				}
			}
		}

		printf("\n La suma de precios es: %.2f", sumaPrecios);

	}
	else
	{
		puts("\n No hay trabajos ingresados");
	}
}

void MostrarOrdenPorMarca(eBicicleta arrayBicicleta[], int tamB, eTrabajo arrayTrabajo[], int tamT, eServicios arrayServicios[], int tamS, eFecha arrayFecha[], int tamF)
{
	int i;
	int j;
	int aux;
	int retorno;

	for(i=0;i<tamB-1;i++)
	{
		for(j=i+1;j<tamB;j++)
		{
			retorno=strcmp(arrayBicicleta[i].marca, arrayBicicleta[j].marca);
			if(retorno==1)
			{
				aux=arrayTrabajo[i];
				arrayTrabajo[i]=arrayTrabajo[j];
				arrayTrabajo[j]=aux;
			}
		}
	}
	mostrarTrabajos(arrayTrabajo, tamT, arrayServicios, tamS, arrayFecha, tamF, arrayBicicleta, tamB);
}

void mostrarServicioBicicleta(eServicios arrayServicios, int pS, eBicicleta arrayBicicleta[], int pB)
{

	 printf("\n%d %14s %15.2f %11d %14s %15d %14s", arrayServicios[pS].id,
	                               	   	   	arrayServicios[pS].descripcion,
											arrayServicios[pS].precio,
											arrayBicicleta[pB].idBicicleta,
											arrayBicicleta[pB].marca,
											arrayBicicleta[pB].rodadoBicicleta,
											arrayBicicleta[pB].color);
}

void mostrarServiciosBicicleta(eServicios arrayServicios, int pS, eBicicleta arrayBicicleta[], int pB)
{
	puts("ID           servicio          precio          IDBicicleta          marca          rodado          color");
	mostrarServicioBicicleta(arrayServicios, pS, arrayBicicleta, pB);
}
