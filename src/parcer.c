/*
 * parcer.c
 *
 *  Created on: 15 nov. 2022
 *      Author: EQUIPO
 */
#include <stdio.h>
#include "Compras.h"
#include "LinkedList.h"

int parser_ComprasFromText(FILE* pFile , LinkedList* pArrayListCompras)
{
	int salida=0;
	eCompras * pCompra=NULL;
	char buffer[6][50];
	int cant=0;
	if(pFile!=NULL && pArrayListCompras!=NULL){
		cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
		while(!feof(pFile)){
			cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
			if(cant==6){
				pCompra=compra_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
				if(pCompra!=NULL){
					ll_add(pArrayListCompras, pCompra);
					salida=1;
				}
			}
		}
	}
    return salida;
}
