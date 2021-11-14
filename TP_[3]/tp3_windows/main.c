#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "InputsYAux.h"

/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main()
{
	setbuf(stdout, NULL);

	char ingresoOpcion[50];
	int opcion;
	int flagOpcion1 = 0;

	LinkedList *listaEmpleados;
	listaEmpleados = ll_newLinkedList();

	do
	{

		printf(
				"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
		printf(
				"2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
		printf("3. Alta de empleado\n");
		printf("4. Modificar datos de empleado\n");
		printf("5. Baja de empleado\n");
		printf("6. Listar empleados\n");
		printf("7. Ordenar empleados\n");
		printf(
				"8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
		printf(
				"9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
		printf("10. Salir\n");

		getStringNumerica(ingresoOpcion, "Elija una opcion: \n", 50, &opcion);

		switch (opcion)
		{
		case 1:
			if (controller_loadFromText("data.csv", listaEmpleados) == 0)
			{
				printf("No se pudo cargar los empleados\n");
			}
			else
			{
				printf("Empleados cargados correctamente\n");
				flagOpcion1 = 1;
			}

			break;
		case 2:
			if (controller_loadFromBinary("data.bin", listaEmpleados) == 0)
			{
				printf("No se pudo cargar los empleados\n");
			}
			else
			{
				printf("Empleados cargados correctamente\n");
				flagOpcion1 = 1;
			}
			break;
		case 3:
			if (flagOpcion1 == 0)
			{
				printf(
						"Debe cargar los datos de algun/a empleado/a desde algun archivo primero\n");
				break;
			}
			if (controller_addEmployee(listaEmpleados) == -1
					&& (flagOpcion1 == 1))
			{
				printf("No se pudo cargar los empleados\n");
			}
			else
			{
				printf("Empleados cargados correctamente\n");
			}
			break;

		case 4:
			if (flagOpcion1 == 0)
			{
				printf(
						"Debe cargar los datos de algun/a empleado/a desde algun archivo primero\n");
				break;
			}
			if (controller_editEmployee(listaEmpleados) == -1
					&& (flagOpcion1 == 1))
			{
				printf("No se pudo cargar los empleados\n");
			}
			else
			{
				printf("Empleados cargados correctamente\n");
			}
			break;

		case 5:
			if (flagOpcion1 == 0)
			{
				printf(
						"Debe cargar los datos de algun/a empleado/a desde algun archivo primero\n");
				break;
			}
			if (controller_removeEmployee(listaEmpleados) == -1
					&& (flagOpcion1 == 1))
			{
				printf("No se pudo cargar los empleados\n");
			}
			else
			{
				printf("Empleados cargados correctamente\n");
			}
			break;

		case 6:
			if (flagOpcion1 == 0)
			{
				printf(
						"Debe cargar los datos de algun/a empleado/a desde algun archivo primero\n");
				break;
			}

			if (controller_ListEmployee(listaEmpleados) == -1)
			{
				printf("No se pudo mostrar la lista\n");
			}
			else
			{
				printf("Lista mostrada correctamente\n");
			}

			break;

		case 7:
			if (flagOpcion1 == 0)
			{
				printf(
						"Debe cargar los datos de algun/a empleado/a desde algun archivo primero\n");
				break;
			}
			if (controller_sortEmployee(listaEmpleados) == -1)
			{
				printf("No se pudo guardar la lista\n");
			}
			else
			{
				printf("Lista guardada correctamente\n");
			}

			break;

		case 8:
			if (flagOpcion1 == 0)
			{
				printf(
						"Debe cargar los datos de algun/a empleado/a desde algun archivo primero\n");
				break;
			}
			if (controller_saveAsText("data.csv", listaEmpleados) == -1)
			{
				printf("No se pudo guardar la lista\n");
			}
			else
			{
				printf("Lista guardada correctamente\n");
			}

			break;

		case 9:
			if (flagOpcion1 == 0)
			{
				printf(
						"Debe cargar los datos de algun/a empleado/a desde algun archivo primero\n");
				break;
			}

			if (controller_saveAsBinary("data.bin", listaEmpleados) == -1)
			{
				printf("No se pudo guardar la lista\n");
			}
			else
			{
				printf("Lista guardada correctamente\n");
			}

			break;

		}

	} while (opcion < 10);

	return EXIT_SUCCESS;
}

