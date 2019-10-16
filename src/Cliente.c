/*
 * Cliente.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Cliente.h"




int imprimirArrayClientes(struct sCliente *aCliente, int cantidad){
	int i;
	int retorno = -1;
	if(aCliente != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aCliente[i].status == 1)
			{

				printf("Id: %d - Nombre: %s - CUIT: %s - direccion: %s - localidad: %s \n"
				,aCliente[i].idCliente,aCliente[i].nombre,aCliente[i].cuit, aCliente[i].direccion, aCliente[i].localidad);
			}
		}
	}
	return retorno;
}
int imprimirPedidos(struct sPedido *aPedido,struct sCliente *aCliente, int cantidad, int iCliente)
{
	int i;
	int i2;
	int retorno = -1;
	if(aPedido != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			for(i2=0; i2< iCliente; i2++)
			{
				if(aPedido[i].idCliente == aCliente[i2].idCliente)
				{
					if(aPedido[i].status != 0)
					{

						printf("Id: %d - Id del cliente: %d - Nombre cliente: %s\n"
						,aPedido[i].idPedido,aPedido[i].idCliente, aCliente[i2].nombre);
					}
				}
			}

		}
	}
	return retorno;
}
int ingresarPedido(struct sPedido aPedido[],int i,int iClientes)
{
	struct sPedido bPedido;
	getInt2 ("Ingresar id del cliente", "ERROR", &bPedido.idCliente, 0, iClientes, 2);
	getInt2 ("Ingresar kilos totales", "ERROR", &bPedido.kilos, 0, 500, 2);
	bPedido.idPedido = i;
	bPedido.status = 1;

	aPedido[i] = bPedido;
	return 0;
}
int modificarCliente(struct sCliente aArray[], int Mayor)
{
	int id;
	int menuOpcionElegida;
	getInt2 ("Ingresar id del cliente", "ERROR", &id, 0, Mayor, 2);
	do
	{
		printf("\n1-Modificar direccion\
				\n2-Modificar localidad\
				\n3-Salir\
		        \nIngrese opcion: ");
		scanf("%d", &menuOpcionElegida);
	 switch (menuOpcionElegida)
	 {
	 case 1:
		 getString2(aArray[id].direccion,"Ingrese el direccion",
		 					"ERROR", 1, 49, 2);
		 break;
	 case 2:
		 getString2(aArray[id].localidad,"Ingrese el localidad",
		 							"ERROR", 1, 49, 2);
		 break;
	 case 3:
		 break;
	 default:
		 printf("Esa no es una opcion valida");
	 }
	}while(menuOpcionElegida != 3);
	 return 0;
}
int bajarCliente(struct sCliente aArray[], int mayor)
{
	int id;
	struct sCliente baja;
	getInt2 ("Ingresar id del cliente", "ERROR", &id, 0, mayor, 2);
	baja.status = 2;
	aArray[id]= baja;
	return 0;
}
int procesarResiduos(struct sPedido aPedido[], int iMayor)
{
	struct sPedido bPedido;
	int id,hdpe,ldpe,pp;

	getInt2 ("Ingresar id del pedido", "ERROR", &id, 0, iMayor, 2);
	bPedido = aPedido[id];
	getInt2 ("Ingresar la cantidad de HDPE", "ERROR", &hdpe, 0, 10000, 2);
	getInt2 ("Ingresar la cantidad de LDPE", "ERROR", &ldpe, 0, 10000, 2);
	getInt2 ("Ingresar la cantidad de PP", "ERROR", &pp, 0, 10000, 2);
	if(hdpe + ldpe + pp<= bPedido.kilos)
	{
		bPedido.kilosH = hdpe;
		bPedido.kilosL = ldpe;
		bPedido.kilosP = pp;
		bPedido.status= COMPLETADO;
		aPedido[id] = bPedido;
	}
	else
	{
		printf("La suma de los quilos es mayor a el total");
	}



	return 0;
}
int ingresarCliente(struct sCliente *aCliente, int i){
	struct sCliente bCliente;

		getString2(bCliente.nombre,"Ingrese el nombre",
					"ERROR", 1, 49, 2);

		getString2(bCliente.direccion,"Ingrese la direccion",
							"ERROR\n", 1, 49, 2);
		getString2(bCliente.localidad,"Ingrese la localidad",
									"ERROR\n", 1, 49, 2);
		getCuit	(bCliente.cuit,"Ingrese el CUIT",
							"ERROR\n",1,59,2);
		bCliente.idCliente = i; //pone id

		bCliente.status = STATUS_PENDIENTE;


		aCliente[i] = bCliente;

	return 0;
}
int imprimirClientes(struct sCliente *aCliente, struct sPedido *aPedido, int cantidad, int cantidadPedidos)
{
	int i;
	int retorno = -1;
	if(aCliente != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aCliente[i].status == 1)
			{

				printf("Id: %d - Nombre: %s - CUIT: %s - direccion: %s - localidad: %s \n"
				,aCliente[i].idCliente,aCliente[i].nombre,aCliente[i].cuit, aCliente[i].direccion, aCliente[i].localidad);
				if(cantidadPedidos >0)
				{
					printf("Los pedidos que hizo este ciente son: ");
				}

					for(int i2=0; i2< cantidadPedidos; i2++)
					{
						if(aPedido[i2].idCliente == aCliente[i].idCliente)
						{
							if(aPedido[i2].status == 1)
							{
								printf("%d de %d, ", aPedido[i2].idPedido, aPedido[i2].kilos);
							}
						}
					}
			}
		}
	}
	return retorno;
}

int impimirPendientes(struct sPedido *aPedido, struct sCliente *aCliente, int cantidadPedidos, int cantidad)
{
	int i;
	int retorno= -1;
	for(int i2=0; i2< cantidadPedidos; i2++)
	{
		if(aPedido[i2].status == STATUS_PENDIENTE)
		{
			for(i=0; i<cantidad; i++)
			{
				if(aPedido[i2].idCliente == aCliente[i].idCliente)
				{
					printf("CUIT del cliente: %s - direccion: %s - cantidad de kilos a recolectar: %d \n",
							aCliente[i].cuit, aCliente[i].direccion, aPedido[i2].kilos);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
int impimirTerminados(struct sPedido *aPedido, struct sCliente *aCliente, int cantidadPedidos, int cantidad)
{
	int i;
	int retorno= -1;
	for(int i2=0; i2< cantidadPedidos; i2++)
	{
		if(aPedido[i2].status == COMPLETADO)
		{
			for(i=0; i<cantidad; i++)
			{
				if(aPedido[i2].idCliente == aCliente[i].idCliente)
				{
					printf("CUIT del cliente: %s - direccion: %s - kilos de HDPE : %d- kilos de LDPE: %d - kilos de PP : %d \n",
							aCliente[i].cuit, aCliente[i].direccion, aPedido[i2].kilosH, aPedido[i2].kilosL, aPedido[i2].kilosP);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
