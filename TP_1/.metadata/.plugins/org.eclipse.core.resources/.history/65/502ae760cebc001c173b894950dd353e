/*
 ============================================================================
 Name        : trabajopractico1.c
 Author      : NathanSullivan11
 Version     :
 Copyright   :
 Description : Trabajo Práctico Nº1 - Laboratorio I
 ============================================================================
 */

#include <stdio.h>

#include "bibliotecaTP1.h"
#include "ingreso_de_datos.h"
#include "operaciones_aritmeticas.h"

#define DESCUENTO_DEBITO 10
#define AUMENTO_CREDITO 25
#define BTC 4606954.55

int main(void) {
	setbuf(stdout, NULL);

	float kilometros, precioAero, precioLatam;
	// Los inicializo para luego validar si fueron completados o no fueron completados
	kilometros = 0;
	precioAero = 0;
	precioLatam = 0;

	// Variables para guardar el resultado de cada función y luego pasarlos como argumento de la funcion que muestra los resultados
	float precioDebitoY, precioDebitoZ, precioCreditoY, precioCreditoZ, precioUnitarioY, precioUnitarioZ, precioDiferencia;
	double precioBitcoinY, precioBitcoinZ;

	int opcionIngresada;

	do
	{
		opcionIngresada = get_Entero("1.  Ingresar Kilómetros \n2.  Ingresar Precio de Vuelos \n3.  Calcular todos los costos \n4.  Informar Resultados \n5.  Carga forzada de datos \n6.  Salir \nOpcion: ");

		switch (opcionIngresada)
		{
			case 1:
				kilometros = get_FlotantePositivo("Ingrese Kilómetros: ", "----------------------------------------------\nERROR: Ingrese un valor de kilómetros válido (MAYOR A 0): \n-----------------------------------------------\n");
				break;
			case 2:
				if (kilometros != 0)
				{
					precioAero = get_FlotantePositivo("Precio Vuelo Aerolíneas: ", "----------------------------------------------\nERROR: Ingrese un precio válido (MAYOR A 0): \n-----------------------------------------------\n");
					precioLatam = get_FlotantePositivo("Precio Vuelo Latam: ", "----------------------------------------------\nERROR: Ingrese un precio válido (MAYOR A 0): \n-----------------------------------------------\n");
				}
				else
				{
					printf("-----------------------------------------------------------------\nERROR: Primero debe ingresar la cantidad de kilómetros (OPCIÓN 1) \n---------------------------------------------------------------");
				}
				break;
			case 3:
				if (kilometros != 0 && precioAero != 0 && precioLatam != 0)
				{
					// Aerolíneas: a), b), c), d)
					precioDebitoY = aplicarDescuento(precioAero, DESCUENTO_DEBITO);
					precioCreditoY = aplicarAumento(precioAero, AUMENTO_CREDITO);
					precioBitcoinY = dividir(precioAero, BTC);
					precioUnitarioY = dividir(precioAero, kilometros);
					// Latam: a), b), c), d)
					precioDebitoZ = aplicarDescuento(precioLatam, DESCUENTO_DEBITO);
					precioCreditoZ = aplicarAumento(precioLatam, AUMENTO_CREDITO);
					precioBitcoinZ = dividir(precioLatam, BTC);
					precioUnitarioZ = dividir(precioLatam, kilometros);
					// e)
					precioDiferencia = calcularDiferencia(precioAero, precioLatam);
				}
				else
				{
					printf("---------------------------------------------------------------------------------------------\nERROR: Aseguresé que ingreso cantidad de kilómetros (OPCIÓN 1) y precio de vuelos (OPCIÓN 2)\n---------------------------------------------------------------------------------------------");
				}
				break;
			case 4:
				// LLamo la funcion que muestra todo por pantalla
				if (kilometros != 0 && precioAero != 0 && precioLatam != 0)
				{
					mostrarCalculos(kilometros, precioAero ,precioLatam , precioDebitoY, precioDebitoZ, precioCreditoY, precioCreditoZ, precioBitcoinY, precioBitcoinZ, precioUnitarioY, precioUnitarioZ, precioDiferencia);
				}
				else
				{
					printf("------------------------------------------------------------------------------------------------------------------------\nERROR: No hay datos que mostrar. Aseguresé que ingreso cantidad de kilómetros (OPCIÓN 1) y precio de vuelos (OPCIÓN 2)\n------------------------------------------------------------------------------------------------------------------------");
				}
				break;
			case 5:
				kilometros = 7090;
				precioAero = 1335000.66;
				precioLatam = 1350000.75;
				// Aerolíneas: a), b), c), d)
				precioDebitoY = aplicarDescuento(precioAero, DESCUENTO_DEBITO);
				precioCreditoY = aplicarAumento(precioAero, AUMENTO_CREDITO);
				precioBitcoinY = dividir(precioAero, BTC);
				precioUnitarioY = dividir(precioAero, kilometros);
				// Latam: a), b), c), d)
				precioDebitoZ = aplicarDescuento(precioLatam, DESCUENTO_DEBITO);
				precioCreditoZ = aplicarAumento(precioLatam, AUMENTO_CREDITO);
				precioBitcoinZ = dividir(precioLatam, BTC);
				precioUnitarioZ = dividir(precioLatam, kilometros);
				// e)
				precioDiferencia = calcularDiferencia(precioAero, precioLatam);
				mostrarCalculos(kilometros, precioAero ,precioLatam , precioDebitoY, precioDebitoZ, precioCreditoY, precioCreditoZ, precioBitcoinY, precioBitcoinZ, precioUnitarioY, precioUnitarioZ, precioDiferencia);
				kilometros = 0;
				precioAero = 0;
				precioLatam = 0;
				break;
			case 6:
				printf("--------------------\nSaliste exitosamente\n--------------------");
				break;
			default:
				printf("--------------------------------\nERROR: Ingrese una opción válida\n--------------------------------");
				break;
		}
		printf("\n");
	}while(opcionIngresada != 6);

	return 0;
}




