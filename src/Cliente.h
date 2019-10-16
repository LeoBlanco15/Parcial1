/*
 * Cliente.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1
#define QTY_EMPLEADOS 10
#define QTY_NOMBRES 10
#define QTY_CARACTERES 50
#define STATUS_PENDIENTE 1
#define COMPLETADO 2

struct sCliente
{
	int idCliente;
	int status;
	//***************
	char nombre[50];
	char cuit[13];
	char direccion[50];
	char localidad[50];
};
struct sPedido
{
	int idPedido;
	int status;
	//**************
	int idCliente;
	int kilos;
	int kilosH;
	int kilosL;
	int kilosP;
};
int imprimirArrayClientes(struct sCliente *aEmpleado, int cantidad);;
int ingresarCliente(struct sCliente *aEmpleados, int i);

int modificarCliente(struct sCliente aArray[], int mayor);
int bajarCliente(struct sCliente aArray[], int mayor);
int ingresarPedido(struct sPedido aPedido[],int i,int iClientes);
int imprimirPedidos(struct sPedido *aPedido,struct sCliente *aCliente, int cantidad, int iCliente);
int procesarResiduos(struct sPedido aPedido[], int iMayor);
int imprimirClientes(struct sCliente *aCliente, struct sPedido *aPedido, int cantidad, int cantidadPedidos);
int impimirPendientes(struct sPedido *aPedido, struct sCliente *aCliente, int cantidadPedidos, int cantidad);
int impimirTerminados(struct sPedido *aPedido, struct sCliente *aCliente, int cantidadPedidos, int cantidad);

#endif /* CLIENTE_H_ */
