#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Parser.h"
#include "gets.h"

int main(void)
{
	setbuf(stdout, NULL);

    LinkedList* listaPasajeros;
    LinkedList* listaCodigosDevuelo;
    int opcion;
	int banderaGuardadoArchivo = 0;
	int banderaLecturaArchivo = 0;
	int confirmacionGuardado;

    listaPasajeros = ll_newLinkedList();
    listaCodigosDevuelo = ll_newLinkedList();
    controller_initFlyCodes(listaCodigosDevuelo);

    do{
    	opcion = passenger_menuInt("\n1. Cargar los datos de los pasajeros desde archivo en modo texto\n2. Cargar los datos de los pasajeros desde archivo en modo binario\n3. Alta de pasajero\n4. Modificar datos de pasajero\n5. Baja de pasajero\n6. Listar pasajeros\n7. Ordenar\n8. Guardar los datos de los pasajeros en modo texto\n9. Guardar los datos de los pasajeros en modo binario\n10. Salir\n",1,10);
        switch(opcion)
        {
            case 1: //  Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
				if(!controller_loadFromText("data.csv",listaPasajeros))
				{
					banderaLecturaArchivo = 1;
					printf("\n=====================================\nArchivo de texto leido CORRECTAMENTE\n=====================================\n");
				}
                break;
            case 2: //  Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
				if(!controller_loadFromBinary("dataBin.bin",listaPasajeros))
				{
					banderaLecturaArchivo = 1;
					printf("\n===========================================\nArchivo binario leido CORRECTAMENTE\n===========================================\n");
				}
            	break;
            case 3: //  Alta de pasajero
            	if(controller_addPassenger(listaPasajeros, listaCodigosDevuelo) == 0)
            	{
            		printf("\n==============================\nPasajero cargado correctamente\n==============================\n");
            	}
            	else
            	{
            		printf("\n===========================================\nError: No se pudo cargar el pasajero\n===========================================\n");
            	}
            	break;
            case 4: //  Modificar datos de pasajero
            	if(!ll_isEmpty(listaPasajeros))
            	{
            		if(!controller_editPassenger(listaPasajeros, listaCodigosDevuelo))
            		{
            			printf("\nModificado CORRECTAMENTE...");
            		}
            		else
            		{
            			printf("\nNo se pudo modificar al pasajero");
            		}
            	}
            	else
            	{
					printf("\n===========================================\nNo hay pasajeros para modificar\n===========================================\n");
            	}
            	break;
            case 5: //  Baja de pasajero
            	if(!ll_isEmpty(listaPasajeros))
            	{
            		if(!controller_removePassenger(listaPasajeros))
            		{
            			printf("\nDado de baja CORRECTAMENTE...");
            		}
            	}
            	else
            	{
					printf("\n===========================================\nNo hay pasajeros para dar de baja\n===========================================\n");

            	}
            	break;
            case 6: //  Listar pasajeros
            	if(!ll_isEmpty(listaPasajeros))
            	{
            		printf("/******** LISTA DE PASAJEROS ********/");
            		controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
					printf("\n===========================================\nNo hay pasajeros cargados en el sistema\n===========================================\n");
            	}
            	break;
            case 7: //  Ordenar pasajeros
            	if(!ll_isEmpty(listaPasajeros))
				{
            		if(!controller_sortPassenger(listaPasajeros))
					{
						printf("\n===========================================\nSe ordenaron los pasajeros CORRECTAMENTE\n===========================================\n");
					}
				}
            	else
            	{
					printf("\n===========================================\nNo hay pasajeros para ordenar\n===========================================\n");
            	}

            	break;
            case 8: //  Guardar los datos de los pasajeros en modo texto
            	if(!ll_isEmpty(listaPasajeros))
            	{
					if(banderaLecturaArchivo == 1)
					{
						controller_saveAsText("data2.csv", listaPasajeros);
					}
					else
					{
						printf("\n============================================================\n¡¡¡¡SI GUARDA AHORA SE PERDERAN LOS PASAJEROS CARGADOS EN EL ARCHIVO!!!!\n============================================================\n");
						get_Entero("Si desea guardarlo igualmente ingrese 1: ", &confirmacionGuardado);
						if(confirmacionGuardado == 1 && !controller_saveAsText("data2.csv", listaPasajeros))
						{
							printf("\n=========================\nArchivo de texto guardado correctamente\n=========================\n");
							banderaGuardadoArchivo = 1;
						}
					}
            	}
            	else
            	{
            		printf("\n=====================================\nNo hay pasajeros cargados para guardar\n=====================================\n");
            	}
            	break;
            case 9: //  Guardar los datos de los pasajeros en modo binario
            	if(!ll_isEmpty(listaPasajeros))
            	{
					if(!controller_saveAsBinary("dataBin.bin", listaPasajeros))
					{
						printf("Guardado correctamente");
						banderaGuardadoArchivo = 1;
					}
            	}
            	else
            	{
            		printf("\n=====================================\nNo hay pasajeros cargados para guardar\n=====================================\n");
            	}
            	break;
            case 10: // Salir
            	if(banderaGuardadoArchivo == 0)
            	{
            		opcion = 0;
            		printf("\n================================================\nDebe guardar la lista antes de salir del sistema\n================================================\n");
            	}
            	else
            	{
            		printf("\n==========================\nSaliste CORRECTAMENTE\n==========================\n");
            	}
            	break;
            default:
            	printf("\nOpcion INEXISTENTE");
            	break;
        }
    }while(opcion != 10);

    ll_deleteLinkedList(listaPasajeros);
    ll_deleteLinkedList(listaCodigosDevuelo);

    return 0;
}

