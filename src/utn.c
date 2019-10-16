/*
 * utn.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int getString2(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	if(	pResultado != NULL &&
		pMensaje != NULL &&
		pMensajeError != NULL &&
		minimo <= maximo &&
		reintentos >= 0)
	{
		do
			{
				printf("%s",pMensaje);
				__fpurge(stdin);
				fgets(buffer,sizeof(buffer),stdin);
				buffer[strlen(buffer)-1] = '\0';
				if(strlen(buffer)>=minimo && strlen(buffer) <= maximo)
				{
					strncpy(pResultado,buffer,maximo+1);
					retorno = 0;
				 	break;
				}
				printf("%s",pMensajeError);
				reintentos--;
			}while(reintentos >= 0);
	}
	return retorno;
}
int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
float getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}
int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps)
{
    char auxStr[256];
    int retorno = -1;
    float auxInt;

    do
    {
    	getStringNumerosFlotantes(requestMessage,auxStr);
        auxInt = atof(auxStr);
        if(auxInt > lowLimit && auxInt < hiLimit)
        {
           break;
        }
        printf ("%s",errorMessage);
        attemps--;
    }while(attemps>=0);
    *input = auxInt;
     retorno = 0;
    return retorno;

}
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);

    scanf ("%[^\n]s", input);
}
void clearStdin(void)
{
    setbuf(stdin,NULL);
}
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps)
{
    char auxStr[256];
    int auxInt, i, retorno = -1;

    for(i=0;i<attemps;i++)
    {
    	getInt(requestMessage);
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int esNumerico(char str[])
{
   int i=0;
   int retorno= -1;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           retorno= 0;

       i++;
   }
   return retorno;
}
void clearScreen(void)
{
    system("clear"); //system("cls");
}
int getInt2 (char mensaje[], char error[], int *input, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int aux;
	do
	{
		printf("%s", mensaje);
		scanf("%d", &aux);
		__fpurge(stdin);
		if(aux> minimo && aux<= maximo )
		{



				*input = aux;
				break;

		}
		printf("%s", error);
		reintentos--;
	}while(reintentos>0);

	return retorno;
}

int getCuit	(char*pResultado,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos)
{
int retorno = -1;
char buffer[133];
if(	pResultado != NULL &&
	pMensaje != NULL &&
	pMensajeError != NULL &&
	minimo <= maximo &&
	reintentos >= 0)
{
	do
		{
			printf("%s",pMensaje);

			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1] = '\0';
			__fpurge(stdin);
			if(strlen(buffer)>minimo && strlen(buffer) < maximo)
			{


					if(esNumerico(buffer)==0)
					{
						strncpy(pResultado,buffer,maximo+1);
						retorno = 0;
						break;
					}

			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
}
return retorno;

	return 0;
}

