/*
 * parser.h
 *
 *  Created on: 15 nov. 2022
 *      Author: EQUIPO
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"

/**
 * \fn int parser_ComprasFromText(FILE*, LinkedList*)
 * \brief Parsea los datos desde el archivo leido y los guarda en la lista
 *
 * \param pFile Puntero al archivo
 * \param pArrayListCompras
 * \return Retorna 0(ERROR) o 1(EXITO)
 */
int parser_ComprasFromText(FILE* pFile , LinkedList* pArrayListCompras);

#endif /* PARSER_H_ */
