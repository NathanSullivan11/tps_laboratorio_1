/*
 * parser.h
 *
 *  Created on: 24 may. 2022
 *      Author: DESKTOP
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
/**
 * Parsea los datos de los pasajeros desde el archivo data.csv (modo texto).
 * @param pFile FILE*
 * @param pArrayListPassenger LinkedList*
 * @return int
 */
int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger);
/**
 * Parsea los datos de los pasajeros desde el archivo dataBin.bin (modo binario).
 *
 * @param pFile FILE*
 * @param pArrayListPassenger LinkedList*
 * @return int
 */
int parser_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger);
/**
 * Recorre la lista de pasajeros y lo carga en el archivo data.csv (modo texto).
 *
 * @param pFile FILE*
 * @param pArrayListPassenger LinkedList*
 * @return int
 */
int parser_PassengerToText(FILE* pFile, LinkedList* pArrayListPassenger);
/**
 * Recorre la lista de pasajeros y lo carga en el archivo dataBin.bin (modo binario).
 *
 * @param pFile FILE*
 * @param pArrayListPassenger LinkedList*
 * @return int
 */
int parser_PassengerToBinary(FILE* pFile, LinkedList* pArrayListPassenger);
#endif /* PARSER_H_ */
