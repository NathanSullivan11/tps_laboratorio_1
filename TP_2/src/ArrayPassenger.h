/*
 * ArrayPassenger.h
 *
 *  Created on: 20 abr. 2022
 *      Author: DESKTOP
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int idTypePassenger;
	int isEmpty;

}Passenger;

typedef struct{

	char flyCode[10];
	int statusFlight;
	int isEmpty;

}flyCodeStatusFlight;

typedef struct{

	int id;
	char descripcion[16];

}typePassenger;

/**
 * @brief Iniciliaza la lista de pasajeros seteando sus estados a vacios
 * @param list Lista que se recorrera
 * @param len Tamaño de la lista
 * @return 0, si funciono correctamente. -1, si la lista == NULL o el tamaño < 0
 */
int initPassengers(Passenger* list, int len);
/**
 * @brief Hardcodea la lista de codigos y estado de vuelos
 * @param list Lista que se recorrera
 * @param len Tamaño de la lista
 * @return 0, si funciono correctamente. -1, si la lista == NULL o el tamaño < 0
 */
int hardcodeFlyCodeStatusFlight(flyCodeStatusFlight* list, int len);
/**
 *
 * @param list
 * @param len
 * @return
 */
int hardcodeTypePassenger(typePassenger* list, int len);
/**
 * @brief Imprime un menu de opciones y pide el ingreso de alguna
 * @param opciones Mensaje que se imprimir
 * @return Devuelve la opcion ingresada
 */
int menu(char opciones[]);
/**
 * @brief Carga los datos recibidos como parametros a un pasajero por su ID
 * @param list Lista que se recorrera para buscar la coincidencia de ID
 * @param len Tamaño de la lista
 * @param id Id del pasajero a cargar
 * @param name Nombre del pasajero a cargar
 * @param lastName Apellido del pasajero a cargar
 * @param price Precio del vuelo del pasajero a cargar
 * @param typePassenger Tipo de pasajero a cargar
 * @param flycode Código de vuelo del pasajero a cargar
 * @return 0, si funciono correctamente. -1, si la lista == NULL o el tamaño < 0
 */
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
/**
 * @brief Pide el ingreso de cada atributo de la entidad Passenger y almacenandolo en un auxiliar
 * @param listPassenger Lista que se pasara como parametro a la funcion promptFlyCodeStatusFlight();
 * @param lenPassenger Tamaño de la lista pasajeros
 * @param listType Lista que se pasara como parametro a la funcion listTypePassengers()
 * @param lenType Tamaño de la lista tipo de pasajeros
 * @return Devuelve un auxiliar del tipo Passenger completamente cargado
 */
Passenger promptPassenger(flyCodeStatusFlight* listPassenger, int lenPassenger, typePassenger* listType, int lenType);
/**
 * @brief Pide el ingreso de un codigo de vuelo, que debe coincidir con alguno de la lista mostrada.
 * @param list Lista que se recorrera para buscar la coincidencia de codigo
 * @param len Tamaño de la lista
 * @param flyCode Cadena que se le asignara el codigo validado
 * @return 0, si funciono correctamente. -1, si la lista == NULL o el tamaño < 0
 */
int promptFlyCodeStatusFlight(flyCodeStatusFlight* list, int len, char* flyCode);
/**
 * @brief Pide el ingreso del tipo de pasajero
 * @param list List a recorrer
 * @param len Tamaño de la lista
 * @return Devuelve el nro de tipo de pasajero
 */
int promptTypePassenger(typePassenger* list, int len);
/**
 * @brief Imprimir una lista de todos los códigos de vuelo con sus respectivos estados (ACTIVOS o INACTIVOS)
 * @param list Lista que se imprimira
 * @param len Tamaño de la lista
 */
void listFlyCodeStatusFlight(flyCodeStatusFlight* list, int len);
/**
 * @brief Muestra un listado de los tipos de pasajeros
 * @param list Lista a imprimir
 * @param len Tamaño de la lista
 */
