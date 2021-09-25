/* Sebastian Baez 1ero E
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAuxYMat.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int primerOperando;
	int segundoOperando;
	int suma;
	int resta;
	float division;
	int multiplicacion;
	int factorialPrimerOperando;
	int factorialSegundoOperando;
	int flagPrimerOperando = 0;
	int flagSegundoOperando = 0;

	do {
		if(flagPrimerOperando == 0) {
			printf("1. Ingreso del primer operando\n");
		} else{
			printf("1. Ingreso del primer operando (A = %d)\n", primerOperando);
		}

		if(flagSegundoOperando == 0) {
					printf("2. Ingreso del segundo operando\n");
				} else{
					printf("2. Ingreso del segundo operando (B = %d)\n", segundoOperando);
				}
		printf("3. Calculo de las operaciones\n");
		printf("4. Informe de resultados\n");
		printf("5. Salir\n");
		printf("Elija una opcion: ");
		scanf("%d", &opcion);
		switch (opcion) {
		case 1:
			primerOperando = PedirEntero("Ingrese el primer operando: ");
			flagPrimerOperando = 1;
			break;
		case 2:

			segundoOperando = PedirEntero("Ingrese el segundo operando: ");
			flagSegundoOperando = 1;
			break;
		case 3:
			if(flagPrimerOperando == 0 || flagSegundoOperando == 0){
				printf("Debe ingresar primero ambos operandos\n");
				break;
			}

			printf("a) Calcular suma (%d + %d)\n", primerOperando,
					segundoOperando);
			printf("b) Calcular resta (%d - %d)\n", primerOperando,
					segundoOperando);
			printf("c) Calcular division (%d / %d)\n", primerOperando,
					segundoOperando);
			printf("d) Calcular multiplicacion (%d * %d)\n", primerOperando,
					segundoOperando);
			printf("e) Calcular el factorial de %d y %d\n", primerOperando,
					segundoOperando);
			break;
		case 4:
			if(flagPrimerOperando == 0 || flagSegundoOperando == 0){
							printf("Debe ingresar primero ambos operandos\n");
							break;
						}
			suma = Sumar(primerOperando, segundoOperando);
			printf("a) El resultado de %d + %d es: %d\n", primerOperando,
					segundoOperando, suma);

			resta = Restar(primerOperando, segundoOperando);
			printf("b) El resultado de %d - %d es: %d\n", primerOperando,
					segundoOperando, resta);

			if (EsDivisible(segundoOperando) == 0) {
				printf("c) No es posible dividir por cero\n");
			} else {
				division = Dividir(primerOperando, segundoOperando);
				printf("c) El resultado de %d / %d es: %.2f\n", primerOperando,
						segundoOperando, division);
			}

			multiplicacion = Multiplicar(primerOperando, segundoOperando);
			printf("d) El resultado de %d * %d es: %d\n", primerOperando,
					segundoOperando, multiplicacion);

			printf("e) ");
			if (primerOperando == 0) {
				printf("El factorial de 0 es: 1 y ");
			} else {
				if (primerOperando < 0) {
					printf(
							"El primer operando es negativo por lo que no se puede calcular el factorial y ");
				} else {
					factorialPrimerOperando = CalcularFactorial(primerOperando);
					printf("El factorial de %d es: %d y ", primerOperando,
							factorialPrimerOperando);
				}
			}

			if (segundoOperando == 0) {
				printf("El factorial de 0 es: 1\n");
			} else {
				if (segundoOperando < 0) {
					printf(
							"El segundo operando es negativo por lo que no se puede calcular el factorial\n");
				} else {
					factorialSegundoOperando = CalcularFactorial(
							segundoOperando);
					printf("El factorial de %d es: %d\n", segundoOperando,
							factorialSegundoOperando);
				}
			}

			break;
		}
	} while (opcion != 5);

	return EXIT_SUCCESS;
}

