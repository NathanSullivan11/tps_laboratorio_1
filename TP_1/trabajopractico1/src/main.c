/*
 ============================================================================
 Name        : trabajopractico1.c
 Author      : NathanSullivan11
 Version     :
 Copyright   :
 Description : Trabajo Pr�ctico N�1 - Laboratorio I
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

	// Variables para guardar el resultado de cada funci�n y luego pasarlos como argumento de la funcion que muestra los resultados
	float precioDebitoY, precioDebitoZ, precioCreditoY, precioCreditoZ, precioUnitarioY, precioUnitarioZ, precioDiferencia;
	double precioBitcoinY, precioBitcoinZ;

	int opcionIngresada;

	do
	{
		opcionIngresada = get_Entero("1.  Ingresar Kil�metros \n2.  Ingresar Precio de Vuelos \n3.  Calcular todos los costos \n4.  Informar Resultados \n5.  Carga forzada de datos \n6.  Salir \nOpcion: ");

		switch (opcionIngresada)
		{
			case 1:
				kilometros = get_FlotantePositivo("Ingrese Kil�metros: ", "----------------------------------------------\nERROR: Ingrese un valor de kil�metros v�lido (MAYOR A 0): \n-----------------------------------------------\n");
				break;
			case 2:
				if (kilometros != 0)
				{
					precioAero = get_FlotantePositivo("Precio Vuelo Aerol�neas: ", "----------------------------------------------\nERROR: Ingrese un precio v�lido (MAYOR A 0): \n-----------------------------------------------\n");
					precioLatam = get_FlotantePositivo("Precio Vuelo Latam: ", "----------------------------------------------\nERROR: Ingrese un precio v�lido (MAYOR A 0): \n-----------------------------------------------\n");
				}
				else
				{
					printf("-----------------------------------------------------------------\nERROR: Primero debe ingresar la cantidad de kil�metros (OPCI�N 1) \n---------------------------------------------------------------");
				}
				break;
			case 3:
				if (kilometros != 0 && precioAero != 0 && precioLatam != 0)
				{
					// Aerol�neas: a), b), c), d)
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
					printf("---------------------------------------------------------------------------------------------\nERROR: Asegures� que ingreso cantidad de kil�metros (OPCI�N 1) y precio de vuelos (OPCI�N 2)\n---------------------------------------------------------------------------------------------");
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
					printf("------------------------------------------------------------------------------------------------------------------------\nERROR: No hay datos que mostrar. Asegures� que ingreso cantidad de kil�metros (OPCI�N 1) y precio de vuelos (OPCI�N 2)\n------------------------------------------------------------------------------------------------------------------------");
				}
				break;
			case 5:
				kilometros = 7090;
				precioAero = 1335000.66;
				precioLatam = 1350000.75;
				// Aerol�neas: a), b), c), d)
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
				printf("--------------------------------\nERROR: Ingrese una opci�n v�lida\n--------------------------------");
				break;
		}
		printf("\n");
	}while(opcionIngresada != 6);

	return 0;
}




