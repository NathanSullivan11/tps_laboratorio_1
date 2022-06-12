/*
 * utn.h
 *
 *  Created on: 24 may. 2022
 *      Author: DESKTOP
 */

#ifndef UTN_H_
#define UTN_H_

int getString(char* cadena, int longitud);

int getDescripcion(char* mensaje, char* pResultado, int longitud);
int getNombre(char* mensaje, char* pResultado, int longitud);
int getNumeroEntero(char* mensaje, int* pResultado);
int getNumeroFlotante(char* mensaje, float* pResultado);

int esNumero(char* auxiliar);
int esFloat(char* cadena);
int esDescripcion(char* cadena, int longitud);
int esNombre(char* cadena, int longitud);

#endif /* UTN_H_ */
