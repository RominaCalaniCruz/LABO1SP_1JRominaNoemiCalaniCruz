/*
 * Controller.h
 *
 *  Created on: 15 nov. 2022
 *      Author: EQUIPO
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/**
 * \fn int controller_menuPrincipal()
 * \brief Imprime el menu principal
 *
 * \return Retorna la opcion elegida
 */
int controller_menuPrincipal();

/**
 * \fn int controller_cargarComprasDesdeTexto(char*, LinkedList*)
 * \brief Carga en la lista los datos del archivo leido
 *
 * \param path Ruta de acceso al archivo
 * \param pArrayListCompras Puntero a la lista
 * \return Retorna 0(ERROR) o 1(EXITO)
 */
int controller_cargarComprasDesdeTexto(char* path , LinkedList* pArrayListCompras);

/**
 * \fn int controller_listarCompras(LinkedList*)
 * \brief Imprime la lista de compras
 *
 * \param pArrayListCompras
 * \return Retorna 0(ERROR) o 1(EXITO)
 */
int controller_listarCompras(LinkedList* pArrayListCompras);

/**
 * \fn int controller_asignarTotales(LinkedList*)
 * \brief Asigna los totales al campo correspondiente dentro de la lista
 *
 * \param pArrayListCompras
 * \return Retorna 0(ERROR) o 1(EXITO)
 */
int controller_asignarTotales(LinkedList* pArrayListCompras);

/**
 * \fn int controller_guardarComprasModoTexto(char*, LinkedList*)
 * \brief  Guarda la lista en modo texto
 *
 * \param path Ruta de acceso al archivo
 * \param pArrayListCompras
 * \return Retorna 0(ERROR) o 1(EXITO)
 */
int controller_guardarComprasModoTexto(char* path,LinkedList* pArrayListCompras);

/**
 * \fn int controller_filtrarPorOrigen(LinkedList*)
 * \brief Filtra , imprime y guarda la lista segun el Origen elegido
 *
 * \param pArrayListCompras
 * \return Retorna 0(ERROR) o 1(EXITO)
 */
int controller_filtrarPorOrigen(LinkedList* pArrayListCompras);

/**
 * \fn int controller_ordenarPorDescripcion(LinkedList*)
 * \brief Ordena la lista segun el campo Descripcion
 *
 * \param pArrayListCompras
 * \return Retorna 0(ERROR) o 1(EXITO)
 */
int controller_ordenarPorDescripcion(LinkedList* pArrayListCompras);


#endif /* CONTROLLER_H_ */
