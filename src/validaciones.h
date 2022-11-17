/*
 * validaciones.h
 *
 *  Created on: 17 sep. 2022
 *      Author: EQUIPO
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/**
 * \fn int myGets(char*, int)
 * \brief Verifica que la cadena no se pase del tamaño que le corresponde como cadena de caracteres, en caso de que este dentro del rango
 * 			cambia el Enter \n por \0 para marcar el fin de la cadena
 *
 * \param cadena Puntero donde comienza la cadena de caracteres ingresada
 * \param longitud	tamaño maximo de la cadena que tiene permitida ocupar en la memoria
 * \return	Retorna -1 si paso el limite, o 0 si el dato se guardo
 */
int myGets(char *cadena, int longitud);

/**
 * \fn int esNumero(char*)
 * \brief Verifica que la cadena pasada por parametro contenga solo numeros
 *
 * \param cadena	Cadena es un puntero al espacio de memoria donde se encuentra el dato a validar
 * \return Retorna 0 si NO es numero o 1 SI es un numero valido
 */
int esNumero(char *cadena);

/**
 * \fn int getInt(int*)
 * \brief Obtiene y asigna a pResultado un numero entero
 *
 * \param pResultado	Es un puntero al espacio de memoria donde se guardara el dato convertido a un numero Entero
 * \return	Retorna -1 si hubo un error, o 0 si todo salio bien
 */
int getInt(int *pResultado);

/**
 * \fn int utn_getNumeroEntero(int*, char*, char*, int, int, int)
 * \brief obtiene un numero entero utilizando sus respectivas validaciones y lo asigna a pResultado
 *
 * \param pResultado es un puntero al espacio de memoria donde guardara el numero que obtendremos
 * \param mensaje es un puntero al espacio de memoria donde podremos imprimir un mensaje para el usuario
 * 			antes del ingreso de un dato
 * \param mensajeError Lo que mostrara al usuario por consola en caso de equivocarse en el ingreso del dato
 * \param min Numero entero desde donde comenzara el rango para aceptar datos
 * \param max Numero entero hasta donde llega el rango para aceptar el dato
 * \param reintentos Cantidad de veces que tiene el usuario para re-ingresar el dato en caso de equivocarse
 * \return Retornara 0 si pudo obtener dicho dato, en caso de que se haya producido algun error retornara -1
 */
int utn_getNumeroEntero(int *pResultado, char *mensaje, char *mensajeError, int min, int max, int reintentos);

/**
 * \fn int esTexto(char*, int)
 * \brief Valida que la cadena de caracteres recibida por parametro sea un texto normal (letras minusculas y mayusculas)
 *
 * \param cadena Puntero al espacio de memoria donde inicia la cadena de caracteres
 * \param longitud maxima de la cadena
 * \return Retorna 0(ERROR) o 1(EXITO
 */
int esTexto(char *cadena,int longitud);

/**
 * \fn int getTexto(char*, int)
 * \brief Obtiene y guarda en pResultado una cadena de caracteres que ya ha sido verificada como texto
 *
 * \param pResultado Puntero al espacio de memoria donde se guarda el texto
 * \param longitud maxima de la cadena
 * \return Retorna -1(ERROR) o 0(EXITO)
 */
int getTexto(char *pResultado, int longitud);

/**
 * \fn int utn_getNombreCompleto(char*, int, char*, char*, int)
 * \brief Obtiene y guarda en pResultado una cadena de caracteres que ya ha sido verificada como Nombre
 *
 * \param pResultado Puntero al espacio de memoria donde se guardara el nombre
 * \param longitud maxima de la cadena
 * \param mensaje Mensaje que se le mostrara al usuario para el ingreso del nombre
 * \param mensajeError Mensaje de error en caso de que ingrese un nombre invalido
 * \param reintentos Cantidad de  reintentos maxima para el ingreso de datos
 * \return Retorna -1(ERROR) o 0(EXITO)
 */
int utn_getNombreArchivo(char *pResultado, int longitud,char *mensaje, char *mensajeError, int reintentos);


#endif /* VALIDACIONES_H_ */
