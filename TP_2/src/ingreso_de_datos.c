/*
 * ingreso_de_datos.c
 *
 *  Created on: 4 abr. 2022
 *      Author: DESKTOP
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ingreso_de_datos.h"

void get_String(char * mensaje, char* cadena, int tamanio){

	char auxiliar[1024];
	int cantidadLetras;

	printf(mensaje);
	fflush(stdin);
	scanf("%[^\n]", auxiliar);

	cantidadLetras = strlen(auxiliar);

	while(cantidadLetras > tamanio)
	{
		printf("Se produjo un error. Vuelva a intentarlo\n%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", auxiliar);
		cantidadLetras = strlen(auxiliar);
	}
	strcpy(cadena,auxiliar);
}

void get_AlphabetString(char* mensaje, char* cadena, int tamanio){

	int sonLetras;
	char auxiliar[tamanio];

	get_String(mensaje, auxiliar, tamanio);
	sonLetras = validarCadenaCaracteres(auxiliar);

	while(sonLetras < 1)
	{
		printf("Se produjo un error. Vuelva a intentarlo\n");
		get_String(mensaje, auxiliar, tamanio);
		sonLetras = validarCadenaCaracteres(auxiliar);
	}

	strcpy(cadena,auxiliar);



}

float get_FlotantePositivo(char * mensaje, char * mensajeError)
{
	float flotanteIngresado;
	printf("%s", mensaje);
	scanf("%f", &flotanteIngresado);
	while(flotanteIngresado < 1)
	{
		printf("%s\n", mensajeError);
		printf("%s", mensaje);
		scanf("%f", &flotanteIngresado);
	}

	return flotanteIngresado;
}

int get_Entero(char * mensaje)
{
	int retorno = -1;
	int numeroValidado;
	int esNumero;
	char auxiliar[30];

	get_String(mensaje, auxiliar, 30);

	esNumero = validarNumero(auxiliar);

	while(esNumero < 1 )
	{
		printf("Se produjo un error. Vuelva a intentarlo\n");
		get_String(mensaje, auxiliar, 30);
		esNumero = validarNumero(auxiliar);
	}

	numeroValidado = atoi(auxiliar);
	retorno = numeroValidado;

	return retorno;
}


int get_EnteroPositivo(char * mensaje, char * mensajeError)
{
	int enteroIngresado;

	printf(mensaje);
	fflush(stdin);
	scanf("%d", &enteroIngresado);
	while(enteroIngresado < 1)
	{
		printf("%s\n", mensajeError);
		printf("%s", mensaje);
		scanf("%d", &enteroIngresado);
	}

	return enteroIngresado;
}



char get_Char(char * mensaje){

	char caracter;
	printf(mensaje);
	fflush(stdin);
	scanf("%c", &caracter);
	while(!isalpha(caracter))
	{
		printf("Lo que ingreso no es un caracter: ");
		fflush(stdin);
		scanf("%c", &caracter);
	}
	return caracter;
}

float get_Float(char* mensaje){

	int retorno = -1;
	float numeroValidado;
	int esFlotante;
	char auxiliar[30];

	get_String(mensaje, auxiliar, 30);

	esFlotante = validarFlotante(auxiliar);

	while(esFlotante < 1 )
	{
		printf("Se produjo un error. Vuelva a intentarlo\n");
		get_String(mensaje, auxiliar, 30);
		esFlotante = validarFlotante(auxiliar);
	}

	numeroValidado = atof(auxiliar);
	retorno = numeroValidado;

	return retorno;
}

void validarString(char* mensaje, char* cadena, int tamanio){

	while(strlen(cadena) > tamanio || cadena == NULL || strlen(cadena) < 1)
	{
		printf(mensaje);
		fflush(stdin);
		scanf("%[^\n]", cadena);
	}

}

int validarEnterosMaxMin(char* mensaje, int enteroValidar, int minimo, int maximo){

	while(enteroValidar > maximo || enteroValidar < minimo)
	{
		printf("Se ha producido un error vuelva a intentar.\n%s", mensaje);

		scanf("%d", &enteroValidar);
	}
	return enteroValidar;
}



char validarCharMaxMin(char* mensaje, char caracter, char minimo, char maximo){

	while(!isalpha(caracter)) {
	    printf("Lo que ingreso no es un caracter: ");
	    fflush(stdin);
	    scanf("%c", &caracter);
	}
	caracter = toupper(caracter);

	while(caracter > maximo || caracter < minimo)
	{
		printf("Ingrese una letra (entre %c - %c", minimo, maximo);
		fflush(stdin);
		scanf("%c", &caracter);
	}

	return caracter;
}

char validarCharDosOpciones(char* mensaje, char caracter, char opcion1, char opcion2){


	caracter = toupper(caracter);
	while(caracter != opcion1 && caracter != opcion2)
	{
		printf(mensaje);
		fflush(stdin);
		scanf("%c", &caracter);
		caracter = toupper(caracter);
	}
	return caracter;

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



int validarNumero(char* auxiliar){

	int i;
	int largo;
	int retorno =-1;

	if(auxiliar != NULL)
	{
		retorno = 1;
		largo = strlen(auxiliar);

		for(i = 0; i < largo; i++)
		{
			if(isdigit(auxiliar[i]) == 0)
			{
				retorno = 0;
				break;
			}

		}
	}
	return retorno;
}

int validarFlotante(char* auxiliar){


	int i;
	int largo;
	int punto = 0;
	int retorno =-1;

	if(auxiliar != NULL)
	{
		retorno = 1;
		largo = strlen(auxiliar);

		for(i = 0; i < largo; i++)
		{
			if(isdigit(auxiliar[i]) == 0)
			{
				if(auxiliar[i] == '.')
				{

					if(punto == 1)
					{
						retorno = 0;
						break;
					}
					punto = 1;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
		if(punto == 1 && strlen(auxiliar) == 1)
		{
			retorno = 0;
		}
	}

	return retorno;
}


