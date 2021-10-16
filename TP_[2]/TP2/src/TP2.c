/* Sebastian Baez 1ero E
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "InputsYAux.h"

#define LEN 1000
#define UP 1
#define DOWN 0

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int opcionSub;
	int retornoFuncion;
	char ingresoOpcion[51];
	char ingresoOpcionSub[51];
	char respuesta;
	Employee listaEmpleados[LEN];
	int id;
	int flagOpcion1 = 0;
	id = 0;
	respuesta = 's';

	initEmployees(listaEmpleados, LEN);

	do
	{

		printf("1. ALTA\n");
		printf("2. MODIFICAR\n");
		printf("3. BAJA\n");
		printf("4. INFORMAR\n");

		getStringNumerica(ingresoOpcion, "Elija una opcion: \n", 51, &opcion);

		switch (opcion)
		{
		case 1:
			retornoFuncion = addEmployees(listaEmpleados, LEN, id);
			if (retornoFuncion != -1)
			{
				id = listaEmpleados[retornoFuncion].id;
				puts("El/la empleado/a se cargo exitosamente\n");
			}
			else
			{
				puts("El/la empleado/a no pudo cargarse\n");
			}
			flagOpcion1 = 1;
			break;
		case 2:
			if (flagOpcion1 == 0)
			{
				printf("Debe dar de alta algun/a empleado/a primero\n");
				break;
			}

			modifyEmployee(listaEmpleados, LEN);

			break;
		case 3:

			if (flagOpcion1 == 0)
			{
				printf("Debe dar de alta algun/a empleado/a primero\n");
				break;
			}

			do
			{
				retornoFuncion = removeEmployee(listaEmpleados, LEN);

				if (retornoFuncion == 1)
				{
					printf("El/la empleado/a se borro exitosamente.\n");
				}
				else
				{
					printf("No se pudo borrar el/la empleado/a.\n");
				}
				printf("Desea eliminar otro/a empleado/a? (s/n)");
				fflush(stdin);
				scanf("%c", &respuesta);
			} while (respuesta == 's');

			break;

		case 4:

			if (flagOpcion1 == 0)
			{
				printf("Debe dar de alta algun/a empleado/a primero\n");
				break;
			}

			do
			{
				printf(
						"1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n");
				printf(
						"2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");

				printf("3. Salir.\n");

				getStringNumerica(ingresoOpcionSub, "Elija una opcion: \n", 51,
						&opcionSub);

				switch (opcionSub)
				{
				case 1:
					retornoFuncion = sortEmployees(listaEmpleados, LEN, UP);
					if (retornoFuncion == 1)
					{
						printEmployees(listaEmpleados, LEN);
						printf("La lista se ordeno exitosamente.\n");
					}
					else
					{
						printf("No se pudo ordenar la lista.\n");
					}

					break;

				case 2:
					retornoFuncion = MostrarDatosSalario(listaEmpleados, LEN);

					if (retornoFuncion == 1)
					{

						printf("\nDatos calculados exitosamente\n");
					}
					else
					{
						printf("\nNo se pudo calcular los datos.\n");
					}

					break;
				}
			} while (opcionSub != 3);

			break;

		}

	} while (opcion != 6);

	return EXIT_SUCCESS;
}
