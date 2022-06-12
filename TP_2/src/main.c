/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "ingreso_de_datos.h"

#define CANT_PASAJEROS 2000
#define CANT_CODIGOS_DE_VUELO 6
#define CANT_TIPOS_PASAJEROS 3

int main(void){
	setbuf(stdout, NULL);

	Passenger pasajeros[CANT_PASAJEROS];
	Passenger aux;
	flyCodeStatusFlight vuelosEstados[CANT_CODIGOS_DE_VUELO];
	typePassenger tipoPasajero[CANT_TIPOS_PASAJEROS];

	char opciones[512];
	int opcion, id, espacioVacio;
	int flag = 0;
	id = 1;

	initPassengers(pasajeros, CANT_PASAJEROS);
	initFlyCodes(vuelosEstados, CANT_CODIGOS_DE_VUELO);
	hardcodeFlyCodeStatusFlight(vuelosEstados, CANT_CODIGOS_DE_VUELO);
	hardcodeTypePassenger(tipoPasajero, CANT_TIPOS_PASAJEROS);

	do
	{
		sprintf(opciones, "MENU\n1. Altas\n2. Modificar\n3. Bajas\n4. Informar:\n5. Carga forzada\n6. SALIR\n");
		opcion = menu(opciones);
		flag = findLoadPassengers(pasajeros, CANT_PASAJEROS);
		switch(opcion)
		{
			case 1:   // Alta
				aux = promptPassenger(vuelosEstados, CANT_CODIGOS_DE_VUELO, tipoPasajero, CANT_TIPOS_PASAJEROS);
				espacioVacio = addPassenger(pasajeros, CANT_PASAJEROS, id, aux.name, aux.lastName, aux.price, aux.idTypePassenger, aux.flyCode);
				id++;
				if(espacioVacio == -1)
				{
					printf("\n==================================================\nNo se pudo cargar el pasajero al sistema (LISTA DE PASAJEROS LLENA)\n==================================================\n");
				}

			break;
			case 2:   // Modificar
				if(flag == 1)
				{
					modificar(pasajeros, CANT_PASAJEROS, vuelosEstados, CANT_CODIGOS_DE_VUELO, tipoPasajero, CANT_TIPOS_PASAJEROS);
				}
				else
				{
					printf("\n===========================================\nNo hay pasajeros cargados en el sistema\n===========================================\n");
				}
			break;
			case 3:   // Baja
				if(flag == 1)
				{
					baja(pasajeros, CANT_PASAJEROS, tipoPasajero, CANT_TIPOS_PASAJEROS);
				}
				else
				{
					printf("\n==============================================\nNo hay pasajeros cargados en el sistema\n==============================================\n");
				}
			break;
			case 4:   // Informar
				if(flag == 1)
				{
					informar(pasajeros, CANT_PASAJEROS, vuelosEstados, CANT_CODIGOS_DE_VUELO, tipoPasajero, CANT_TIPOS_PASAJEROS);
				}
				else
				{
					printf("\n==============================================\nNo hay pasajeros cargados en el sistema\n==============================================\n");
				}
			break;
			case 5:
				id = forcedPassengerLoad(pasajeros, CANT_PASAJEROS, id);
				if(id != -1)
				{
					printf("\n=================================================\nSe ha forzado la carga de 5 pasajeros al sistema\n=================================================\n");
				}
			break;
			case 6:   // Salir
				printf("\n====================\nSaliste exitosamente\n====================\n");
			break;
			default:
				printf("\n==============================\nOpci�n ingresada INEXISTENTE\n==============================\n");
			break;
		}
		printf("\n");

	}while(opcion != 6);
	return 0;
}