void listTypePassengers(typePassenger* list, int len);
/**
 * @brief Recorre una lista y busca coincidencia con el ID recibido.
 * @param list Lista a recorrer
 * @param len Tamaño de la lista
 * @param id Id del pasajero a encontrar en la lista de pasajeros
 * @return Devuelve la posición (index) del pasajero, si lo encontró. -1, Si no encuentra al pasajero, si la lista == NULL o el tamaño < 0.
 */
int findPassengerById(Passenger* list, int len, int id);
/**
 * @brief Modifica el estado del pasajero con ID igual al recibido como parametro
 * @param list Lista a recorrer para buscar la coincidencia de ID
 * @param len Tamaño de la lista
 * @param id Id del pasajero a dar de baja
 * @return 0, si lo dio de baja. -1, si la lista == NULL o el tamaño < 0
 */
int removePassenger(Passenger* list, int len, int id);
/**
 * @brief Se encarga de administrar la opcion informando, llamando a las funciones adecuadas
 * @param listPassenger Lista que se pasara como parametro a otras funciones
 * @param lenPassenger Tamaño de la lista pasajeros
 * @param listFlyCode lista que se pasara como parametro a otras funciones
 * @param lenFlyCode Tamaño de la lista codigo de vuelos
 * @param listType Lista que se pasara como parametro a otras funciones
 * @param lenType Tamaño de la lista tipo de pasajeros
 */
void informar(Passenger* listPassenger, int lenPassenger, flyCodeStatusFlight* listFlyCode, int lenFlyCode, typePassenger* listType, int lenType);
/**
 * @brief Ordena los pasajeros por apellido como 1 er criterio y por tipo de pasajero como 2do criterio. (ASCENDENTEMENTE o DESCENDENTEMENTE)
 * @param list Lista a ordenar
 * @param len Tamaño de la lista
 * @param order Acepta 2 valores, 1 para ordenar de manera ascendente y 0 para ordenar de manera descendente
 * @param listType Lista que se pasara como parametro a otras funciones
 * @param lenType Tamaño de la lista tipo de pasajeros
 * @return 0, si funciono correctamente. -1, si la lista == NULL o el tamaño < 0
 */
int sortPassengers(Passenger* list, int len, int order, typePassenger* listType, int lenType);
/**
 * @brief Ordena los pasajeros por Código de vuelo con estado ACTIVO (ASCENDENTEMENTE o DESCENDENTEMENTE)
 * @param listPassenger Lista a ordenar
 * @param lenPassenger Tamaño de la lista pasajeros
 * @param order  Acepta 2 valores, 1 para ordenar de manera ascendente y 0 para ordenar de manera descendente
 * @param listFlyCode Lista que se recorrera buscando los estados de vuelos ACTIVO
 * @param lenFlyCode Tamaño de la lista código de vuelo
 * @param listType Lista que se pasara como parametro a otras funciones
 * @param lenType Tamaño de la lista tipo de pasajeros
 * @return 0, si funciono correctamente. -1, si la lista == NULL o el tamaño < 0
 */
int sortPassengersByCode(Passenger* listPassenger, int lenPassenger, int order, flyCodeStatusFlight* listFlyCode, int lenFlyCode, typePassenger* listType, int lenType);
/**
 * @brief Imprime la lista de pasajeros completo en forma encolumnada
 * @param listPassenger Lista a imprimir
 * @param lenPassenger Tamaño de la lista
 * @param listType Lista para comparar la lista pasajeros, y poder imprimir el tipo de pasajero adecuado
 * @param lenType Tamaño de la lista tipo de pasajeros
 * @return 0, si funciono correctamente. -1, si la lista == NULL o el tamaño < 0
 */
int printPassengers(Passenger* listPassenger, int lenPassenger, typePassenger* listType, int lenType);
/**
 * @brief Modifica un atributo de un pasajero de la lista
 * @param listPassenger Lista que se pasara como parametro a las funciones sortPassengers y sortPassengersByCode()
 * @param lenPassenger Tamaño de la lista pasajeros
 * @param index La posicion del pasajero a modificar
 * @param attribute Es el atributo a modificar del elemento de tipo Passenger
 * @param listFlyCode Lista que se pasara como parametro a la funcion sortPassengersByCode()
 * @param lenFlyCode Tamaño de la lista codigo de vuelos
 * @return 0, si se modifico algun pasajero. -1, si la lista == NULL o el tamaño < 0
 */
