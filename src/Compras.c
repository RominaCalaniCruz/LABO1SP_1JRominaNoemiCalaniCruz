/*
 * Compras.c
 *
 *  Created on: 14 nov. 2022
 *      Author: EQUIPO
 */
#include "Compras.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eCompras * compra_new(){
	return (eCompras*)calloc(1,sizeof(eCompras));
}

eCompras * compra_newParametros(char* codigo, char * descripcion,char* origen, char* precioUnitario, char* cantidad,char* total){
	eCompras * this;
	this = compra_new();
	if(this != NULL){
		if(!compra_setCodigo(this,atoi(codigo)) ||
			!compra_setDescripcion(this, descripcion) ||
			!compra_setOrigen(this, atoi(origen)) ||
			!compra_setPrecio(this, atof(precioUnitario)) ||
			!compra_setCantidad(this, atoi(cantidad)) ||
			!compra_setTotal(this, atof(total)))
		{
			compra_delete(this);
		}
	}
	return this;
}

void compra_delete(eCompras * this){
	free(this);
}

int compra_setCodigo(eCompras* this,int codigo){
	int salida=0;
	if(this!=NULL){
		this->codigo=codigo;
		salida=1;
	}
	return salida;
}

int compra_getCodigo(eCompras* this,int * codigo){
	int salida=0;
	if(this!=NULL){
		*codigo = this->codigo;
		salida=1;
	}
	return salida;
}

int compra_setDescripcion(eCompras* this,char* descp){
	int salida=0;
	if(this!=NULL ){
		strcpy(this->descripcion,descp);
		salida=1;
	}
	return salida;
}

int compra_getDescripcion(eCompras* this,char* descp){
	int salida=0;
	if(this!=NULL ){
		strcpy(descp,this->descripcion);
		salida=1;
	}
	return salida;
}

int compra_setOrigen(eCompras* this,int origen){
	int salida=0;
	if(this!=NULL){
		this->origen=origen;
		salida=1;
	}
	return salida;
}

int compra_getOrigen(eCompras* this,int* origen){
	int salida=0;
	if(this!=NULL){
		*origen = this->origen;
		salida=1;
	}
	return salida;
}

int compra_setPrecio(eCompras* this,float precio){
	int salida=0;
	if(this!=NULL){
		this->precioUnitario=precio;
		salida=1;
	}
	return salida;
}

int compra_getPrecio(eCompras* this,float* precio){
	int salida=0;
	if(this!=NULL){
		*precio = this->precioUnitario;
		salida=1;
	}
	return salida;
}

int compra_setCantidad(eCompras* this,int cant){
	int salida=0;
	if(this!=NULL){
		this->cantidad=cant;
		salida=1;
	}
	return salida;
}

int compra_getCantidad(eCompras* this,int* cant){
	int salida=0;
	if(this!=NULL){
		*cant = this->cantidad;
		salida=1;
	}
	return salida;
}

int compra_setTotal(eCompras* this,float total){
	int salida=0;
	if(this!=NULL){
		this->totalCompra=total;
		salida=1;
	}
	return salida;
}

int compra_getTotal(eCompras* this,float* total){
	int salida=0;
	if(this!=NULL){
		*total = this->totalCompra;
		salida=1;
	}
	return salida;
}

void * compra_calcularTotal (void* element){
	int cantidad;
	float precio,total;
	eCompras * pResultado;
	pResultado = (eCompras*)element;
	compra_getCantidad(pResultado, &cantidad);
	compra_getPrecio(pResultado, &precio);
	total = precio * (float)cantidad;
	compra_setTotal(pResultado, total);
	return pResultado;
}

int compra_filtrarPorAdmin(void* element){
	int salida=-1;
	int origen;
	if(element!=NULL){
		compra_getOrigen((eCompras*)element, &origen);
		if(origen == 1){
			salida=1;
		}
		else{
			salida=0;
		}
	}
	return salida;
}

int compra_filtrarPorTaller(void* element){
	int salida=-1;
	int origen;
	if(element!=NULL){
		compra_getOrigen((eCompras*)element, &origen);
		if(origen == 2){
			salida=1;
		}
		else{
			salida=0;
		}
	}
	return salida;
}

int compra_filtrarPorVentas(void* element){
	int salida=-1;
	int origen;
	if(element!=NULL){
		compra_getOrigen((eCompras*)element, &origen);
		if(origen == 3){
			salida=1;
		}
		else{
			salida=0;
		}
	}
	return salida;
}

int compra_ordenarPorDescripcion(void* pElementUno, void* pElementDos){
	int salida=0;
	char descUno[50],descDos[50];
	if(pElementUno!=NULL && pElementDos!=NULL){
		compra_getDescripcion((eCompras*)pElementUno, descUno);
		compra_getDescripcion((eCompras*)pElementDos, descDos);
		salida = strnicmp(descUno,descDos,50);
	}
	return salida;
}
