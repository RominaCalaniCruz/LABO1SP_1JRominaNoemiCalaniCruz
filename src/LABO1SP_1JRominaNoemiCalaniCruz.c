/*
 ============================================================================
 Name        : LABO1SP_1JRominaNoemiCalaniCruz.c
 Author      : Romina Noemi Calani Cruz
 Course      : 1° J
 Copyright   : 2022
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "validaciones.h"

int main(void) {
	setbuf(stdout, NULL);
	LinkedList* listaCompras = ll_newLinkedList();
	int salir=0,flagCarga=0;
	char rutaArchivo[50],rutaGuardar[50];
	do{
		switch(controller_menuPrincipal())
		{
			case 1:
				if(flagCarga==0 && utn_getNombreArchivo(rutaArchivo, 50, "Ingrese el nombre del archivo(solo letras): \n", "Error. Ingrese solo letras\n", 3)==0){
					strcat(rutaArchivo,".csv");
					if(controller_cargarComprasDesdeTexto(rutaArchivo, listaCompras)){
						flagCarga=1;
					}
				}
				break;
			case 2:
				if(ll_isEmpty(listaCompras)==0){
					controller_listarCompras(listaCompras);
				}
				else{
					printf("Primero debe pasar por la opcion 1. \n(No hay datos para mostrar)\n");
				}
				break;
			case 3:
				if(ll_isEmpty(listaCompras)==0 && controller_asignarTotales(listaCompras)){
					printf("Se calcularon y asignaron los totales correctamente.\n");
				}
				else{
					printf("Primero debe pasar por la opcion 1. \n(No hay datos cargados para calcular)\n");
				}
				break;
			case 4:
				if(ll_isEmpty(listaCompras)==0){
					controller_filtrarPorOrigen(listaCompras);
				}
				else{
					printf("Primero debe pasar por la opcion 1. \n(No hay datos para filtrar)\n");
				}
				break;
			case 5:
				if(ll_isEmpty(listaCompras)==0){
					controller_ordenarPorDescripcion(listaCompras);
					controller_listarCompras(listaCompras);
				}
				else{
					printf("Primero debe pasar por la opcion 1. \n(No hay datos para mostrar)\n");
				}
				break;
			case 6:
				if(ll_isEmpty(listaCompras)==0 && utn_getNombreArchivo(rutaGuardar, 50, "Ingrese el nombre del archivo (solo letras)\n", "Error.\n", 3)==0){
					strcat(rutaGuardar,".csv");
					if(controller_guardarComprasModoTexto(rutaGuardar, listaCompras)){
						printf("Se guardo con exito.\nSu archivo se llama: %s\n", rutaGuardar);
					}
				}
				else{
					printf("Primero debe pasar por la opcion 1. \n(No hay datos que se puedan guardar)\n");
				}
				break;
			case 7:
				printf("Fin del programa.\n");
				salir=1;
				break;
			default:
				printf("Esa opcion no existe.\n");

		}
	}while(!salir);
	ll_deleteLinkedList(listaCompras);
	return EXIT_SUCCESS;
}
