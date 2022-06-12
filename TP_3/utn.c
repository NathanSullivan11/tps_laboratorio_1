/*
 * utn.c
 *
 *  Created on: 24 may. 2022
 *      Author: DESKTOP
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

static int getInt(int* pResultado);
static int getFloat(float* pResultado);
static int getNombreCadena(char* pResultado, int longitud);
static int getDescripcionCadena(char* pResultado, int longitud);

int getString(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[4096]; // char* bufferString = malloc(sizeof(char)*longitud); /*** != NULL ***/

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

static int getInt(int* pResultado){

	int retorno = -1;
	char bufferString[50];

	if(pResultado != NULL &&
		!getString(bufferString, sizeof(bufferString)) &&
		esNumero(bufferString) &&
		bufferString[0] != '\0')
	{
		retorno = 0;
		*pResultado = atoi(bufferString);
	}
	return retorno;
}

int esNumero(char* auxiliar){

	int retorno =-1;
	int i;

	if(auxiliar != NULL)
	{
		retorno = 1;
		for(i = 0; auxiliar[i] != '\0'; i++)
		{
			if(i == 0 && (auxiliar[i] == '-' || auxiliar[i] == '+'))
			{
				continue;
			}
			if(auxiliar[i] > '9' || auxiliar[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int getNumeroEntero(char* mensaje, int* pResultado){

	int retorno = -1;
	int respuesta, bufferInt;

	do{
		printf("%s", mensaje);
		respuesta = getInt(&bufferInt);
		if(!respuesta)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		else
		{
			printf("Se ha producido un error. Vuelva a intentarlo\n");
		}
	}while(respuesta != 0);

	return retorno;
}

static int getFloat(float* pResultado){

	int retorno = -1;
	char bufferString[50];

	if(pResultado != NULL &&
		!getString(bufferString, sizeof(bufferString)) &&
		esFloat(bufferString) &&
		bufferString[0] != '\0')
	{
		retorno = 0;
		*pResultado = atof(bufferString);
	}
	return retorno;
}


int getNumeroFlotante(char* mensaje, float* pResultado)
{

	int retorno = -1;
	float bufferFloat;
	int respuesta;
	do{
		printf("%s", mensaje);
		respuesta = getFloat(&bufferFloat);
		if(!respuesta)
		{
			retorno = 0;
			*pResultado = bufferFloat;
			break;
		}
		else
		{
			printf("Se ha producido un error. Vuelva a intentarlo\n");
		}
	}while(respuesta != 0);

	return retorno;
}


int esFloat(char* cadena){

	int i;
	int contadorPuntos = 0;
	int retorno = -1;

	if(cadena != NULL)
	{
		retorno = 1;
		for(i = 0; cadena[i] != '\0'; i++)
		{

			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(isdigit(cadena[i]) == 0)
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}

	}

	return retorno;
}

int getNombre(char* mensaje, char* pResultado, int longitud){

	char bufferString[4096];
	int retorno = -1;

	while(1)
	{
		printf("%s", mensaje);
		if(getNombreCadena(bufferString, sizeof(bufferString)) == 0 &&
			strnlen(bufferString, sizeof(bufferString)) < longitud &&
			bufferString[0] != '\0')
		{
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("Se ha producido un error. Vuelva a intentarlo\n");
	}
	return retorno;
}

static int getNombreCadena(char* pResultado, int longitud){

	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL && longitud > 0)
	{
		if(getString(buffer, sizeof(buffer)) == 0 &&
			esNombre(buffer, sizeof(buffer)) &&
			strnlen(buffer, sizeof(buffer))< longitud)
		{
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}

int esNombre(char* cadena, int longitud){

	int i;
	int retorno = -1;

	if(cadena != NULL && longitud > 0)
	{
		retorno = 1;
		for(i = 0; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] >'Z') && (cadena[i] < 'a' || cadena[i] >'z') && (cadena[i] < 129 || cadena[i] > 235))
			{
				retorno = 0;
				break;
			}

		}

	}

	return retorno;
}

int getDescripcion(char* mensaje, char* pResultado, int longitud){

	char bufferString[4096];
	int retorno = -1;

	while(1)
	{
		printf("%s", mensaje);
		if(getDescripcionCadena(bufferString, sizeof(bufferString)) == 0 &&
			strnlen(bufferString, sizeof(bufferString)) < longitud &&
			bufferString[0] != '\0')
		{
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("Se ha producido un error. Vuelva a intentarlo\n");
	}
	return retorno;
}

static int getDescripcionCadena(char* pResultado, int longitud){

	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL && longitud > 0)
	{
		if(getString(buffer, sizeof(buffer)) == 0 &&
			esDescripcion(buffer, sizeof(buffer)) &&
			strnlen(buffer, sizeof(buffer))< longitud)
		{
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}

int esDescripcion(char* cadena, int longitud){

	int i;
	int retorno = -1;

	if(cadena != NULL && longitud > 0)
	{
		retorno = 1;
		for(i = 0; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && (cadena[i] < 'A' || cadena[i] >'Z') && (cadena[i] < 'a' || cadena[i] >'z') && (cadena[i] < '0' || cadena[i] > '9') )
			{
				retorno = 0;
				break;
			}

		}

	}

	return retorno;
}



