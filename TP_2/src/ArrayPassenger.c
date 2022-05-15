/*
 * ArrayPassenger.c
 *
 *  Created on: 20 abr. 2022
 *      Author: DESKTOP
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ingreso_de_datos.h"
#include "ArrayPassenger.h"

#define TRUE 1
#define FALSE 0
#define DOWN -1
#define ACTIVO 1
#define CANCELADO 0

int initPassengers(Passenger* list, int len){

	int i, retorno;
	retorno = -1;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

int initFlyCodes(flyCodeStatusFlight* list, int len){

	int i, retorno;
	retorno = -1;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

int menu(char opciones[]){

	int opcion;

	printf(opciones);

	opcion = get_Entero("Opción: ");

	return opcion;
}


int findPassengerById(Passenger* list, int len, int id){

	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].id == id && list[i].isEmpty == FALSE)
			{
				retorno = i;
			}
		}
	}

	return retorno;
}

int hardcodeTypePassenger(typePassenger* list, int len){

	int retorno = -1;

	if(list != NULL && len > 0)
	{
		retorno = 0;
		int id[] = {1, 2, 3};
		char descripcion[][16] = {"Primera clase", "Premium", "Ejecutivo"};
		int i;

		for(i = 0; i < len; i++)
		{
			list[i].id = id[i];
			strcpy(list[i].descripcion, descripcion[i]);
		}
	}
	return retorno;
}

int hardcodeFlyCodeStatusFlight(flyCodeStatusFlight* list, int len){

	int retorno = -1;

	if(list != NULL && len > 0)
	{
		retorno = 0;
		char flyCodes[][10] = {"N4XL23", "L3NM52", "B3JF67", "G9OJ83"};
		int statusFlights[] = {ACTIVO, CANCELADO, CANCELADO, ACTIVO};
		int i;

		for(i = 0; i < 4; i++)
		{
			strcpy(list[i].flyCode, flyCodes[i]);
			list[i].statusFlight = statusFlights[i];
			list[i].isEmpty = FALSE;
		}
	}
	return retorno;
}

void listTypePassengers(typePassenger* list, int len){

	int i;

	for(i = 0; i < len; i++)
	{
		if(i == 0)
		{
			printf("\n+----+-----------------+\n");
			printf("| ID | Type Passenger  |");
			printf("\n+----+-----------------+\n");
		}
		printf("| %-3d| %-16s|\n", list[i].id, list[i].descripcion);

	}
	printf("+----+-----------------+\n");
}

void listFlyCodeStatusFlight(flyCodeStatusFlight* list, int len){


		int i;
		char estadoVuelo[10];

		for(i = 0; i < len; i++)
		{
			if(i == 0)
			{
				printf("\n+-----------+----------------+\n");
				printf("|Fly code   | Status flight  |");
				printf("\n+-----------+----------------+\n");
			}
			if(list[i].isEmpty == FALSE)
			{
				if(list[i].statusFlight == 1)
				{
					strcpy(estadoVuelo, "ACTIVO");
				}
				else
				{
					strcpy(estadoVuelo, "CANCELADO");
				}
				printf("| %-10s|  %-14s|\n", list[i].flyCode, estadoVuelo);
			}
		}
		printf("+-----------+----------------+\n");

}

int promptTypePassenger(typePassenger* list, int len){

	int retorno = -1;
	int opcionTipoPasajero;

	if(list != NULL && len > 0)
	{

		listTypePassengers(list, len);
		opcionTipoPasajero = get_Entero("Tipo de pasajero: ");
		validarEnterosMaxMin("Tipo de pasajero: ", opcionTipoPasajero, 1, 3);
		retorno = opcionTipoPasajero;

	}
	return retorno;
}

int promptFlyCodeStatusFlight(flyCodeStatusFlight* list, int len, char* flyCode){

	int retorno = -1;
	char auxFlyCode[10];
	char promptFlyCode[10];
	int contador = 0;
	char confirmacionNuevoCodigo;
	int i;

	if(list != NULL && len > 0)
	{
		retorno = 0;
		listFlyCodeStatusFlight(list, len);
		confirmacionNuevoCodigo = get_Char("¿Desea ingresar un nuevo código de vuelo ACTIVO? [S/N]: ");
		confirmacionNuevoCodigo = validarCharDosOpciones("Se ha producido un error. Vuelva a intentar\n¿Desea ingresar un nuevo código de vuelo ACTIVO? [S/N]: ", confirmacionNuevoCodigo, 'S', 'N');

		if(confirmacionNuevoCodigo == 'S')
		{
			promptNewFlyCode(list, len, promptFlyCode);
			for(i = 0; i < len; i++)
			{
				if(list[i].isEmpty == TRUE)
				{
					strcpy(list[i].flyCode, promptFlyCode);
					list[i].statusFlight = ACTIVO;
					list[i].isEmpty = FALSE;
					break;
				}
			}
			if(i == len-1)
			{
				printf("\n===============================================\nNo se ha podido cargar. Lista de código de vuelos llena\n===============================================\n");
			}

			listFlyCodeStatusFlight(list, len);
		}

		get_String("Ingrese el código de vuelo: ", auxFlyCode, 10);
		strcpy(auxFlyCode, strupr(auxFlyCode));
		contador = 0;
		for(i = 0; i < len; i++)
		{
			if(strcmp(auxFlyCode, list[i].flyCode) != 0 && list[i].isEmpty == FALSE)
			{
				contador++;
			}
			if(contador > len)
			{
				printf("----------------------------\nCódigo de vuelo inexistente\n----------------------------\n");
				get_String("Ingrese el código de vuelo: ", auxFlyCode, 10);
				strcpy(auxFlyCode, strupr(auxFlyCode));
				i = 0;
				contador = 0;
			}
		}

		strcpy(flyCode, auxFlyCode);
	}
	return retorno;
}

void promptNewFlyCode(flyCodeStatusFlight* list, int len, char* auxFlyCode){

	int contadorNumero = 0;
	int contadorLetra = 0;
	int i, flag, largo;

	do
	{
		if(flag == 1)
		{
			contadorNumero = 0;
			contadorLetra = 0;
			printf("Se ha producido un error vuelva a intentarlo\n");
		}
		largo = strlen(auxFlyCode);
		flag = 1;
		get_String("Ingrese el código de su vuelo ACTIVO: ", auxFlyCode, 10);

		for(i = 0; i < 6; i++)
		{
			if(isalpha(auxFlyCode[i]) == 0)
			{
				contadorLetra++;
			}
			else
			{
				if(isdigit(auxFlyCode[i]) != 0)
				{
					contadorNumero++;
				}
			}
		}
	}while(contadorNumero != 3 && contadorLetra != 3 && largo != 6);


}

int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[]){

	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].price = price;
				list[i].idTypePassenger = typePassenger;
				strcpy(list[i].flyCode, flyCode);
				list[i].isEmpty = FALSE;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

Passenger promptPassenger(flyCodeStatusFlight* list, int len, typePassenger* listType, int lenType){

	Passenger aux;

	get_AlphabetString("Nombre del pasajero: ", aux.name, 51);
	get_AlphabetString("Apellido del pasajero: ", aux.lastName, 51);
	promptFlyCodeStatusFlight(list, len, aux.flyCode);
	aux.price = get_Float("Precio: ");
	aux.idTypePassenger = promptTypePassenger(listType, lenType);

	return aux;
}

void baja(Passenger* list, int len, typePassenger* listType, int lenType){

	if(findLoadPassengers(list, len) > 0)
	{
		int idIngresado, index;
		char confirmar;
		printPassengers(list, len,  listType, lenType);
		idIngresado = get_Entero("\nID del pasajero a dar de baja: ");
		index = findPassengerById(list, len, idIngresado);
		if(index != -1)
		{
			confirmar = get_Char("¿Dar de baja? [S/N]: ");
			confirmar = validarCharDosOpciones("Ingrese 'S' = (si) , 'N' = (no): ", confirmar, 'S', 'N');
			if(confirmar == 'S')
			{
				removePassenger(list, len, idIngresado);
				printf("\n-------------------------------\nPasajero con ID %d DADO DE BAJA\n-------------------------------\n", idIngresado);
			}
			else
			{
				printf("\n--------------------\nCancelaste la BAJA\n--------------------\n");
			}
		}
		else
		{
			printf("\n-------------------------------\nPasajero con ID %d NO ENCONTRADO\n-------------------------------\n", idIngresado);
		}
	}
	else
	{
		printf("\n==============================================\nNo hay pasajeros cargados en el sistema\n==============================================\n");
	}
}

int removePassenger(Passenger* list, int len, int id){

	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].id == id && list[i].isEmpty == FALSE)
			{
				list[i].isEmpty = DOWN;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

void modificar(Passenger* listPassenger, int lenPassenger, flyCodeStatusFlight* listFlyCode, int lenFlyCode, typePassenger* listType, int lenType){

	if(findLoadPassengers(listPassenger, lenPassenger) > 0)
	{
		int idIngresado, index, opcionModificar;
		printPassengers(listPassenger, lenPassenger, listType, lenType);
		idIngresado = get_Entero("\nId del pasajero a modificar: ");
		index = findPassengerById(listPassenger, lenPassenger, idIngresado);
		if(index != -1)
		{
			opcionModificar = menu("\n¿Que atributo desea modificar? \n1. Nombre\n2. Apellido\n3. Precio\n4. Tipo de pasajero\n5. Código de vuelo\n");
			modifyPassenger(listPassenger, lenPassenger, index, opcionModificar, listFlyCode, lenFlyCode, listType, lenType);
		}
		else
		{
			printf("\n------------------------------\nPasajero con ID %d NO ENCONTRADO\n------------------------------\n", idIngresado);
		}
	}
	else
	{
		printf("\n==============================================\nNo hay pasajeros cargados en el sistema\n==============================================\n");
	}
}

int modifyPassenger(Passenger* listPassenger, int lenPassenger, int index, int attribute, flyCodeStatusFlight* listFlyCode, int lenFlyCode, typePassenger* listType, int lenType){

	int retorno = -1;
	int flag = 0;

		switch(attribute)
		{
			case 1:   // Nombre
				get_AlphabetString("Nombre: ", listPassenger[index].name, 51);
				flag = 1;
				break;
			case 2:   // Apellido
				get_AlphabetString("Apellido: ", listPassenger[index].lastName, 51);
				flag = 1;
				break;
			case 3:   // Precio
				listPassenger[index].price = get_Float("Precio: ");
				flag = 1;
				break;
			case 4:   // Tipo
				listPassenger[index].idTypePassenger = promptTypePassenger(listType, lenType);
				flag = 1;
				break;
			case 5:   // Codigo
				promptFlyCodeStatusFlight(listFlyCode, lenFlyCode, listPassenger[index].flyCode);
				flag = 1;
				break;
		}
		if(flag == 1)
		{
			retorno = 0;
			printf("--------------------------------\nPasajero modificado exitosamente\n--------------------------------");
		}

	return retorno;
}

void informar(Passenger* listPassenger, int lenPassenger, flyCodeStatusFlight* listFlyCode, int lenFlyCode, typePassenger* listType, int lenType){

		int opcionInformar, orden;

		if(findLoadPassengers(listPassenger, lenPassenger) > 0)
		{
			opcionInformar = menu("   SUBMENU - Informar\n      1. Listar alfabeticamente por APELLIDO y por TIPO.\n      2. PROMEDIO y TOTAL de los pasajes, y cantidad de pasajeros que superan el precio promedio.\n      3. Listar pasajeros por Código de vuelo y por estado de vuelo ACTIVO\n");
			switch(opcionInformar)
			{
				case 1:   // Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
					orden = get_Entero("Ingrese (según orden) '1' = Ascendente, '0' = Descendente : ");
					sortPassengers(listPassenger, lenPassenger, orden, listType, lenType);
				break;
				case 2:	  // Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio
					calculateTotalAverage(listPassenger, lenPassenger);
				break;
				case 3:   //Listado de los pasajeros por Código de vuelo
					orden = get_Entero("Ingrese (según orden) '1' = Ascendente, '0' = Descendente : ");
					sortPassengersByCode(listPassenger, lenPassenger, orden, listFlyCode, lenFlyCode, listType, lenType);
				break;
			}
		}
		else
		{
			printf("\n==============================================\nNo hay pasajeros cargados en el sistema\n==============================================\n");
		}
}

int sortPassengers(Passenger* list, int len, int order, typePassenger* listType, int lenType){

	int retorno = -1;
	int i,j;
	Passenger aux;

	if(list != NULL && len > 0)
	{
		retorno = 0;
		switch(order)
			{
			case 1:
				for(i = 0; i < len - 1; i++)
				{
					for(j = i + 1; j < len; j++)
					{
						if(list[i].isEmpty == FALSE)
						{
							if(list[j].isEmpty == FALSE)
							{
								if(strcmp(list[i].lastName, list[j].lastName) > 0)
								{
									aux = list[i];
									list[i] = list[j];
									list[j] = aux;
								}
								else
								{
									if(strcmp(list[i].lastName, list[j].lastName) == 0)
									{
										if(list[i].idTypePassenger > list[j].idTypePassenger)
										{
											aux = list[i];
											list[i] = list[j];
											list[j] = aux;
										}
									}
								}
							}
						}
					}
				}
			break;
			case 0:
				for(i = 0; i < len - 1; i++)
				{
					for(j = i + 1; j < len; j++)
					{
						if(list[i].isEmpty == FALSE)
						{
							if(list[j].isEmpty == FALSE)
							{
								if(strcmp(list[i].lastName, list[j].lastName) < 0)
								{
									aux = list[i];
									list[i] = list[j];
									list[j] = aux;
								}
								else
								{
									if(strcmp(list[i].lastName, list[j].lastName) == 0)
									{
										if(list[i].idTypePassenger < list[j].idTypePassenger)
										{
											aux = list[i];
											list[i] = list[j];
											list[j] = aux;
										}
									}
								}
							}
						}
					}
				}
				break;
			}
		printPassengers(list, len, listType, lenType);

	}

	return retorno;
}



int sortPassengersByCode(Passenger* listPassenger, int lenPassenger, int order, flyCodeStatusFlight* listFlyCode, int lenFlyCode, typePassenger* listType, int lenType){

	int retorno = -1;
	int i,j;
	Passenger aux;

	if(listPassenger != NULL && lenPassenger > 0)
	{
		retorno = 0;
		switch(order)
		{
			case 1:
				for(i = 0; i < lenPassenger - 1; i++)
				{
					for(j = i + 1; j < lenPassenger; j++)
					{
						if(listPassenger[i].isEmpty == FALSE)
						{
							if(listPassenger[j].isEmpty == FALSE)
							{
								if(strcmp(listPassenger[i].flyCode, listPassenger[j].flyCode) > 0)
								{
									aux = listPassenger[i];
									listPassenger[i] = listPassenger[j];
									listPassenger[j] = aux;
								}
							}
						}
					}
				}
			break;
			case 0:
				for(i = 0; i < lenPassenger - 1; i++)
				{
					for(j = i + 1; j < lenPassenger; j++)
					{
						if(listPassenger[i].isEmpty == FALSE)
						{
							if(listPassenger[j].isEmpty == FALSE)
							{
								if(strcmp(listPassenger[i].flyCode, listPassenger[j].flyCode) < 0)
								{
									aux = listPassenger[i];
									listPassenger[i] = listPassenger[j];
									listPassenger[j] = aux;
								}
							}
						}
					}
				}
			break;
		}

		printActivePassengers(listPassenger,lenPassenger, listFlyCode, lenFlyCode, listType, lenType);

	}
	return retorno;
}

void printActivePassengers(Passenger* listPassenger, int lenPassenger, flyCodeStatusFlight* listFlyCode, int lenFlyCode, typePassenger* listType, int lenType){

	int flag = 0;
	int i, j;

	for(j = 0; j < 6; j++)
	{
		if(listFlyCode[j].isEmpty == FALSE)
		{
			for(i = 0; i < lenPassenger; i++)
				{
					if(listPassenger[i].isEmpty == FALSE)
					{
						if(strcmp(listFlyCode[j].flyCode, listPassenger[i].flyCode) == 0)
						{
							if(listFlyCode[j].statusFlight == ACTIVO)
							{
								if(flag == 0)
								{
									printf("\n+-----+-------------------+----------------------+-----------+---------------+-----------------+\n");
									printf("|  Id | Name              | Last name            | Fly code  | Price         | Type passenger  |");
									printf("\n+-----+-------------------+----------------------+-----------+---------------+-----------------+");
								}
								flag = 1;
								printOnePassenger(listPassenger[i], listType, lenType);
							}
						}
					}
				}
		}
	}
	if(flag == 1)
	{
		printf("\n+-----+-------------------+----------------------+-----------+---------------+-----------------+");
	}
	else
	{
		printf("\n===================================\nNo hay pasajeros con vuelos ACTIVOS\n===================================\n");
	}

}

void printOnePassenger(Passenger pasajero, typePassenger* listType, int lenType){

	int i;
	for(i = 0; i < lenType; i++)
	{
		if(pasajero.idTypePassenger == listType[i].id)
		{
			printf("\n|  %-3d| %-18s| %-21s| %-10s| $%-13.2f| %-16s|", pasajero.id, pasajero.name, pasajero.lastName, pasajero.flyCode, pasajero.price, listType[i].descripcion);
		}
	}

}

int printPassengers(Passenger* listPassenger, int lenPassenger, typePassenger* listType, int lenType){

	int i, j;
	int retorno = -1;
	if(listPassenger != NULL && lenPassenger > 0)
	{
		retorno = 0;
		printf("+-----+-------------------+----------------------+-----------+---------------+-----------------+\n");
		printf("|  Id | Name              | Last name            | Fly code  | Price         | Type passenger  |");
		printf("\n+-----+-------------------+----------------------+-----------+---------------+-----------------+");
		for(i = 0; i < lenType; i++)
		{
			for(j = 0; j < lenPassenger; j++)
			{
				if((listType[i].id == listPassenger[j].idTypePassenger) && listPassenger[j].isEmpty == FALSE)
				{
					printOnePassenger(listPassenger[j], listType, lenType);
				}
			}
		}
		printf("\n+-----+-------------------+----------------------+-----------+---------------+-----------------+");
	}
	return retorno;
}

int calculateTotalAverage(Passenger* list, int len){

	int retorno = -1;
	int i, acumuladorPrecio, contadorTotalPasajeros, contadorPasajerosPromedio;
	float promedio;
	acumuladorPrecio = 0;
	contadorTotalPasajeros = 0;
	contadorPasajerosPromedio = 0;

	if(list != NULL && len > 0)
	{

		retorno = 0;
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				acumuladorPrecio += list[i].price;
				contadorTotalPasajeros++;
			}
		}

		promedio = (float)acumuladorPrecio / contadorTotalPasajeros;

		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].price > promedio)
			{
				contadorPasajerosPromedio++;
			}
		}
		printf("\n==============================================\n");
		printf("Total de precios: $%d \nPromedio por pasajero: $%.2f \nCantidad pasajero que superaron el promedio: %d", acumuladorPrecio, promedio, contadorPasajerosPromedio);
		printf("\n==============================================\n");
	}
	return retorno;
}

int forcedPassengerLoad(Passenger* list, int len, int id){

	int retorno, i;
	int contador = 0;
	retorno = -1;

	if(list != NULL && len > 0)
	{
		char nombre[][51] = {"Pedro", "Charly" ,"Gustavo", "José", "Santiago"};
		char apellido[][51] = {"Páez", "Gómez" ,"Hernandéz", "Ríos", "Lopéz"};
		float precio[] = {799.99, 200, 450, 399.99, 725};
		char codigoDeVuelo[][10] = {"N4XL23", "L3NM52", "B3JF67", "L3NM52", "N4XL23"};
		int tipoPasajero[] = {2, 1, 3, 3, 2};

		for(i = 0; i < len; i++)
		{
			if(contador == 5)
			{
				break;
			}
			if(list[i].isEmpty == TRUE)
			{
				list[i].id = id;
				strcpy(list[i].name, nombre[contador]);
				strcpy(list[i].lastName, apellido[contador]);
				list[i].price = precio[contador];
				strcpy(list[i].flyCode, codigoDeVuelo[contador]);
				list[i].idTypePassenger = tipoPasajero[contador];
				list[i].isEmpty = FALSE;
				id++;
				contador++;
			}
		}
		retorno = id;
	}

	return retorno;

}

int findLoadPassengers(Passenger* list, int len){

	 int retorno = -1;
	 int i;

	 if(list != NULL && len > 0)
	 {
		 retorno = 0;
		 for(i = 0; i < len; i++)
		 {
		 	if(list[i].isEmpty == FALSE)
		 	{
		 		retorno = 1;
		 	}
		 }

	 }

	 return retorno;

}


