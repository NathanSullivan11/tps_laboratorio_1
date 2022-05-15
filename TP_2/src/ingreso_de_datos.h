
#ifndef INGRESO_DE_DATOS_H_
#define INGRESO_DE_DATOS_H_
/**
 * @brief Pide un numero flotante positivos
 * @param mensaje Es el mensaje a mostrar al momento de pedir el numero
 * @param mensajeError Es el mensaje a mostrar en caso de que no sea positivo, muestro por pantalla este mensaje
 * @return Devuelve el flotante validado
 */
float get_FlotantePositivo(char * mensaje, char * mensajeError);
/**
 * @brief Pido un entero
 * @param mensaje Es el mensaje a mostrar al momento de pedir el entero
 * @return Devuelve el entero ingresado
 */
int get_Entero(char * mensaje);
/**
 * @brief Pide un entero y valida que sea mayor a 0
 * @param mensaje Es el mensaje a mostrar al momento de pedir el entero positivo
 * @param mensajeError Es el mensaje a mostrar en caso de que no sea positivo, muestro por pantalla este mensaje
 * @return Devuelve el entero validado
 */
int get_EnteroPositivo(char * mensaje, char * mensajeError);

/**
 * @brief Pide el ingreso de una cadena de caracteres y lo copia a la cadena recibida como parametro
 * @param mensaje Es el mensaje a mostrar al momento de pedir el string
 * @param cadena Es la cadena a la que se le copiara lo ingresado por teclado
 * @param tamanio Es el tamaño maximo de la cadena
 */
void get_String(char * mensaje, char* cadena, int tamanio);

/**
 * @brief Pide el ingreso de un solo caracter
 * @param mensaje Es el mensaje a mostrar al momento de pedir el caracter
 * @return Devuelve el caracter ingresado
 */
char get_Char(char * mensaje);
/**
 *
 * @param mensaje
 * @param cadena
 * @param tamanio
 */
void get_AlphabetString(char* mensaje, char* cadena, int tamanio);
/**
 * @brief Recibe una cadena y valida si supera el maximo de caracteres permitidos
 * @param mensaje Se imprimira en caso de que supere el máximo de caracteres
 * @param cadena Es la cadena de caracteres a validar
 * @param tamanio Tamaó maximo de caracteres
 */
void validarString(char* mensaje, char* cadena, int tamanio);
/**
 * @brief Valida un entero dentro de un rango de enteros.
 * @param mensaje Se imprimira en caso de que el entero no se encuentro dentro del rango
 * @param enteroValidar Es el numero entero a validar
 * @param minimo Es el entero minimo del rango
 * @param maximo Es el entero maximo del rango
 * @return Devuelve el entero validado
 */
int validarEnterosMaxMin(char* mensaje, int enteroValidar, int maximo, int minimo);
/**
 * @brief Valida un caracter dentro de un rango de caracteres.
 * @param mensaje Se imprimira en caso de que el entero no se encuentro dentro del rango
 * @param caracter Es el caracter a validar
 * @param minimo Es el entero minimo del rango
 * @param maximo  Es el entero maximo del rango
 * @return Devuelve el caracter validado
 */
char validarCharMaxMin(char* mensaje, char caracter, char minimo, char maximo);
/**
 * @brief Valida un caracter, dentro de un rango de 2 caracteres
 * @param mensaje Se imprimira en caso de que el caracter no sea
 * @param caracter Es el caracter a validar
 * @param opcion1 Primera opcion del rango a validar
 * @param opcion2 Segunda opcion del rango a validar
 * @return Devuelve el caracter validado
 */
char validarCharDosOpciones(char* mensaje, char caracter, char opcion1, char opcion2);
/**
 * @brief Recibe una cadena y recorre cada caracter verificando que todos sean numeros
 * @param auxiliar Es la cadena a validar
 * @return Devuelve 1 si la cadena es numerica, 0 no es toda numerica y -1 si la cadena recibida == NULL
 */
int validarNumero(char* auxiliar);
/**
 *
 * @param auxiliar
 * @return
 */
int validarCadenaCaracteres(char* auxiliar);
/**
 *
 * @param auxiliar
 * @return
 */
int validarFlotante(char* auxiliar);
float get_Float(char* mensaje);


#endif /* INGRESO_DE_DATOS_H_ */