int modifyPassenger(Passenger* listPassenger, int lenPassenger, int index, int attribute, flyCodeStatusFlight* listFlyCode, int lenFlyCode, typePassenger* listType, int lenType);
/**
 * @brief Pide el ID del pasajero a modificar, y si lo encuentra imprime un submenu con los atributos que se pueden modificar, y por ultimo llama a las funciones correspondientes
 * @param listPassenger Lista que se pasara como parametro a la funcion modifiyPassengers()
 * @param lenPassenger Tamaño de la lista pasajeros
 * @param listFlyCode Lista que e pasara como parametro a la funcion modifiyPassengers()
 * @param lenFlyCode Tamaño de la lista codigo de vuelos
 * @param listType LLista que se pasara como parametro a la funcion modifiyPassengers()
 * @param lenType Tamaño de la lista tipo de pasajeros
 */
void modificar(Passenger* listPassenger, int lenPassenger, flyCodeStatusFlight* listFlyCode, int lenFlyCode, typePassenger* listType, int lenType);
/**
 * @brief Pide el ID del pasajero a dar de baja, y luego imprime un mensaje para confirmar la baja.
 * @param list Lista a recorrer buscando la coincidencia de ID
 * @param len Tamaño de la lista
 * @param listType Lista que se pasara como parametro a otras funciones
 * @param lenType Tamaño de la lista tipo de pasajeros
 */
void baja(Passenger* list, int len, typePassenger* listType, int lenType);
/**
 * @brief Calcula e imprime el total de precios de vuelo, el promedio de precios de los pasajeros cargados en el sistema y la cantidad de pasajeros que no superan el promedio
 * @param list Lista a recorrer para calcular lo debido
 * @param len Tamaño de la lista
 * @return 0, si funciono correctamente. -1, si la lista == NULL o el tamaño < 0
 */
int calculateTotalAverage(Passenger* list, int len);
/**
 * @brief Busca si hay algun pasajero cargado en el sistema
 * @param list Lista a recorrer
 * @param len Tamaño de la lista
 * @return 1, si hay por lo menos uno cargado. 0, si no hay niguno. Y -1, si si la lista == NULL o el tamaño < 0
 */
int findLoadPassengers(Passenger* list, int len);
/**
 * @brief Hace una carga forzada de 5 pasajeros a la lista
 * @param list Lista a la que se le cargara los pasajerosdatos
 * @param id Es el id autoincremental, creado en el main, que se asignara a cada pasajero cargado.
 * @return Devuelve el ID para que siga un orden lógico
 */
int forcedPassengerLoad(Passenger* list, int len, int id);
/**
 * @brief Imprime un unico pasajero, con todos sus atributos
 * @param pasajero Pasajero a imprimir
 * @param listType Lista a recorrer para imprimir el tipo de pasajero adecuado
 * @param lenType Tamaño de la lista typePassenger
 */
void printOnePassenger(Passenger pasajero, typePassenger* listType, int lenType);
/**
 * @brief Imprime una lista de los pasajeros con estado de vuelo ACTIVO
 * @param listPassenger Lista a imprimir
 * @param lenPassenger Tamaño de la lista
 * @param listFlyCode Lista a recorrer para corroborar el estado de vuelo ACTIVO
 * @param lenFlyCode Tamaño de la lista flyCode
 * @param listType Lista a recorrer para imprimir el tipo de pasajero adecuado
 * @param lenType Tamaño de la lista tipo de pasajeros
 */
void printActivePassengers(Passenger* listPassenger, int lenPassenger, flyCodeStatusFlight* listFlyCode, int lenFlyCode, typePassenger* listType, int lenType);
/**
 * @brief Pide el ingreso de un nuevo código de vuelo
 * @param list Lista a la que se le cargara lo pedido
 * @param len Tamaño de la lista
 * @param auxFlyCode Es la cadena en la que se cargara el codigo ingresado.
 */
void promptNewFlyCode(flyCodeStatusFlight* list, int len, char* auxFlyCode);
#endif /* ARRAYPASSENGER_H_ */
