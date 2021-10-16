/*
 * InputsYAux.h
 *
 *  Created on: 30 sep. 2021
 *      Author: Seba
 */

#ifndef INPUTSYAUX_H_
#define INPUTSYAUX_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getStringSoloLetras(char cadena[], char mensaje[], int tam);
int getStringNumerica(char cadena[], char mensaje[], int tam, int* pNumeroValidado);
int getStringFlotante(char cadena[], char mensaje[], int tam, float* pNumeroValidado);

#endif /* INPUTSYAUX_H_ */
