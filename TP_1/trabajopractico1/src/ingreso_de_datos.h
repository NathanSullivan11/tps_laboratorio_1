/*
 * ingreso_de_datos.h
 *
 *  Created on: 4 abr. 2022
 *      Author: DESKTOP
 */

#ifndef INGRESO_DE_DATOS_H_
#define INGRESO_DE_DATOS_H_

float get_FlotantePositivo(char * mensaje, char * mensajeError);
/// @brief Pide un numero flotante positivos
/// @param mensaje = recibe como parametro una cadena para mostrar al momento de pedir el numero
/// @param mensajeError = en caso de que no sea positivo, muestro por pantalla este mensaje
/// @return float = deuvelve lo que la funcion pide

int get_Entero(char * mensaje);
/// @brief Pido un entero
/// @param  mensaje = recibe como parametro una cadena para mostrar al momento de pedir el entero
/// @return int = devuelve lo que la funcion pide

#endif /* INGRESO_DE_DATOS_H_ */
