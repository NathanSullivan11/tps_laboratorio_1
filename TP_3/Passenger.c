/*
 * Passenger.c
 *
 *  Created on: 20 may. 2022
 *      Author: DESKTOP
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "gets.h"
//#include "utn.h"


Passenger* passenger_new(void)
{
	return (Passenger*) malloc(sizeof(Passenger));
}

Passenger* passenger_newParametrosTxt(char* id, char* name,char* lastName, char* price, char* flyCode, char* typePassenger,char* statusFlight){

	Passenger* this = NULL;
	this = passenger_new();
	if(this != NULL)
	{
		if(passenger_setName(this, name) != 0 ||
		   passenger_setLastName(this, lastName) != 0 ||
		   passenger_setIdTxt(this,  id) != 0 ||
		   passenger_setPriceTxt(this, price) != 0||
		   passenger_setFlyCode(this, flyCode) != 0||
		   passenger_setTypePassengerTxt(this, typePassenger) != 0 ||
		   passenger_setStatusFlightTxt(this, statusFlight) != 0)
		{
			passenger_delete(this);
			this = NULL;
		}
	}
	return this;

}


Passenger* passenger_newParametros(char* name,char* lastName,  float price, char* flyCode, int typePassenger, int statusFlight){

	Passenger* this = NULL;
	this = passenger_new();
	if(this != NULL)
	{
		if(passenger_setName(this, name) != 0 ||
		   passenger_setLastName(this, lastName) != 0 ||
		   passenger_setPrice(this, price) != 0||
		   passenger_setFlyCode(this, flyCode) != 0||
		   passenger_setTypePassenger(this, typePassenger) != 0 ||
		   passenger_setStatusFlight(this, statusFlight) != 0)
		{
			passenger_delete(this);
			this = NULL;
		}
	}
	return this;
}

int passenger_delete(Passenger* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		free(this);
	}
	return retorno;
}

int passenger_removeOne(LinkedList* pArrayListPassenger, int index){
	int retorno = -1;
	Passenger* pAux;
	if(pArrayListPassenger != NULL && index > 0)
	{
		pAux = (Passenger*) ll_pop(pArrayListPassenger, index);
		if(pAux != NULL)
		{
			passenger_delete(pAux);
			retorno = 0;

		}
	}
	return retorno;
}
int passenger_menuInt(char options[], int min, int max){

	int opcion;
	printf(options);
	get_Entero("Opción: ", &opcion);
	validarEnterosMaxMin("Ingrese una opción válida", &opcion, min, max);
	return opcion;
}

char passenger_menuChar(char options[], char min, char max){

	char opcion;
	printf(options);
	get_Char("\nOpción: ", &opcion);
	opcion = toupper(opcion);
	validarCharMaxMin("Ingrese una opción válida", &opcion, min, max);
	return opcion;
}

int passenger_edit(LinkedList* pArrayListPassenger, LinkedList* pArrayFlyCodes,Passenger* this){
	int retorno = -1;
	char confirmar, opcionModificar;
	char bufferNombre[NAME_LEN];
	char bufferApellido[NAME_LEN];
	char bufferTipopassenger[NAME_LEN];
	char bufferCodigo[FLYCODE_LEN];
	int bufferEstadoVuelo;
	float bufferPrecio;

	if(this != NULL)
	{
		printf("+-------+-------------------+----------------------+------------+--------------+-----------------+-----------------+");
		passenger_printOne(pArrayListPassenger, this);
		printf("\n+-------+-------------------+----------------------+------------+--------------+-----------------+-----------------+");
		do{
			opcionModificar =  passenger_menuChar("Menu modificación\nA. Nombre\nB. Apellido\nC. Precio\nD. Código de vuelo\nE. Tipo de passenger", 'A', 'E');
			switch(opcionModificar)
			{
			case 'A':
				get_Nombre("Nombre: ",bufferNombre, NAME_LEN );
				if(!passenger_setName(this, bufferNombre))
				{
					printf("\nNombre modificado correctamente!");
				}
				else
				{
					printf("\nError: no se pudo modificar");
				}
				break;
			case 'B':
				get_Nombre("Apellido: ", bufferApellido, NAME_LEN);
				if(!passenger_setLastName(this, bufferApellido))
				{
					printf("\nApellido modificado correctamente!");
				}
				else
				{
					printf("\nError: no se pudo modificar");
				}
				break;
			case 'C':
				get_Float("Precio: ", &bufferPrecio);
				if(!passenger_setPrice(this, bufferPrecio))
				{
					printf("\nPrecio modificado correctamente!");
				}
				else
				{
					printf("\nError: no se pudo modificar");
				}
				break;
			case 'D':
				if(!flycode_promptFlyCode(pArrayFlyCodes,bufferCodigo, &bufferEstadoVuelo))
				{
					passenger_setFlyCode(this,bufferCodigo);
					printf("\nCódigo de vuelo modificado correctamente!");
				}
				else
				{
					printf("\nError: no se pudo modificar");
				}
				break;
			case 'E':
				passenger_listTypesPassengers();
				get_String("Tipo de passenger: ", bufferTipopassenger, 20);
				if(!passenger_setTypePassengerTxt(this, bufferTipopassenger))
				{
					printf("\nTipo de passenger modificado correctamente!");
				}
				else
				{
					printf("\nError: no se pudo modificar");
				}
				break;

			}
			printf("\n+-------+-------------------+----------------------+------------+--------------+-----------------+-----------------+");
			passenger_printOne(pArrayListPassenger, this);
			printf("\n+-------+-------------------+----------------------+------------+--------------+-----------------+-----------------+");
			get_Char("\n¿Quiere seguir modifcando [S/N]: ", &confirmar);
			validarCharDosOpciones("Ingrese 'S' si quiere seguir modificando: ", &confirmar, 'S', 'N');
			retorno = 0;
		}while(confirmar == 'S');

	}

	return retorno;
}

int passenger_promptPassenger(LinkedList* pArrayFlyCodes, char* name,char* lastName, float* price, char* flyCode, int* typePassenger,int* statusFlight){

	int retorno = -1;
	char bufferTipo[128];
	char bufferFlyCode[128];
	int bufferEstado;
	int tipo;

	if(name != NULL && lastName != NULL && price != NULL && flyCode != NULL && typePassenger != NULL && statusFlight != NULL)
	{
		get_Nombre("Nombre: ", name, NAME_LEN);
		get_Nombre("Apellido: ", lastName, NAME_LEN);
		get_Float("Precio: ", price);
		if(!flycode_promptFlyCode(pArrayFlyCodes, bufferFlyCode,&bufferEstado))
		{
			strcpy(flyCode, bufferFlyCode);
			*statusFlight = bufferEstado;
			printf("\nCodigo recibido");
		}
		passenger_listTypesPassengers();
		do{
			get_String("Tipo de passenger: ", bufferTipo, 20);
			tipo = passenger_readTypePassengerChar(bufferTipo);
		}while(tipo < 0);
		*typePassenger = tipo;
		retorno = 0;

	}
	return retorno;
}

int passenger_assignNextId(Passenger* this){
	int retorno = -1;
	char charId[10];
	int intId;
	FILE* pIdFile;
	if(this != NULL)
	{
		pIdFile = fopen("idsPassengers.csv", "r");
		if(pIdFile != NULL)
		{
			if(fscanf(pIdFile, "%[^\n]\n", charId) == 1)
			{
				intId = atoi(charId) + 1;
				if(!passenger_setId(this,intId))
				{
					if(!passenger_loadLastId(intId))
					{
						retorno = 0;
					}
				}
			}
			fclose(pIdFile);
		}
	}

	return retorno;
}
int passenger_loadLastId(int lastId){
	int retorno = -1;

	FILE* pIdFile;

	pIdFile = fopen("idsPassengers.csv", "w");
	if(pIdFile != NULL)
	{
		fprintf(pIdFile, "%d", lastId);
		fclose(pIdFile);
		retorno = 0;
	}
	return retorno;
}

void passenger_listTypesPassengers(void)
{
	printf("\n+-----------------+\n");
	printf("| Type passenger  |\n+-----------------+\n|  EconomyClass   |\n| ExecutiveClass  |\n|   FirstClass    |");
	printf("\n+-----------------+\n");

}

void passenger_listStatusFlights(void)
{
	printf("\n+-----------------+\n");
	printf("| Status Flights  |\n+-----------------+\n|   En Horario    |\n|   Aterrizado    |\n|    En Vuelo     |\n|    Demorado     |");
	printf("\n+-----------------+\n");

}


int passenger_printOne(LinkedList* pArrayListPassenger, Passenger* this){

	int retorno = -1;
	float bufferPrecio;
	char bufferNombre[128];
	char bufferApellido[128];
	char bufferFlyCode[128];
	char bufferType[128];
	char bufferStatus[128];
	int bufferId;

	if(this != NULL)
	{
		passenger_getId(this, &bufferId);
		passenger_getName(this, bufferNombre);
		passenger_getLastName(this, bufferApellido);
		passenger_getPrice(this, &bufferPrecio);
		passenger_getFlyCode(this, bufferFlyCode);
		passenger_getTypePassengerTxt(this, bufferType);
		passenger_getStatusFlightTxt(this,bufferStatus);
		//passenger_readStatusFlightInt(intStatus, bufferStatus);
		//passenger_readTypePassengerInt(intType, bufferType);
		printf("\n| %-5d| %-18s| %-21s| $%-12.2f| %-11s| %-16s| %-16s|", bufferId, bufferNombre ,bufferApellido, bufferPrecio, bufferFlyCode,bufferType ,bufferStatus);
	}
	return retorno;
}

int passenger_setId(Passenger* this, int id){

	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int passenger_setIdTxt(Passenger* this, char* id){

	int retorno = -1;

	if(this != NULL && id != NULL && esNumerica(id))
	{
		this->id = atoi(id);
		retorno = 0;
	}
	return retorno;
}

int passenger_getId(Passenger* this, int* id){

	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}
int passenger_getIdTxt(Passenger* this, char* id){

	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		sprintf(id, "%d", this->id);
		retorno = 0;

	}
	return retorno;
}

int passenger_setName(Passenger* this, char* name){

	int retorno = -1;

	if(this != NULL && name != NULL && esValidoNombre(name, NAME_LEN))
	{
		strcpy(this->name, name);
		retorno = 0;
	}
	return retorno;
}
int passenger_setLastName(Passenger* this, char* lastName){
	int retorno = -1;

	if(this != NULL && lastName != NULL && esValidoNombre(lastName, NAME_LEN))
	{
		strcpy(this->lastName, lastName);
		retorno = 0;
	}
	return retorno;
}
int passenger_getName(Passenger* this, char* name){
	int retorno = -1;

	if(this != NULL && name != NULL)
	{
		strcpy(name, this->name);
		retorno = 0;
	}
	return retorno;
}
int passenger_getLastName(Passenger* this, char* lastName){
	int retorno = -1;

	if(this != NULL && lastName != NULL)
	{
		strcpy(lastName, this->lastName);
		retorno = 0;
	}
	return retorno;
}
int passenger_setFlyCode(Passenger* this, char* flyCode){
	int retorno = -1;

	if(this != NULL && flyCode != NULL && flycode_isValidFlyCode(flyCode))
	{
		strcpy(this->flyCode, flyCode);
		retorno = 0;
	}
	return retorno;
}

int passenger_setFlyCodeStruct(Passenger* this, char* flyCode){
	int retorno = -1;

	if(this != NULL && flyCode != NULL && flycode_isValidFlyCode(flyCode))
	{

		strcpy(this->flyCode, flyCode);
		retorno = 0;
	}
	return retorno;
}

int passenger_getFlyCode(Passenger* this, char* flyCode){
	int retorno = -1;

	if(this != NULL && flyCode != NULL)
	{
		strcpy(flyCode, this->flyCode);
		retorno = 0;
	}
	return retorno;
}

int passenger_setPrice(Passenger* this, float price){
	int retorno = -1;

	if(this != NULL && price > 0)
	{
		this->price = price;
		retorno = 0;
	}
	return retorno;
}

int passenger_setPriceTxt(Passenger* this, char* price){
	int retorno = -1;

	if(this != NULL && price != NULL && esFlotante(price))
	{
		this->price = atof(price);
		retorno = 0;
	}
	return retorno;
}

int passenger_getPrice(Passenger* this, float* price){
	int retorno = -1;

	if(this != NULL && price != NULL)
	{
		*price = this->price;
		retorno = 0;
	}
	return retorno;
}

int passenger_setTypePassengerTxt(Passenger* this, char* typePassenger){
	int retorno = -1;
	int auxTipo;

	if(this != NULL && typePassenger != NULL)
	{
		auxTipo = passenger_readTypePassengerChar(typePassenger);
		if(auxTipo != -1)
		{
			this->typePassenger = auxTipo;
			retorno = 0;
		}
	}
	return retorno;
}

int passenger_setTypePassenger(Passenger* this, int typePassenger){
	int retorno = -1;

	if(this != NULL && typePassenger > 0)
	{
		this->typePassenger = typePassenger;
		retorno = 0;
	}
	return retorno;
}

int passenger_getTypePassenger(Passenger* this, int* typePassenger){
	int retorno = -1;

	if(this != NULL && typePassenger != NULL)
	{
		*typePassenger = this->typePassenger;
		retorno = 0;
	}

	return retorno;
}
int passenger_getTypePassengerTxt(Passenger* this, char* typePassenger){
	int retorno = -1;
	char aux[50];
	if(this != NULL && typePassenger != NULL)
	{
		passenger_readTypePassengerInt(this->typePassenger, aux);
		if(aux != NULL)
		{
			strcpy(typePassenger, aux);
			retorno = 0;
		}

	}
	return retorno;
}

int passenger_setStatusFlight(Passenger* this, int statusFlight){
	int retorno = -1;

	if(this != NULL && statusFlight > 0)
	{
		this->statusFlight = statusFlight;
		retorno = 0;
	}
	return retorno;
}

int passenger_setStatusFlightTxt(Passenger* this, char* statusFlight){
	int retorno = -1;
	int auxEstado;

	if(this != NULL && statusFlight != NULL)
	{
		auxEstado = passenger_readStatusFlightChar(statusFlight);
		if(auxEstado != -1)
		{
			this->statusFlight = auxEstado;
			retorno = 0;
		}
	}
	return retorno;
}
int passenger_getStatusFlight(Passenger* this, int* statusFlight){
	int retorno = -1;

	if(this != NULL && statusFlight != NULL)
	{
		*statusFlight = this->statusFlight;
		retorno = 0;
	}
	return retorno;
}

int passenger_getStatusFlightTxt(Passenger* this, char* statusFlight){
	int retorno = -1;
	char aux[50];
	if(this != NULL && statusFlight != NULL)
	{
		passenger_readStatusFlightInt(this->statusFlight, aux);
		if(aux != NULL)
		{
			strcpy(statusFlight, aux);
			retorno = 0;
		}

	}
	return retorno;
}


int passenger_readStatusFlightChar(char* statusFlight){
	int retorno = -1;
	if(statusFlight != NULL)
	{
		if(!strcmp("En Horario", statusFlight)) // En Horario
		{
			retorno = 1;
		}
		else
		{
			if(!strcmp("Aterrizado", statusFlight)) // Aterrizado
			{
				retorno = 2;
			}
			else
			{
				if(!strcmp("Demorado", statusFlight)) // Demorado
				{
					retorno = 3;
				}
				else
				{
					if(!strcmp("En Vuelo", statusFlight)) // En Vuelo
					{
						retorno = 4;
					}
				}
			}
		}
	}
	return retorno;
}

int passenger_readTypePassengerChar(char* typePassenger){
	int retorno = -1;
	if(typePassenger != NULL)
	{
		if(!strcmp("EconomyClass", typePassenger)) // EconomyClass
		{
			retorno = 1;
		}
		else
		{
			if(!strcmp("ExecutiveClass", typePassenger)) // ExecutiveClass
			{
				retorno = 2;
			}
			else
			{
				if(!strcmp("FirstClass", typePassenger)) // FirstClass
				{
					retorno = 3;
				}
			}
		}
	}
	return retorno;
}

int passenger_readStatusFlightInt(int statusFlight, char* charStatusFlight){
	int retorno = -1;
	if(statusFlight > 0 && charStatusFlight != NULL)
	{
		switch(statusFlight)
			{
			case 1:
				strcpy(charStatusFlight, "En Horario");
				retorno = 0;
			break;
			case 2:
				strcpy(charStatusFlight, "Aterrizado");
				retorno = 0;
			break;
			case 3:
				strcpy(charStatusFlight, "Demorado");
				retorno = 0;
			break;
			case 4:
				strcpy(charStatusFlight, "En Vuelo");
				retorno = 0;
			break;
			default:
				charStatusFlight = NULL;
				break;
			}
	}
	return retorno;

}

int passenger_readTypePassengerInt(int typePassenger,char* charTypePassenger){
	int retorno = -1;
	if(typePassenger > 0 && charTypePassenger != NULL)
	{
		switch(typePassenger)
		{
		case 1:
			strcpy(charTypePassenger, "EconomyClass");
			retorno = 0;
		break;
		case 2:
			strcpy(charTypePassenger, "ExecutiveClass");
			retorno = 0;
		break;
		case 3:
			strcpy(charTypePassenger, "FirstClass");
			retorno = 0;
		break;
		default:
			charTypePassenger = NULL;
			break;
		}
	}
	return retorno;
}

int passenger_sort(LinkedList* pArrayListPassenger){
	int retorno = -1;
	char opcionCriterio;
	int opcionOrden;
	if(pArrayListPassenger != NULL)
	{
		opcionCriterio = passenger_menuChar("A. Ordenar por nombre\nB. Ordenar por ID\nC. Ordenar por código de vuelo\n",'A','C');
		switch(opcionCriterio)
		{
		case 'A':
			opcionOrden = passenger_menuInt("0. Descendente\n1. Ascendente\n", 0, 1);
			if(opcionOrden == 1)
			{
				if(!ll_sort(pArrayListPassenger, passenger_compareByName, 1))
				{
					retorno = 0;
				}
			}
			else
			{
				if(!ll_sort(pArrayListPassenger, passenger_compareByName, 0))
				{
					retorno = 0;
				}
			}
			break;
		case 'B':
			opcionOrden = passenger_menuInt("0. Descendente\n1. Ascendente\n", 0, 1);
			if(opcionOrden == 1)
			{
				if(!ll_sort(pArrayListPassenger, passenger_compareById, 1))
				{
					retorno = 0;
				}
			}
			else
			{
				if(!ll_sort(pArrayListPassenger, passenger_compareById, 0))
				{
					retorno = 0;
				}
			}
			break;
		case 'C':
			opcionOrden = passenger_menuInt("0. Descendente\n1. Ascendente\n", 0, 1);
			if(opcionOrden == 1)
			{
				if(!ll_sort(pArrayListPassenger, passenger_compareByFlyCode, 1))
				{
					retorno = 0;
				}
			}
			else
			{
				if(!ll_sort(pArrayListPassenger, passenger_compareByFlyCode, 0))
				{
					retorno = 0;
				}
			}
			break;
		}
	}
	return retorno;
}

int passenger_compareByName(void* p1, void* p2)
{
	Passenger* passenger1;
	Passenger* passenger2;
	char nombre1[NAME_LEN];
	char nombre2[NAME_LEN];
	int retorno = -2;
	int comparacion;

	if(p1 != NULL && p2 != NULL)
	{
		passenger1 = (Passenger*) p1;
		passenger2 = (Passenger*) p2;
		if( !(passenger_getName(passenger1, nombre1)) &&
		!(passenger_getName(passenger2, nombre2)))
		{
			comparacion = strcmp(nombre1, nombre2);
			if(comparacion > 0)
			{
				retorno = 1;
			}
			else
			{
				if(comparacion < 0)
				{
					retorno = -1;
				}
				else
				{
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int passenger_compareByFlyCode(void* p1, void* p2)
{
	Passenger* passenger1;
	Passenger* passenger2;
	char flyCode1[FLYCODE_LEN];
	char flyCode2[FLYCODE_LEN];
	int retorno = -2;
	int comparacion;

	if(p1 != NULL && p2 != NULL)
	{
		passenger1 = (Passenger*) p1;
		passenger2 = (Passenger*) p2;
		if( !(passenger_getFlyCode(passenger1, flyCode1)) &&
		!(passenger_getFlyCode(passenger2, flyCode2)))
		{
			comparacion = strcmp(flyCode1, flyCode2);
			if(comparacion > 0)
			{
				retorno = 1;
			}
			else
			{
				if(comparacion < 0)
				{
					retorno = -1;
				}
				else
				{
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}


int passenger_compareById(void* p1, void* p2)
{
	Passenger* passenger1;
	Passenger* passenger2;
	int comparacion;
	int id1, id2;
	comparacion = -2;
	passenger1 = (Passenger*) p1;
	passenger2 = (Passenger*) p2;
	if( !(passenger_getId(passenger1, &id1)) &&
		!(passenger_getId(passenger2, &id2)))
	{
		if(id1 > id2)
		{
			comparacion = 1;
		}
		else
		{
			if(id1 < id2)
			{
				comparacion = -1;
			}
			else
			{
				comparacion = 0;
			}
		}
	}
	return comparacion;
}


FlyCode* flycode_newFlyCode(void){

	return (FlyCode*) malloc(sizeof(FlyCode)*1);
}

int flycode_setFlyCode(FlyCode* this, char* flyCode){
	int retorno = -1;
	if(this != NULL && flyCode != NULL)
	{
		strcpy(this->flyCode, flyCode);
		retorno = 0;
	}
	return retorno;

}

int flycode_setStatusFlight(FlyCode* this, int statusFlight){
	int retorno = -1;

	if(this != NULL && statusFlight > 0)
	{
		this->statusFlight = statusFlight;
		retorno = 0;
	}
	return retorno;

}

int flycode_promptFlyCode(LinkedList* pArrayFlyCodes, char* flyCode, int* statusFlight){

	int retorno = -1;
	char bufferCodigo[FLYCODE_LEN];
	int bufferEstado;
	int nuevoCodigoVuelo;

	if(pArrayFlyCodes != NULL)
	{
		flycode_listFlyCodes(pArrayFlyCodes);
		get_Entero("\n0. Para elegir un código de vuelo\n1.Para agregar uno nuevo a la lista\nOpción: ", &nuevoCodigoVuelo);
		if(nuevoCodigoVuelo == 1 && !flycode_addNewFlyCode(pArrayFlyCodes))
		{
			flycode_listFlyCodes(pArrayFlyCodes);
			printf("\nSe agregó el código de vuelo");
		}
		if(!flycode_getFlyCode(pArrayFlyCodes, bufferCodigo, &bufferEstado))
		{
			strcpy(flyCode, bufferCodigo);
			*statusFlight = bufferEstado;
			retorno = 0;
		}
	}
	return retorno;
}

int flycode_getFlyCode(LinkedList* pArrayFlyCodes, char* flyCode, int* statusFlight){
	int retorno = -1;
	FlyCode* aux;
	char bufferCodigo[FLYCODE_LEN];
	int i, len;
	if(pArrayFlyCodes != NULL && flyCode != NULL)
	{
		len = ll_len(pArrayFlyCodes);

		while(retorno != 0)
		{
			get_String("\nCódigo de su vuelo: ", bufferCodigo, FLYCODE_LEN);
			strupr(bufferCodigo);
			for(i = 0; i < len; i++)
			{
				aux = (FlyCode*)ll_get(pArrayFlyCodes, i);
				if(aux != NULL)
				{
					if(!strcmp(aux->flyCode,bufferCodigo))
					{
						retorno = 0;
						strcpy(flyCode, aux->flyCode);
						*statusFlight = aux->statusFlight;
						break;
					}
				}
			}
			if(retorno != 0)
			{
				printf("\nCódigo de vuelo INEXISTENTE");
			}
		}
	}
	return retorno;
}

int flycode_addNewFlyCode(LinkedList* pArrayFlyCodes){
	int retorno = -1;
	FlyCode* auxCodigo;
	char bufferCodigo[10];
	char bufferEstado[15];
	int estadoValido = 0;
	char mensaje[40];
	if(pArrayFlyCodes != NULL)
	{
		if(!flycode_getNewFlyCode(pArrayFlyCodes, bufferCodigo))
		{
			passenger_listStatusFlights();
			while(estadoValido < 1)
			{
				sprintf(mensaje, "Estado del vuelo de %s: ", bufferCodigo);
				get_String(mensaje, bufferEstado, 15);
				estadoValido = passenger_readStatusFlightChar(bufferEstado);
				if(estadoValido > 0)
				{
					break;
				}
				printf("===================================\nError estado de vuelo INEXISTENTE\n===================================\n");
			}
			auxCodigo = flycode_newFlyCode();
			if(	auxCodigo != NULL &&
				!flycode_setFlyCode(auxCodigo, bufferCodigo) &&
				!flycode_setStatusFlight(auxCodigo, estadoValido) &&
				!ll_add(pArrayFlyCodes, auxCodigo))
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}
int flycode_listFlyCodes(LinkedList* pArrayFlyCodes){

	int retorno = -1;
	FlyCode* auxCodigo;
	char bufferStatus[14];
	int i, len;
	if(pArrayFlyCodes != NULL)
	{
		len = ll_len(pArrayFlyCodes);
		if(!ll_isEmpty(pArrayFlyCodes))
		{
			retorno = 0;
			printf("/******* CODIGO DE VUELOS *******/");
			printf("\n+--------------+-----------------+\n| Fly code     | Status Flight   |\n+--------------+-----------------+");
			for(i = 0; i < len; i++)
			{
				auxCodigo = ll_get(pArrayFlyCodes, i);
				if(auxCodigo != NULL)
				{
					passenger_readStatusFlightInt(auxCodigo->statusFlight, bufferStatus);
					if(bufferStatus != NULL)
					{
						printf("\n| %-13s| %-16s|", auxCodigo->flyCode,bufferStatus);
					}

				}
			}
			printf("\n+--------------+-----------------+");
		}
	}


	return retorno;
}



