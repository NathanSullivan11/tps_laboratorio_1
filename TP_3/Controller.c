#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "gets.h"
//#include "utn.h"
#include "Parser.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int pasajerosCargados;
	FILE* fpArchivo;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		fpArchivo = fopen(path, "r");
		if(fpArchivo != NULL)
		{
			pasajerosCargados = parser_PassengerFromText(fpArchivo,pArrayListPassenger);
			printf("\nSe cargaron %d pasajeros", pasajerosCargados);
			retorno = 0;
		}
		fclose(fpArchivo);

	}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* fpArchivo;
	int pasajerosCargados;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		fpArchivo = fopen(path, "rb");
		if(fpArchivo != NULL)
		{
			pasajerosCargados = parser_PassengerFromBinary(fpArchivo,pArrayListPassenger);
			printf("Se cargaron %d pasajeros del archivo binario", pasajerosCargados);
		}
		fclose(fpArchivo);
	}
	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayFlyCodes)
{
	int retorno = -1;
	Passenger* auxPasajero = NULL;
	char bufferNombre[128];
	char bufferApellido[128];
	char bufferFlyCode[128];
	int bufferType;
	float bufferPrecio;
	int bufferStatus;
	if(pArrayListPassenger != NULL)
	{
		passenger_promptPassenger(pArrayFlyCodes, bufferNombre, bufferApellido, &bufferPrecio, bufferFlyCode, &bufferType, &bufferStatus);
		auxPasajero = passenger_newParametros(bufferNombre, bufferApellido, bufferPrecio, bufferFlyCode, bufferType, bufferStatus);
		if(auxPasajero != NULL)
		{
			if(!passenger_assignNextId(auxPasajero))
			{
				if(!ll_add(pArrayListPassenger, auxPasajero))
				{
					retorno = 0;
				}
			}
			else
			{
				passenger_delete(auxPasajero);
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayFlyCodes)
{
	int retorno = -1;
	Passenger* pAux;
	int idOpcion, len, idEncontrado, i;
	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		get_Entero("\nIngrese el ID del pasajero a modificar: ", &idOpcion);
		len = ll_len(pArrayListPassenger);
		for(i = 0; i < len;i++)
		{
			pAux = ll_get(pArrayListPassenger, i);
			passenger_getId(pAux, &idEncontrado);
			if(idEncontrado == idOpcion)
			{
				passenger_edit(pArrayListPassenger, pArrayFlyCodes, pAux);
				retorno = 0;
				break;
			}
		}
		if(retorno != 0)
		{
			printf("Pasajero con ID: %d NO ENCONTRADO", idOpcion);
		}
	}
	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pAux;
	int idOpcion, len, idEncontrado, i, confirmacion;
	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		get_Entero("\nIngrese el ID del pasajero a dar de baja: ", &idOpcion);
		len = ll_len(pArrayListPassenger);
		for(i = 0; i < len;i++)
		{
			pAux = ll_get(pArrayListPassenger, i);
			if(!passenger_getId(pAux, &idEncontrado) && idEncontrado == idOpcion)
			{
				printf("+-------+-------------------+----------------------+------------+--------------+-----------------+-----------------+");
				passenger_printOne(pArrayListPassenger, pAux);
				printf("\n+-------+-------------------+----------------------+------------+--------------+-----------------+-----------------+");
				get_Entero("\nPara darlo de baja ingrese 1.\nPara cancelarlo ingrese 0: ", &confirmacion);
				if(confirmacion == 1)
				{
					if(!passenger_removeOne(pArrayListPassenger, i))
					{
						retorno = 0;
						break;
					}
				}
				else
				{
					printf("\nHas cancelado la baja");
					retorno = 1;
				}
			}
		}
		if(retorno < 0)
		{
			printf("Pasajero con ID: %d NO ENCONTRADO", idOpcion);
		}
	}

	return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* p1;
	int len;
	int i;
	if(pArrayListPassenger != NULL)
	{  /* Price        */
		printf("\n+------+-------------------+----------------------+--------------+------------+-----------------+-----------------+\n");
		printf("| Id   | Name              | Last name            | Price        | Fly code   | Type passenger  | Status Flight   |");
		printf("\n+------+-------------------+----------------------+--------------+------------+-----------------+-----------------+");
		len = ll_len(pArrayListPassenger);
		for(i=0;i<len;i++)
		{
			p1 = ll_get(pArrayListPassenger, i);
			if(p1 != NULL)
			{
				passenger_printOne(pArrayListPassenger, p1);
			}
		}
		printf("\n+------+-------------------+----------------------+--------------+------------+-----------------+-----------------+");
		retorno = 0;
	}
	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int confirmacion;

	if(pArrayListPassenger != NULL)
	{
		confirmacion = passenger_sort(pArrayListPassenger);
		printf("\nOrdenando la lista. Aguarde un momento...");
		if(!confirmacion)
		{
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* fpArchivo;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		fpArchivo = fopen(path, "w");
		if(fpArchivo != NULL)
		{
			if(!parser_PassengerToText(fpArchivo, pArrayListPassenger))
			{
				retorno = 0;
			}
		}
		fclose(fpArchivo);
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* fpArchivo;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		fpArchivo = fopen(path, "wb");
		if(fpArchivo != NULL)
		{
			if(!parser_PassengerToBinary(fpArchivo, pArrayListPassenger))
			{
				retorno = 0;
			}
		}
		fclose(fpArchivo);
	}
	return retorno;
}


int controller_initFlyCodes(LinkedList* pArrayFlyCodes){
	int retorno = -1;
	FlyCode* codigoDeVuelos[8];
	char codigos[][10] = {"BA2491A","IB0800A" , "MM0987B", "TU6789B", "GU2345F", "HY4567D", "FR5678G", "BR3456J"};
	int estados[] = {2,2,1,2,4,3,1,3};
	int i;
	if(pArrayFlyCodes != NULL)
	{
		retorno = 0;
		for(i = 0; i < 8; i++)
		{
			codigoDeVuelos[i] = flycode_newFlyCode();
			if(codigoDeVuelos[i] != NULL)
			{
				flycode_setFlyCode(codigoDeVuelos[i], codigos[i]);
				flycode_setStatusFlight(codigoDeVuelos[i], estados[i]);
				ll_add(pArrayFlyCodes, codigoDeVuelos[i]);
			}
		}
	}
	return retorno;
}


