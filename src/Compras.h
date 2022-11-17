/*
 * Compras.h
 *
 *  Created on: 14 nov. 2022
 *      Author: EQUIPO
 */

#ifndef COMPRAS_H_
#define COMPRAS_H_

#define LEN 50

typedef struct{
	int codigo;
	char descripcion[LEN];
	int origen;
	float precioUnitario;
	int cantidad;
	float totalCompra;
}eCompras;

/**
 * \fn eCompras compra_new*()
 * \brief Constructor
 *
 * \return Retorna un puntero a estructura con memoria reservada
 */
eCompras * compra_new();

/**
 * \fn eCompras compra_newParametros*(char*, char*, char*, char*, char*, char*)
 * \brief Constructor con parametros seteados
 *
 * \param codigo
 * \param descripcion
 * \param origen
 * \param precioUnitario
 * \param cantidad
 * \param total
 * \return Retorna un puntero a la estructura con sus campos cargados y con memoria reservada
 */
eCompras * compra_newParametros(char* codigo, char* descripcion,char* origen, char* precioUnitario, char* cantidad,char* total);

/**
 * \fn void compra_delete(eCompras*)
 * \brief Destructor, libera memoria
 *
 * \param this Puntero a la estructura que se va a liberar
 */
void compra_delete(eCompras * this);

int compra_setCodigo();

int compra_getCodigo(eCompras* this,int * codigo);

int compra_setDescripcion(eCompras* this,char* descp);

int compra_getDescripcion(eCompras* this,char* descp);

int compra_setOrigen(eCompras* this,int origen);

int compra_getOrigen(eCompras* this,int* origen);

int compra_setPrecio(eCompras* this,float precio);

int compra_getPrecio(eCompras* this,float* precio);

int compra_setCantidad(eCompras* this,int cant);

int compra_getCantidad(eCompras* this,int* cant);

int compra_setTotal(eCompras* this,float total);

int compra_getTotal(eCompras* this,float* total);

/**
 * \fn void compra_calcularTotal*(void*)
 * \brief Calcula el total (precio*cantidad) y lo setea
 *
 * \param element Puntero al elemento
 */
void * compra_calcularTotal (void* element);

/**
 * \fn int compra_filtrarPorAdmin(void*)
 * \brief Filtra el elemento por origen Administracion
 *
 * \param element Puntero al elemento
 * \return Retorna -1(ERROR) , 1(si pasa el filtro) o 0(si no pasa el filtro)
 */
int compra_filtrarPorAdmin(void* element);

/**
 * \fn int compra_filtrarPorTaller(void*)
 * \brief Filtra el elemento por origen Taller
 *
 * \param element Puntero al elemento
 * \return Retorna -1(ERROR) , 1(si pasa el filtro) o 0(si no pasa el filtro)
 */
int compra_filtrarPorTaller(void* element);

/**
 * \fn int compra_filtrarPorVentas(void*)
 * \brief Filtra el elemento por origen Ventas
 *
 * \param element Puntero al elemento
 * \return Retorna -1(ERROR) , 1(si pasa el filtro) o 0(si no pasa el filtro)
 */
int compra_filtrarPorVentas(void* element);

/**
 * \fn int compra_ordenarPorDescripcion(void*, void*)
 * \brief Compara los dos elementos segun el campo descripcion para poder Ordenarlos
 *
 * \param pElementUno Puntero al elementoUno
 * \param pElementDos Puntero al elementoDos
 * \return Retorna el resultado de la comparacion de los dos elementos
 */
int compra_ordenarPorDescripcion(void* pElementUno, void* pElementDos);


#endif /* COMPRAS_H_ */
