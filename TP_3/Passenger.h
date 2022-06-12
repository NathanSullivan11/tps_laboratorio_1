/*
 * Passenger.h
 *
 *  Created on: 20 may. 2022
 *      Author: DESKTOP
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#define NAME_LEN 51
#define FLYCODE_LEN 10

typedef struct{

	int id;
	char name[NAME_LEN];
	char lastName[NAME_LEN];
	float price;
	char flyCode[FLYCODE_LEN];
	int typePassenger;
	int statusFlight;

}Passenger;

typedef struct{

	char flyCode[FLYCODE_LEN];
	int statusFlight;

}FlyCode;

/*==========================================================================================*/
/*  ===================           FUNCIONES PASSENGER               ========================*/
/*==========================================================================================*/

/**
 * Reserva memoria de manera dinamica para un puntero del tipo Passenger
 * @return Passenger*
 */
Passenger* passenger_new(void);
/**
 * Recibe cada atributo de un pasajero en string, y lo crea si todos los datos son válidos
 * @param char* id
 * @param char* name
 * @param char* lastName
 * @param char* price
 * @param char* flyCode
 * @param char* typePassenger
 * @param char* statusFlight
 * @return Passenger* si salio ok. NULL si hubo error
 */
Passenger* passenger_newParametrosTxt(char* id, char* name,char* lastName, char* price, char* flyCode, char* typePassenger, char* statusFlight);
/**
 * Recibe cada atributo de un pasajero, excepto el id, y lo crea si todos los datos son válidos
 * @param char* name
 * @param char* lastName
 * @param float price
 * @param char* flyCode
 * @param int typePassenger
 * @param int statusFlight
 * @return Passenger* si salio ok. NULL si hubo error
 */
Passenger* passenger_newParametros(char* name,char* lastName,  float price, char* flyCode, int typePassenger, int statusFlight);
/**
 * Maneja un menú con opciones para modificar un pasajero
 * @param LinkedList* pArrayListPassenger
 * @param LinkedList* pArrayFlyCodes
 * @param Passenger* this
 * @return int 1 si salio ok. -1 si hubo error
 */
int passenger_edit(LinkedList* pArrayListPassenger, LinkedList* pArrayFlyCodes,Passenger* this);
/**
 * Libera un pasajero de la memoria
 * @param Passenger* this
 * @return int 1 si salio ok. -1 si hubo error
 */
int passenger_delete(Passenger* this);
/**
 * Remueve un pasasjero de la lista
 * @param LinkedList* pArrayListPassenger
 * @param int index
 * @return int 1 si salio ok. -1 si hubo error
 */
int passenger_removeOne(LinkedList* pArrayListPassenger, int index);
/**
 * Lista todos los campos de un pasajero
 * @param LinkedList* pArrayListPassenger
 * @param Passenger* this
 * @return int 1 si salio ok. -1 si hubo error
 */
int passenger_printOne(LinkedList* pArrayListPassenger, Passenger* this);
/**
 * Pide al usuario la carga de un nuevo pasajero
 * @param LinkedList* pArrayFlyCodes
 * @param char* name
 * @param char* lastName
 * @param float* price
 * @param char* flyCode
 * @param int* typePassenger
 * @param int* statusFlight
 * @return int 1 si salio ok. -1 si hubo error
 */
int passenger_promptPassenger(LinkedList* pArrayFlyCodes, char* name,char* lastName, float* price, char* flyCode, int* typePassenger,int* statusFlight);
/**
 * Imprime un menu numerico y pide el ingreso de una opcion
 * @param char options
 * @param int min Primera opcion del menu
 * @param int max Ultima opcion del menu
 * @return int Devuelve la opcion ingresada
 */
int passenger_menuInt(char options[], int min, int max);
/**
 * Maneja un menú con opcion para ordenar la lista de pasajero
 * @param pArrayListPassenger
 * @return int 1 si salio ok. -1 si hubo error
 */
int passenger_sort(LinkedList* pArrayListPassenger);
/**
 * Compara dos pasajeros por su nombre
 * @param void* p1
 * @param void* p2
 * @return 1 (p1 > p2), -1 (p1 < p2) o 0 (p1 = p2)
 */
