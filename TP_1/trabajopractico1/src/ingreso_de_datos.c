/*
 * ingreso_de_datos.c
 *
 *  Created on: 4 abr. 2022
 *      Author: DESKTOP
 */
#include <stdio.h>

float get_FlotantePositivo(char * mensaje, char * mensajeError)
{
	float flotanteIngresado;
	printf("%s", mensaje);
	scanf("%f", &flotanteIngresado);
	while(flotanteIngresado < 1)
	{
		printf("%s", mensajeError);
		printf("%s", mensaje);
		scanf("%f", &flotanteIngresado);
	}

	return flotanteIngresado;
}

int get_Entero(char * mensaje)
{
	int enteroIngresado;

	printf(mensaje);
	scanf("%d", &enteroIngresado);

	return enteroIngresado;
}