int flycode_getNewFlyCode(LinkedList* pArrayFlyCodes, char* string){
	int retorno = -1;
	int esValido = -1;
	if(string != NULL)
	{
		while(esValido < 1)
		{
			get_String("\nCódigo de vuelo a agregar a la lista: ", string, FLYCODE_LEN);
			esValido = flycode_isValidFlyCode(string);
			if(esValido == 1)
			{
				retorno = 0;
				break;
			}
			printf("\nError: Formato de código INVALIDO (Ej: 'AB1234C')");
		}
	}
	return retorno;
}

int flycode_isValidFlyCode(char* string){

	int retorno = -1;
	int largo, i;
	if(string != NULL)
	{
		retorno = 1;
		largo = strlen(string);
		if(largo != 7)
		{
			return 0;
		}
		for(i = 0; i < largo && string[i] != '\0'; i++)
		{
			if(i == 0 || i == 1 || i == 6)
			{
				if(!(isalpha(string[i])))
				{
					retorno = 0;
					break;
				}
				else
				{
					string[i] = toupper(string[i]);
				}
			}
			else
			{
				if(i == 2 || i == 3|| i == 4|| i == 5)
				{
					if(!(isdigit(string[i])))
					{
						retorno = 0;
						break;
					}
				}
			}
		}

	}
	return retorno;
}



