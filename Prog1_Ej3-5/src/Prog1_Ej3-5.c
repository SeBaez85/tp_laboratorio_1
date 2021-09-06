/*Sebastian Baez 1ero E
 ============================================================================
 Name        : Prog1_Ej3-5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 3-5:
 Realizar un programa en donde se puedan utilizar los prototipos de la función Sumar en
 sus 4 combinaciones.
 int Sumar1(int, int);
 int Sumar2(void);
 void  Sumar3(int, int);
 void Sumar4(void);
 */

#include <stdio.h>
#include <stdlib.h>

int Sumar1(int primerNumero, int segundoNumero);
int Sumar2(void);
void Sumar3(int primerNumero, int segundoNumero);
void Sumar4(void);

int main(void) {
	setbuf(stdout, NULL);
	int suma1;
	int suma2;


	suma1 = Sumar1(10, 5);
	printf("La suma 1 es: %d \n", suma1);

	suma2 = Sumar2();
	printf("La suma 2 es: %d \n", suma2);

	Sumar3(3, 7);

	Sumar4();

	return EXIT_SUCCESS;
}

int Sumar1(int primerNumero, int segundoNumero) {
	int resultado;

	resultado = primerNumero + segundoNumero;

	return resultado;
}
int Sumar2(void) {
	int primerNumeroSumar2;
	int segundoNumeroSumar2;
	int resultadoSumar2;

	primerNumeroSumar2 = 10;
	segundoNumeroSumar2 = 25;


	resultadoSumar2 = primerNumeroSumar2 + segundoNumeroSumar2;

	return resultadoSumar2;
}
void Sumar3(int primerNumero, int segundoNumero) {

	int resultadoSumar3;



	resultadoSumar3 = primerNumero + segundoNumero;

	printf("La suma 3 es: %d \n", resultadoSumar3);

}
void Sumar4(void)
{
	int resultadoSumar4;



	resultadoSumar4 = 6 + 8;

	printf("La suma 4 es: %d \n", resultadoSumar4);

}
