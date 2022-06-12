/*
 * gets.h
 *
 *  Created on: 17 may. 2022
 *      Author: DESKTOP
 */

#ifndef GETS_H_
#define GETS_H_


/**
 * @brief Pido un entero
 * @param mensaje Es el mensaje a mostrar al momento de pedir el entero
 * @return Devuelve el entero ingresado
 */
int get_Entero(char * mensaje, int *numero);
/**
 * @brief Pide el ingreso de una cadena de caracteres y lo copia a la cadena recibida como parametro
 * @param mensaje Es el mensaje a mostrar al momento de pedir el string
 * @param cadena Es la cadena a la que se le copiara lo ingresado por teclado
 * @param tamanio Es el tamaño maximo de la cadena
 */
int get_String(char * mensaje, char* cadena, int tamanio);
/**
 * @brief Pide el ingreso de un solo caracter
 * @param mensaje Es el mensaje a mostrar al momento de pedir el caracter
 * @return Devuelve el caracter ingresado
 */
int get_Char(char * mensaje, char *caracter);
/**
 * @brief Pide el ingreso de un nro flotante y lo valida
 * @param mensaje Mensaje a imprimir al momento del pedido
 * @return Devuelve el numero validado
 */
int get_Float(char* mensaje, float *numero);
/**
 * @brief Valida un entero dentro de un rango de enteros.
 * @param mensaje Se imprimira en caso de que el entero no se encuentro dentro del rango
 * @param enteroValidar Es el numero entero a validar
 * @param minimo Es el entero minimo del rango
 * @param maximo Es el entero maximo del rango
 * @return Devuelve el entero validado
 */
void validarEnterosMaxMin(char* mensaje, int *enteroValidar, int minimo, int maximo);
/**
 * @brief Valida un caracter dentro de un rango de caracteres.
 * @param mensaje Se imprimira en caso de que el entero no se encuentro dentro del rango
 * @param caracter Es el caracter a validar
 * @param minimo Es el entero minimo del rango
 * @param maximo  Es el entero maximo del rango
 * @return Devuelve el caracter validado
 */
void validarCharMaxMin(char* mensaje, char *caracter, char minimo, char maximo);
/**
 * @brief Valida un caracter, dentro de un rango de 2 caracteres
 * @param mensaje Se imprimira en caso de que el caracter no sea
 * @param caracter Es el caracter a validar
 * @param opcion1 Primera opcion del rango a validar
 * @param opcion2 Segunda opcion del rango a validar
 * @return Devuelve el caracter validado
 */
void validarCharDosOpciones(char* mensaje, char *caracter, char opcion1, char opcion2);
/**
 * @brief Recibe una cadena y recorre cada caracter verificando que todos sean numeros
 * @param auxiliar Es la cadena a validar
 * @return Devuelve 1 si la cadena es numerica, 0 no es toda numerica y -1 si la cadena recibida == NULL
 */
int esNumerica(char* auxiliar);
/**
 * @brief Valida que una cadena sea unicamente de letras
 * @param auxiliar Cadena a validar
 * @return Devuelve 1 si la cadena es toda de letras, 0 no es toda de letras y -1 si la cadena recibida == NULL
 */
int validarCadenaCaracteres(char* auxiliar);
/**
 * @brief Valida que la cadena sea valida flotante
 * @param auxiliar Auxiliar
 * @return Devuelve 1 si la cadena es ncorrecta, 0 no es correcta y -1 si la cadena recibida == NULL
 */
int esFlotante(char* auxiliar);
/**
 *@brief  Valida que la cadena sea valida como nombre
 * @param auxiliar Cadena a validar
 * @param tamanio tamañ de la cadena
 * @return
 */
int esValidoNombre(char* auxiliar, int tamanio);
/**
 * Pide el ingreso de una cadena valida como nombre
 * @param mensaje Mensaje a imprimir para el prompt
 * @param cadena Cadena a cargar
 * @param tamanio tamañ maximo de la cadena
 * @return
 */
int get_Nombre(char * mensaje, char* cadena, int tamanio);

#endif /* GETS_H_ */
