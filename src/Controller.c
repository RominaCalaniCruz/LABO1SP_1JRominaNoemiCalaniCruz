/*
 * Controller.c
 *
 *  Created on: 15 nov. 2022
 *      Author: EQUIPO
 */
#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Compras.h"
#include "validaciones.h"

int controller_menuPrincipal(){
	int opcion;
	printf("\t••Menu Principal••\n");
	printf("1 - Cargar archivo (.csv)\n");
	printf("2 - Imprimir lista.\n");
	printf("3 - Asignar totales.\n");
	printf("4 - Filtrar por tipo y guardar archivo.\n");
	printf("5 - Mostrar compras ordenadas por descripcion.\n");
	printf("6 - Guardar compras.\n");
	printf("7 - Salir del programa.\n");
	utn_getNumeroEntero(&opcion, "Elija una opcion: ", "Error, debe ingresar un numero valido.\n", 0, 100, 0);
	return opcion;
}

int controller_cargarComprasDesdeTexto(char* path , LinkedList* pArrayListCompras)
{
	int salida=0;
	FILE * archivo = fopen(path,"r");
	if(archivo!=NULL && pArrayListCompras!=NULL){
		if(parser_ComprasFromText(archivo, pArrayListCompras)){
			printf("Archivo cargado correctamente.\n");
			salida=1;
		}
	}
	else{
		printf("No se pudo abrir.\n");
	}
	fclose(archivo);
    return salida;
}

/**
 * \fn void obtenerTipoOrigen(int, char*)
 * \brief Obtiene la cadena de caracteres segun un numero entero
 *
 * \param origen Tipo de origen 1 2 o 3
 * \param tipoOrigen Cadena de caracteres donde se guarda el dato segun el origen
 */
static void obtenerTipoOrigen(int origen,char *tipoOrigen){
	char tipos[][50] = {{"Administracion"},{"Taller"},{"Ventas"}};
	for(int i=0;i<3;i++){
		if((origen-1)==i){
			strcpy(tipoOrigen,tipos[i]);
		}
	}
}

int controller_listarCompras(LinkedList* pArrayListCompras){
	int salida=0;
	eCompras * this;
	int codigo, origen, cantProd;
	char descripcion[50],tipoOrigen[50];
	float precio,total;
	if(pArrayListCompras!=NULL){
		printf("══════════════════════════════════════════════════════════════════════════════════════════════════════\n");
		printf("║ Código ║    Descripción            ║   Origen       ║ Precio Unitario ║ Cantidad ║  Precio Total   ║\n");
		printf("══════════════════════════════════════════════════════════════════════════════════════════════════════\n");
		for(int i=0;i<ll_len(pArrayListCompras);i++){
			this = ll_get(pArrayListCompras, i);
			if(this!=NULL){
				compra_getCodigo(this, &codigo);
				compra_getDescripcion(this, descripcion);
				compra_getOrigen(this, &origen);
				obtenerTipoOrigen(origen, tipoOrigen);
				compra_getPrecio(this, &precio);
				compra_getCantidad(this, &cantProd);
				compra_getTotal(this, &total);
				printf("║  %-3d   ║ %-25s ║ %-14s ║ %15.2f ║ %8d ║ %15.2f ║\n",codigo,descripcion,tipoOrigen,precio,cantProd,total);
				salida=1;
			}
		}
		printf("══════════════════════════════════════════════════════════════════════════════════════════════════════\n");
	}
    return salida;
}

int controller_asignarTotales(LinkedList* pArrayListCompras){
	int salida=0;
	if(pArrayListCompras!=NULL){
		ll_map(pArrayListCompras, compra_calcularTotal);
		salida=1;
	}
	return salida;
}

int controller_guardarComprasModoTexto(char* path,LinkedList* pArrayListCompras){
	int salida=0;
	int codigo,origen,cantidad;
	char descripcion[LEN];
	float precio,total;
	eCompras * this;
	FILE * archivo = fopen(path,"w");
	if(pArrayListCompras!=NULL && archivo!=NULL){
		fprintf(archivo,"codigoCompra,descripcion,origen,precioUnitario,cantidad,totalCompra\n");
		for(int i=0;i<ll_len(pArrayListCompras);i++){
			this = ll_get(pArrayListCompras, i);
			if(this!=NULL){
				compra_getCodigo(this, &codigo);
				compra_getDescripcion(this, descripcion);
				compra_getOrigen(this, &origen);
				compra_getPrecio(this, &precio);
				compra_getCantidad(this, &cantidad);
				compra_getTotal(this, &total);
				fprintf(archivo,"%d,%s,%d,%f,%d,%f\n",codigo,descripcion,origen,precio,cantidad,total);
			}
		}
		salida=1;
		fclose(archivo);
	}
	return salida;
}

int controller_filtrarPorOrigen(LinkedList* pArrayListCompras){
	int salida=0;
	LinkedList* listaFiltro=NULL;
	int opcion;
	char path[50];
	if(pArrayListCompras!=NULL){
		do{
			utn_getNumeroEntero(&opcion, "Por cual tipo de origen desea filtrar?\n1 - Administracion\n2 - Taller\n3 - Ventas\n4 - Volver al menu principal.\n", "Error\n", 1, 4, 3);
			switch(opcion){
				case 1:
					listaFiltro = ll_filter(pArrayListCompras, compra_filtrarPorAdmin);
					strncpy(path,"comprasTipoAdministracion.csv",50);
					break;
				case 2:
					listaFiltro = ll_filter(pArrayListCompras, compra_filtrarPorTaller);
					strncpy(path,"comprasTipoTaller.csv",50);
					break;
				case 3:
					listaFiltro = ll_filter(pArrayListCompras, compra_filtrarPorVentas);
					strncpy(path,"comprasTipoVentas.csv",50);
					break;
				case 4:
					printf("Volviendo al menu...\n");
					break;
				default:
					printf("Esa opcion no existe\n");
			}
			if(listaFiltro!=NULL && path!=NULL && opcion!=4){
				printf("Filtrando por tipo: %s\n",path);
				controller_listarCompras(listaFiltro);
				if(controller_guardarComprasModoTexto(path, listaFiltro)){
					printf("Se guardo con exito el archivo con nombre: %s\n",path);
					salida=1;
				}
			}
		}while(opcion!=4);
		ll_deleteLinkedList(listaFiltro);
	}
	return salida;
}

int controller_ordenarPorDescripcion(LinkedList* pArrayListCompras){
	int salida=0;
	if(pArrayListCompras!=NULL){
		ll_sort(pArrayListCompras, compra_ordenarPorDescripcion, 1);
		salida=1;
	}
	return salida;
}


