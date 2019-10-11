/*
 * utn.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef UTN_H_
#define UTN_H_

int getString2(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos);
int esNumericoFlotante(char str[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps);
float getFloat(char* mensaje);
int getInt(char* mensaje);
void getString(char mensaje[],char input[]);
void clearStdin(void);
int getStringNumeros(char mensaje[],char input[]);
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);
void clearScreen(void);
int esNumerico(char str[]);
int getInt2 (char mensaje[], char error[], int *input, int minimo, int maximo, int reintentos);

int getCuit	(char*pResultado,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos);

#endif /* UTN_H_ */
