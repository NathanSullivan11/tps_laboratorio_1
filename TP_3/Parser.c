#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "gets.h"
#include "Parser.h"


int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger){
	int retorno = -1;
	char bufferNombre[128];
	char bufferApellido[128];
	char bufferFlyCode[128];
	char bufferType[128];
	char bufferPrecio[128];
	char bufferId[128];
	char bufferStatus[128];
	char buffer[128];
	int contador = 0;
	Passenger* auxPasajero;
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile, "%[^\n]\n", buffer);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferApellido, bufferPrecio, bufferFlyCode, bufferType, bufferStatus) == 7)
			{
				auxPasajero = passenger_newParametrosTxt(bufferId, bufferNombre, bufferApellido, bufferPrecio, bufferFlyCode, bufferType, bufferStatus);
				if(auxPasajero != NULL)
				{
					if(!ll_add(pArrayListPassenger, auxPasajero))
					{
						contador++;
					}
				}
			}

		}while(!feof(pFile));
	}
	retorno = contador;
	return retorno;
}

int parser_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger){

	int retorno = -1;
	int contador = 0;
	Passenger* auxPasajero;
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			auxPasajero = passenger_new();
			if(auxPasajero != NULL)
			{
				if(fread(auxPasajero, sizeof(Passenger), 1, pFile) == 1)
				{
					if(!ll_add(pArrayListPassenger, auxPasajero))
					{
						contador++;
					}
				}
			}

		}while(!feof(pFile));
		retorno = contador;
	}
	return retorno;
}


int parser_PassengerToText(FILE* pFile, LinkedList* pArrayListPassenger){

	int retorno = -1;
	char bufferNombre[128];
	char bufferApellido[128];
	char bufferFlyCode[128];
	char bufferType[128];
	float bufferPrecio;
	int bufferId;
	char bufferStatus[128];
	int intType;
	int intStatus;
	int len, i;
	Passenger* auxPasajero;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);
		fprintf(pFile, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");
		for(i = 0; i < len; i++)
		{
			auxPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			if(auxPasajero != NULL)
			{
				if(!passenger_getId(auxPasajero, &bufferId) &&
					!passenger_getName(auxPasajero, bufferNombre) &&
					!passenger_getLastName(auxPasajero, bufferApellido) &&
					!passenger_getPrice(auxPasajero, &bufferPrecio) &&
					!passenger_getFlyCode(auxPasajero, bufferFlyCode) &&
					!passenger_getTypePassenger(auxPasajero, &intType) &&
					!passenger_getStatusFlight(auxPasajero, &intStatus))
				{

					passenger_readStatusFlightInt(intStatus, bufferStatus);
					passenger_readTypePassengerInt(intType, bufferType);
					retorno = 0;
					fprintf(pFile, "%d,%s,%s,%.2f,%s,%s,%s\n", bufferId, bufferNombre, bufferApellido, bufferPrecio, bufferFlyCode, bufferType, bufferStatus);
				}
			}
		}
	}

	return retorno;
}
int parser_PassengerToBinary(FILE* pFile, LinkedList* pArrayListPassenger){

	int retorno = -1;
	int len,i;
	Passenger* auxPasajero;
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		retorno = 0;
		len = ll_len(pArrayListPassenger);
		for(i = 0; i < len; i++)
		{
			auxPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			fwrite(auxPasajero, sizeof(Passenger), 1, pFile);
		}
	}
	return retorno;
}



