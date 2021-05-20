/*
 * Bicicleta.h
 *
 *  Created on: 20 may. 2021
 *      Author: Lau
 */

#ifndef BICICLETA_H_
#define BICICLETA_H_
typedef struct
{
	int idBicicleta;
	char marca[25];
	int rodadoBicicleta;
	char color [15];
	int isEmpty;
}eBicicleta;

void hardcodearBicicletas(eBicicleta arrayBicicleta [], int tam);
int buscarBicicletaID(eBicicleta arrayBicicleta[], int tam, int idBicicleta);
void mostrarBicicleta(eBicicleta arrayBicicleta[], int pB);
void mostrarBicicletas(eBicicleta arrayBicicleta[], int tam);
void ordenarPorMarca(eBicicleta arrayBicicleta[], int tam);
#endif /* BICICLETA_H_ */
