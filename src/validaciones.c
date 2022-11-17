/*
 * validaciones.c
 *
 *  Created on: 17 sep. 2022
 *      Author: Romina Calani Cruz
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

int myGets(char *cadena, int longitud){
	int salida=-1;
	fflush(stdin);
	if(cadena!=NULL && longitud>0 && fgets(cadena,longitud, stdin)==cadena){
		if(cadena[strlen(cadena)-1]=='\n'){
			cadena[strlen(cadena)-1]='\0';
		}
		salida=0;
	}
	return salida;
}

int esNumero(char *cadena){
	int salida=1;
	int i=0;
	if(cadena!=NULL && strlen(cadena)>0){
		while(cadena[i]!='\0'){
			if(cadena[i]<'0' || cadena[i]>'9'){
				salida=0;
				break;
			}
			i++;
		}
	}
	return salida;
}

int getInt(int *pResultado){
	int salida=-1;
	char buffer[64];
	if(pResultado!=NULL && myGets(buffer, sizeof(buffer))==0 && esNumero(buffer)){
		*pResultado = atoi(buffer);
		salida=0;
	}
	return salida;
}

int utn_getNumeroEntero(int *pResultado, char *mensaje, char *mensajeError, int min, int max, int reintentos){
	int salida=-1;
	int buffer;
	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && min<=max && reintentos>=0){
		while(reintentos>=0){
			printf("%s",mensaje);
			if(getInt(&buffer)==0 && buffer>=min && buffer<=max){
				*pResultado = buffer;
				salida=0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}
	}
	return salida;
}

int esTexto(char *cadena,int longitud){
	int i=0;
	int retorno = 1;
	if(cadena != NULL && longitud > 0)	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++){
			if(cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' )){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int getTexto(char *pResultado, int longitud){
    int salida=-1;
    char buffer[2022];
    if(pResultado != NULL){
    	if(	myGets(buffer,sizeof(buffer))==0 &&
    		esTexto(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
    		salida = 0;
		}
    }
    return salida;
}

int utn_getNombreArchivo(char *pResultado, int longitud,char *mensaje, char *mensajeError, int reintentos){
	char buffer[2022];
	int salida = -1;
	if(pResultado!=NULL && longitud>0 && mensaje!=NULL && mensajeError!=NULL  && reintentos>=0){
		while(reintentos>=0)
		{
			printf("%s",mensaje);
			if(getTexto(buffer,sizeof(buffer))==0)
			{
				strncpy(pResultado,buffer,longitud);
				salida = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return salida;
}
