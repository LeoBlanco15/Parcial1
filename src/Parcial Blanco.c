/*
 ============================================================================
 Name        : Parcial.c
 Author      : Leonardo Blanco
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Cliente.h"



int main(void)
{

	struct sCliente aClientes[1000];
	struct sPedido aPedido[1000];
	int menuOpcionElegida;
	int i=1;
	int iPedidos=1;
	 do
	 {
		 	menuOpcionElegida= 0;
	        printf("\n1-Alta de cliente\
	                 \n2-Modificar datos del cliente\
	                 \n3-Baja del cliente\
	                 \n4-Crear pedido de recoleccion\
	                 \n5-Prosesar residuos\
	                 \n6-Imprimir clientes\
	        		\n7-Imprimir pedidos pendientes\
	        		\n8 Imprimir pedidos prosesados\
	        		 \n9-Salir");
	        scanf("%d", &menuOpcionElegida); //pido la respuesta del menu
	        __fpurge(stdin);
	        	switch (menuOpcionElegida)
	        	{
	        	case 1:
	        		//clearScreen();
	        		ingresarCliente(aClientes, i); //dar de alta empleado
	        		i++;
	        		break;
	        	case 2:
	        		if(i>0)
	        		{
	        			modificarCliente(aClientes, i); // modificar empleados
	        		}
	        		else
	        		{
	        			printf("No es una opcion valida\n");
	        		}
	        		break;
	        	case 3:

	        		if(i>0)
	        		{
	        			bajarCliente(aClientes, i); // elimina el empelado

	        		}
	        		else
	        		{
	        			printf("No es una operacion valida\n");
	        		}
	        		break;
	        	case 4:

	        		if(i>0)
	        		{
	        			imprimirArrayClientes(aClientes, i);
	        			ingresarPedido(aPedido,iPedidos,i);
	        			iPedidos++;
	        		}
	        		else
	        		{
	        			printf("No es una opcion valida\n");
	        		}
	        		break;
	        	case 5:

	        		imprimirPedidos(aPedido,aClientes, iPedidos, i);
	        		procesarResiduos(aPedido, iPedidos);

	        		break;
	        	case 6:
	        		imprimirClientes(aClientes, aPedido, i, iPedidos);
	        		break;
	        	case 7:
	        		impimirPendientes(aPedido, aClientes, iPedidos, i);
	        		break;
	        	case 8:
	        		impimirTerminados(aPedido, aClientes, iPedidos, i);
	        		break;
	        	case 0:
	        		printf("No es una opcion valida\n");
	        		menuOpcionElegida = 9;
	        		break;
	        	default:
	        		printf("No es una opcion valida\n");
	        	}

	        }while (menuOpcionElegida != 9 ); //termina el programa

	return EXIT_SUCCESS;
}