int passenger_compareByName(void* p1, void* p2);
/**
 * Compara dos pasajeros por su id
 * @param void* p1
 * @param void* p2
 * @return 1: (p1 > p2), -1: (p1 < p2) o 0: (p1 = p2)
 */
int passenger_compareById(void* p1, void* p2);
/**
 * Compara dos pasajeros por su código de vuelo
 * @param void* p1
 * @param void* p2
 * @return 1: (p1 > p2), -1: (p1 < p2) o 0: (p1 = p2)
 */
int passenger_compareByFlyCode(void* p1, void* p2);
/**
 * Imprime un menu alfabetico y pide el ingreso de una opcion
 * @param char options
 * @param char min Primera opcion del menu
 * @param char max Ultima opcion del menu
 * @return char Devuelve la opcion ingresada
 */
char passenger_menuChar(char options[], char min, char max);
/**
 * Recibe un string estado de vuelo y lo transforma a tipo int
 * @param statusFlight
 * @return int Devuelve 1,2,3 o 4 dependiendo de cual sea el estado de vuelo. -1 si hubo error
 */
int passenger_readStatusFlightChar(char* statusFlight);
/**
 * Recibe un string tipo de pasajero y lo transforma a tipo int
 * @param char* typePassenger
 * @return int Devuelve 1,2 o 3 dependiendo de cual sea el estado de vuelo. -1 si hubo error
 */
int passenger_readTypePassengerChar(char* typePassenger);
/**
 * Recibe un entero estado de vuelo y lo transforma a string
 * @param int statusFlight
 * @param char* charStatusFlight
 * @return int 0 si salio ok. -1 si hubo error
 */
int passenger_readStatusFlightInt(int statusFlight, char* charStatusFlight);
/**
 * Recibe un entero tipo de pasajero y lo transforma a string
 * @param int typePassenger
 * @param char* charTypePassenger
 * @return int 0 si salio ok. -1 si hubo error
 */
int passenger_readTypePassengerInt(int typePassenger,char* charTypePassenger);
/**
 * Imprime todos los tipos de pasajero
 */
void passenger_listTypesPassengers(void);
/**
 * Imprimi todos los estado de vuelo
 */
void passenger_listStatusFlights(void);
/**
 * Le asigna el id proximo a un pasajero
 * @param Passenger* this
 * @return int 0 si salio ok. -1 si hubo error
 */
int passenger_assignNextId(Passenger* this);
/**
 * Carga el úlitmo id al archivo idsPasajeros.csv
 * @param int lastId
 * @return  int 0 si salio ok. -1 si hubo error
 */
int passenger_loadLastId(int lastId);

