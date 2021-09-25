/*
 * FuncionesAuxYMat.c
 *
 *  Created on: 21 sep. 2021
 *      Author: Seba
 */

#include <stdio.h>

/// @brief Pide un entero y lo retorna
/// @param mensaje. El mensaje que se va a mostrar al pedir el num entero
/// @return Retorna el numero ingresado

int PedirEntero(char mensaje[]) {
	int numeroIngresado;

	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}

/// @brief Suma dos numeros enteros y retorna el resultado
/// @param primerNumero. Primer operando (entero)
/// @param segundoNumero. Segundo operando (entero)
/// @return Retorna el resultado de la suma de los dos operandos

int Sumar(int primerNumero, int segundoNumero) {
	int resultado;

	resultado = primerNumero + segundoNumero;

	return resultado;
}

/// @brief Resta dos numeros enteros y retorna el resultado
/// @param primerNumero. Primer operando (entero)
/// @param segundoNumero. Segundo operando (entero)
/// @return Retorna el resultado de la resta de los dos operandos

int Restar(int primerNumero, int segundoNumero) {
	int resultado;

	resultado = primerNumero - segundoNumero;

	return resultado;
}

/// @brief Si el segundo operando de una division es cero retorna 0
/// @param segundoNumero. Segundo operando (entero)
/// @return Retorna 0 (false) en caso de que el segundo operando sea 0 (indivisible)

int EsDivisible(int segundoNumero) {
	int retorno = 1;

	if (segundoNumero == 0) {
		retorno = 0;
	}

	return retorno;

}

/// @brief Divide dos numeros enteros (casteados a float) y retorna el resultado
/// @param primerNumero. Primer operando (entero cast)
/// @param segundoNumero. Segundo operando (entero cast)
/// @return Retorna el resultado de la division (float para div decimal) de los dos operandos

float Dividir(int primerNumero, int segundoNumero) {
	float resultado;

	resultado = (float) primerNumero / (float) segundoNumero;

	return resultado;
}

/// @brief Multiplica dos numeros enteros y retorna el resultado
/// @param primerNumero. Primer operando (entero)
/// @param segundoNumero. Segundo operando (entero)
/// @return Retorna el resultado de la resta de los dos operandos

int Multiplicar(int primerNumero, int segundoNumero) {
	int resultado;

	resultado = primerNumero * segundoNumero;

	return resultado;
}


/// @brief Calcula el factorial de un numero entero y retorna el resultado
/// @param primerNumero. Primer operando (entero)
/// @return Retorna el resultado del factorial de un numero entero

int CalcularFactorial(int numeroIngresado) {

	int i;
	int factorial = 1;

	for (i = 1; i <= numeroIngresado; i++) {

		factorial = factorial * i;
	}


	return factorial;

}

