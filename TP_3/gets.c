/*
 * gets.c
 *
 *  Created on: 17 may. 2022
 *      Author: DESKTOP
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "gets.h"

int get_String(char * mensaje, char* cadena, int tamanio){

	int retorno = -1;
	char auxiliar[528];
	int cantidadLetras;
	if(cadena != NULL && tamanio > 0)
	{
		retorno = 0;

		printf(mensaje);
		fflush(stdin);
		scanf("%[^\n]", auxiliar);

		cantidadLetras = strlen(auxiliar);

		while(cantidadLetras > tamanio || cantidadLetras < 1)
		{
			printf("Se produjo un error. Vuelva a intentarlo\n%s", mensaje);
			fflush(stdin);
			scanf("%[^\n]", auxiliar);
			cantidadLetras = strlen(auxiliar);
		}
		strcpy(cadena,auxiliar);
	}
	return retorno;
}

int get_Nombre(char * mensaje, char* cadena, int tamanio){

	int retorno = -1;
	char auxiliar[528];
	int respuesta;
	if(cadena != NULL && tamanio > 0)
	{
		retorno = 0;
		do{
			printf(mensaje);
			fflush(stdin);
			scanf("%[^\n]", auxiliar);
			respuesta = esValidoNombre(auxiliar, tamanio);
		}while(respuesta == 0);

		strcpy(cadena,auxiliar);
	}
	return retorno;
}

int get_Entero(char * mensaje, int *numero){
	int retorno = -1;
	int numeroValidado;
	char auxiliar[30];

	if(numero != NULL)
	{
		retorno = 0;
		get_String(mensaje, auxiliar, 30);

		numeroValidado = esNumerica(auxiliar);

		while(numeroValidado < 1 )
		{
			printf("Se produjo un error. Vuelva a intentarlo\n");
			get_String(mensaje, auxiliar, 30);
			numeroValidado = esNumerica(auxiliar);
		}

		*numero = atoi(auxiliar);

	}
	return retorno;
}


int get_Char(char * mensaje, char *caracter){

	int retorno = -1;
	char auxChar;
	if(caracter != NULL)
	{
		retorno = 0;
		printf(mensaje);
		fflush(stdin);
		scanf("%c", &auxChar);
		while(!isalpha(auxChar))
		{
			printf("Lo que ingreso no es una letra: ");
			fflush(stdin);
			scanf("%c", &auxChar);
		}

		*caracter = auxChar;
	}
	return retorno;
}

int get_Float(char* mensaje, float *numero){

	int retorno = -1;
	if(numero != NULL)
	{
		float numeroValidado;
		int flotanteValidado;
		char auxiliar[30];

		get_String(mensaje, auxiliar, 30);

		flotanteValidado = esFlotante(auxiliar);

		while(flotanteValidado < 1)
		{
			printf("Se produjo un error. Vuelva a intentarlo\n");
			get_String(mensaje, auxiliar, 30);
			flotanteValidado = esFlotante(auxiliar);
		}

		numeroValidado = atof(auxiliar);
		*numero = numeroValidado;
	}
	return retorno;
}

void validarEnterosMaxMin(char* mensaje, int *enteroValidar, int minimo, int maximo){

	int aux;
	aux = *enteroValidar;

	while(aux > maximo || aux < minimo)
	{
		printf("%s (%d-%d): ",mensaje, minimo, maximo);
		scanf("%d", &aux);
	}
	*enteroValidar = aux;
}

void validarCharMaxMin(char* mensaje, char *caracter, char minimo, char maximo){

	char aux;
	aux = toupper(*caracter);

	while(aux > maximo || aux < minimo || !isalpha(aux))
	{
		printf("%s (%c-%c): ", mensaje, minimo, maximo);
		fflush(stdin);
		scanf("%c", &aux);
		*caracter = toupper(aux);
	}

}

void validarCharDosOpciones(char* mensaje, char *caracter, char opcion1, char opcion2){

	char aux;
	aux = *caracter;

	aux = toupper(aux);
	while(aux != opcion1 && aux != opcion2)
	{
		printf(mensaje);
		fflush(stdin);
		scanf("%c", &aux);
		*caracter = toupper(*caracter);
	}

	*caracter = aux;

}

int validarCadenaCaracteres(char* auxiliar){

	int i;
	int largo;
	int retorno = -1;

	if(auxiliar != NULL)
	{
		retorno = 1;
		largo = strlen(auxiliar);

		for(i = 0; i < largo; i++)
		{
			if(!(isalpha(auxiliar[i])))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int esNumerica(char* auxiliar){

	int i;
	int retorno =-1;

	if(auxiliar != NULL)
	{
		retorno = 1;
		for(i = 0; auxiliar[i] != '\0'; i++)
		{
			if(i == 0 && (auxiliar[i] == '-' || auxiliar[i] == '+'))
			{
				continue;
			}
			if(isdigit(auxiliar[i]) == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int esFlotante(char* cadena){


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


int esValidoNombre(char* auxiliar, int tamanio){

	int i;
	int largo;
	int retorno = -1;

	if(auxiliar != NULL)
	{
		retorno = 1;
		largo = strlen(auxiliar);
		if(largo > tamanio)
		{
			return 0;
		}

		for(i = 0; i < largo; i++)
		{      //(cadena[i] < 'A' || cadena[i] >'Z') && (cadena[i] < 'a' || cadena[i] >'z')
			if((auxiliar[i] < 'A' || auxiliar[i] > 'Z') && (auxiliar[i] < 'a' || auxiliar[i] > 'z') && (auxiliar[i] < 129 || auxiliar[i] > 235))
			{
				if((auxiliar[i] == ' ') && (((auxiliar[i-1] >= 'A' && auxiliar[i-1] <= 'Z')) || ((auxiliar[i-1] >= 'a' && auxiliar[i-1] <= 'z'))) && (((auxiliar[i+1] >= 'A' && auxiliar[i+1] <= 'Z')) || ((auxiliar[i+1] >= 'a' && auxiliar[i+1] <= 'z'))))
				{
					continue;
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