/************** ****************************************************************************/
/**************                 SETTERS Y GETTERS                 **************************/
/************** ****************************************************************************/
/**
 * Le asigna un id a un pasajero
 * @param Passenger* this
 * @param id
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_setId(Passenger* this, int id);
/**
 * Le asigna un id recibido como string a un pasajero
 * @param Passenger* this
 * @param char* id
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_setIdTxt(Passenger* this, char* id);
/**
 * Obtiene el id de un pasajero
 * @param Passenger* this
 * @param int id
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_getId(Passenger* this, int* id);
/**
 * Le asigna un nombre a un pasajero
 * @param Passenger* this
 * @param char* name
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_setName(Passenger* this, char* name);
/**
 * Obtiene el nombre de un pasajero
 * @param Passenger* this
 * @param char* name
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_getName(Passenger* this, char* name);
/**
 * Le asigna un apellido a un pasajero
 * @param Passenger* this
 * @param char* lastName
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_setLastName(Passenger* this, char* lastName);
/**
 * Obtiene el apellido de un pasajero
 * @param Passenger* this
 * @param char* lastName
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_getLastName(Passenger* this, char* lastName);
/**
 * Le asigna un flyCode a un pasajero
 * @param Passenger* this
 * @param char* flyCode
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_setFlyCode(Passenger* this, char* flyCode);
/**
 * Obtiene el flyCode de un pasajero
 * @param Passenger* this
 * @param char* flyCode
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_getFlyCode(Passenger* this, char* flyCode);
/**
 * Le asigna un precio a un pasajero
 * @param Passenger* this
 * @param price
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_setPrice(Passenger* this, float price);
/**
 * Le asigna un precio recibido como string a un pasajero
 * @param Passenger* this
 * @param char* price
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_setPriceTxt(Passenger* this, char* price);
/**
 * Obtiene el precio de un pasajero
 * @param Passenger* this
 * @param price
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_getPrice(Passenger* this, float* price);
/**
 * Le asigna un typePassenger a un pasajero
 * @param Passenger* this
 * @param typePassenger
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_setTypePassenger(Passenger* this, int typePassenger);
/**
 * Le asigna un typePassenger recibido como string a un pasajero
 * @param Passenger* this
 * @param char* typePassenger
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_setTypePassengerTxt(Passenger* this, char* typePassenger);
/**
 * Obtiene el typePassenger de un pasajero
 * @param Passenger* this
 * @param typePassenger
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_getTypePassenger(Passenger* this, int* typePassenger);
/**
 * Obtiene el typePassenger de un pasajero como string
 * @param Passenger* this
 * @param char* typePassenger
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_getTypePassengerTxt(Passenger* this, char* typePassenger);
/**
 * Le asigna un statusFlight a un pasajero
 * @param Passenger* this
 * @param statusFlight
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_setStatusFlight(Passenger* this, int statusFlight);
/**
 * Le asigna un statusFlight recibido como string a un pasajero
 * @param Passenger* this
 * @param char* statusFlight
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_setStatusFlightTxt(Passenger* this, char* statusFlight);
/**
 * Obtiene el statusFlight de un pasajero
 * @param Passenger* this
 * @param statusFlight
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_getStatusFlight(Passenger* this, int* statusFlight);
/**
 * Obtiene el statusFlight de un pasajero como string
 * @param Passenger* this
 * @param char* statusFlight
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int passenger_getStatusFlightTxt(Passenger* this, char* statusFlight);



/*==========================================================================================*/
/*  ===================            FUNCIONES FLYCODE               =========================*/
/*==========================================================================================*/

/**
 * Reserva memoria de manera dinamica para un puntero del tipo FlyCode
 * @return FlyCode*
 */
FlyCode* flycode_newFlyCode(void);
/**
 * Agrega un código de vuelo a la lista
 * @param LinkedList* pArrayFlyCodes
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int flycode_addNewFlyCode(LinkedList* pArrayFlyCodes);
/**
 * Imprime la lista de códido de vuelos
 * @param LinkedList* pArrayFlyCodes
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int flycode_listFlyCodes(LinkedList* pArrayFlyCodes);
/**
 * Pide el ingreso de un código de vuelo
 * @param LinkedList* pArrayFlyCodes
 * @param char* string
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int flycode_getNewFlyCode(LinkedList* pArrayFlyCodes, char* string);
/**
 * Valida que la cadena tenga el formato valido para código de vuelo
 * @param char* string
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int flycode_isValidFlyCode(char* string);
/**
 * Asigna un estado de vuelo a una estructura FlyCode
 * @param FlyCode* this
 * @param int statusFlight
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int flycode_setStatusFlight(FlyCode* this, int statusFlight);
/**
 * Asigna un código de vuelo a una estructura FlyCode
 * @param FlyCode* this
 * @param char* flyCode
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int flycode_setFlyCode(FlyCode* this, char* flyCode);
/**
 * Pide el ingreso de un FlyCode existente
 * @param pArrayFlyCodes
 * @param flyCode
 * @param statusFlight
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int flycode_getFlyCode(LinkedList* pArrayFlyCodes, char* flyCode, int* statusFlight);
/**
 * Pide al usuario un código de vuelo de la lista y le asigna su estado correspondiente
 * @param LinkedList* pArrayFlyCodes
 * @param char* flyCode
 * @param char* statusFlight
 * @return int Devuelve 0 si salio ok. -1 si hubo error
 */
int flycode_promptFlyCode(LinkedList* pArrayFlyCodes, char* flyCode, int* statusFlight);


#endif /* PASSENGER_H_ */
