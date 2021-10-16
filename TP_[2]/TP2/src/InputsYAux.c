/*
 * InputsYAux.c
 *
 *  Created on: 30 sep. 2021
 *      Author: Seba
 */

#include "InputsYAux.h"

/**
 * @brief Recibe una cadena, valida que el ingreso sea un flotante y lo retorna convertido
 * @param cadena char La cadena de caracteres que se ingresa
 * @param mensaje char El mensaje que se muestra al usuario
 * @param tam int El tamanio de la cadena de caracteres ingresada
 * @param pNumeroValidado *float El valor validado y convertido en flotante
 * @return return int Retorna 0 si no pudo cumplir su funcion y 1 si pudo
 */
int getStringFlotante(char cadena[], char mensaje[], int tam,
		float *pNumeroValidado)
{
	char auxiliarString[1000];
	float retorno;
	int i;
	int contadorPuntos = 0;
	retorno = 0;
	if (cadena != NULL && mensaje != NULL)
	{
		retorno = 1;
		printf(mensaje);
		fflush(stdin);
		gets(auxiliarString);
		for (i = 0; i < tam && auxiliarString[i] != '\0'; i++)
		{
			if (i == 0
					&& (auxiliarString[i] == '+' || auxiliarString[i] == '-'))
			{
				continue;
			}
			if ((auxiliarString[i] != ' ') && (auxiliarString[i] != '.')
					&& (auxiliarString[i] < '0' || auxiliarString[i] > '9'))
			{
				printf("Error. El ingreso debe contener numeros enteros o decimales: ");
				fflush(stdin);
				gets(auxiliarString);

			}

		}
		if (cadena[i] == '.')
		{
			contadorPuntos++;

		}
	}
	if (contadorPuntos == 1)
	{
		return 1;
	}
	strcpy(cadena, auxiliarString);
	*pNumeroValidado = atof(cadena);
	return retorno;

}

/**
 * @brief Recibe una cadena, valida que el ingreso sea un entero y lo retorna convertido
 * @param cadena char La cadena de caracteres que se ingresa
 * @param mensaje char El mensaje que se muestra al usuario
 * @param tam int El tamanio de la cadena de caracteres ingresada
 * @param pNumeroValidado int* El valor validado y convertido en entero
 * @return retorno int Retorna 0 si no pudo cumplir su funcion y 1 si pudo
 */

int getStringNumerica(char cadena[], char mensaje[], int tam,
		int *pNumeroValidado)
{
	char auxiliarString[1000];
	int retorno;
	int i;
	retorno = 0;
	if (cadena != NULL && mensaje != NULL)
	{
		retorno = 1;
		printf(mensaje);
		fflush(stdin);
		gets(auxiliarString);
		for (i = 0; i < tam && auxiliarString[i] != '\0'; i++)
		{
			if (i == 0
					&& (auxiliarString[i] == '+' || auxiliarString[i] == '-'))
			{
				continue;
			}
			if (auxiliarString[i] > '9' || auxiliarString[i] < '0')
			{
				printf("Error. El ingreso debe contener solo numeros: ");
				fflush(stdin);
				gets(auxiliarString);
				break;
			}
		}
		strcpy(cadena, auxiliarString);
		*pNumeroValidado = atoi(cadena);

	}

	return retorno;

}

/**
 * @brief Recibe una cadena y valida que el ingreso sea solo letras
 * @param cadena char La cadena de caracteres que se ingresa
 * @param mensaje char El mensaje que se muestra al usuario
 * @param tam int El tamanio de la cadena de caracteres ingresada
 * @return retono int Retorna 0 si no pudo cumplir su funcion y 1 si pudo
 */

int getStringSoloLetras(char cadena[], char mensaje[], int tam)
{
	char auxiliarString[1000];
	int retorno;
	int i;
	retorno = 0;
	if (cadena != NULL && mensaje != NULL)
	{
		retorno = 1;
		printf(mensaje);
		fflush(stdin);
		gets(auxiliarString);
		for (i = 0; i < tam && auxiliarString[i] != '\0'; i++)
		{
			if (i == 0
					&& (auxiliarString[i] == '+' || auxiliarString[i] == '-'))
			{
				continue;
			}
			if ((auxiliarString[i] != ' ')
					&& (auxiliarString[i] < 'a' || auxiliarString[i] > 'z')
					&& (auxiliarString[i] < 'A' || auxiliarString[i] > 'Z'))
			{
				printf("Error. El ingreso debe contener solo letras: ");
				fflush(stdin);
				gets(auxiliarString);
				break;
			}
		}
		strcpy(cadena, auxiliarString);

	}

	return retorno;

}
