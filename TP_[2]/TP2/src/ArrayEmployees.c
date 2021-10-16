/*
 * ArrayEmployees.c
 *
 *  Created on: 29 sep. 2021
 *      Author: Seba
 */

#include "ArrayEmployees.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * positions of the array
 * \param list Employee Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len)
{
	int respuesta;
	respuesta = -1;

	if (list != NULL && len > 0)
	{
		respuesta = 0;

		for (int i = 0; i < len; i++)
		{
			list[i].id = -1;
			list[i].isEmpty = 1;
		}

	}

	return respuesta;
}

/** \brief add values received from user in every member of employee struct
 * \param id int
 * \return empleado Employee with every member of employee struct validated
 */

Employee addAnEmployee(int id)
{

	Employee empleado;
	char ingresoSalario[51];
	char ingresoSector[51];

	getStringSoloLetras(empleado.name,
			"Ingrese el nombre de el/la empleado/a: ", 51);
	getStringSoloLetras(empleado.lastName,
			"Ingrese el apellido de el/la empleado/a: ", 51);
	getStringFlotante(ingresoSalario,
			"Ingrese el salario de el/la empleado/a: ", 51, &empleado.salary);
	getStringNumerica(ingresoSector, "Ingrese el sector de el/la empleado/a: ",
			51, &empleado.sector);
	empleado.isEmpty = 0;
	empleado.id = ++id;

	return empleado;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param Employee list
 * \param len int
 * \param id int
 * \return index int loaded with the list of employees and their members
 */

int addEmployees(Employee list[], int len, int id)
{
	int index;
	index = firstEmptyItem(list, len);
	if (index != -1)
	{
		list[index] = addAnEmployee(id);
	}
	return index;
}

/** \brief search for the first empty item in the array and returns the index position
 * \param Employee list
 * \param len int
 * \param id int
 * \return index int first empty item index position or (-1) if [Invalid length or NULL
 pointer received or employee not found]
 *
 */

int firstEmptyItem(Employee list[], int len)
{
	int i;
	int index;

	index = -1;

	for (i = 0; i < len; i++)
	{
		if (list[i].isEmpty == 1 && list[i].id == -1)
		{
			index = i;
			break;
		}

	}
	return index;

}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 pointer received or employee not found]
 *
 */

int findEmployeeById(Employee list[], int len, int id)
{
	int respuesta;

	respuesta = -1;

	if (id < 1)
	{
		return respuesta;
	}

	if (list != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (list[i].id == id && list[i].isEmpty == 0)
			{
				respuesta = i;
				break;
			}
		}

	}

	return respuesta;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param list Employee
 * \param len int
 * \return int auxIdEmpleadoSeleccionado (0) if Error - (1) if Ok
 *
 */

int removeEmployee(Employee list[], int len)
{
	int i;
	int idEmpleadoSeleccionado;
	int auxIdEmpleadoSeleccionado;
	char ingresoIdEmpleadoAEliminar[51];
	char confirmacion = 'n';
	int index;

	auxIdEmpleadoSeleccionado = 0;

	printEmployees(list, len);

	getStringNumerica(ingresoIdEmpleadoAEliminar,
			"\nIngrese el ID de el/la empleado/a a eliminar: ", 51,
			&idEmpleadoSeleccionado);
	index = findEmployeeById(list, len, idEmpleadoSeleccionado);

	while (index == -1)
	{
		printf("\nId invalido. Reingrese");
		getStringNumerica(ingresoIdEmpleadoAEliminar,
				"\nIngrese el ID de el/la empleado/a a eliminar: ", 51,
				&idEmpleadoSeleccionado);

		index = findEmployeeById(list, len, idEmpleadoSeleccionado);

		printf("Usted selecciono el ID: %d. Esta seguro/a que desea borrarlo? (s/n)",
				idEmpleadoSeleccionado);
		fflush(stdin);
		scanf("%c", &confirmacion);

		if (confirmacion == 's')
		{
			for (i = 0; i < len; i++)
			{
				if (list[i].isEmpty == 0
						&& list[i].id == idEmpleadoSeleccionado)
				{
					list[i].isEmpty = 1;
					auxIdEmpleadoSeleccionado = 1;
					break;

				}

			}
		}

	}
	return auxIdEmpleadoSeleccionado;
}


/** \brief Modify an Employee by Id (put isEmpty Flag in 1)
 * \param list Employee
 * \param len int
 */

void modifyEmployee(Employee list[], int len)
{
	char ingresoIdEmpleadoAModificar[51];
	int idEmpleadoSeleccionado;
	char nombreACambiar[51];
	char apellidoACambiar[51];
	char salarioIngresado[51];
	float salarioACambiar;
	char sectorIngresado[51];
	int sectorACambiar;
	char respuesta = 's';
	char confirmar = 'n';
	int index;

	do
	{

		printEmployees(list, len);
		getStringNumerica(ingresoIdEmpleadoAModificar, "Ingrese el ID de el/la empleado/a a modificar: ", 51, &idEmpleadoSeleccionado);

		index = findEmployeeById(list, len, idEmpleadoSeleccionado);

		while (index == -1)
		{
			printf("Id invalido. Reingrese\n");
			getStringNumerica(ingresoIdEmpleadoAModificar, "Ingrese el ID de el/la empleado/a a modificar: ", 51, &idEmpleadoSeleccionado);

			index = findEmployeeById(list, len, idEmpleadoSeleccionado);
		}

		getStringSoloLetras(nombreACambiar, "Ingrese el nombre de el/la emplado/a (oprima enter si no desea cambiar el nombre): ", 51);
		if (nombreACambiar[0] == '\0')
		{
			strcpy(nombreACambiar, list[index].name);
		}

		getStringSoloLetras(apellidoACambiar, "Ingrese el apellido de el/la emplado/a (oprima enter si no desea cambiar el apellido): ", 51);
		if (apellidoACambiar[0] == '\0')
		{
			strcpy(apellidoACambiar, list[index].lastName);
		}

		getStringFlotante(salarioIngresado, "Ingrese el salario de el/la emplado/a (oprima enter si no desea cambiar el salario): ", 51, &salarioACambiar);
		if (salarioIngresado[0] == '\0')
		{
			salarioACambiar = list[index].salary;
		}


		getStringNumerica(sectorIngresado, "Ingrese el sector de el/la emplado/a (oprima enter si no desea cambiar el sector): ", 51, &sectorACambiar);
		if (sectorIngresado[0] == '\0')
		{
			sectorACambiar = list[index].sector;
		}


		printf("\nDatos antiguos del empleado: ");

		print(list[index]);

		printf("\nDatos modificados del empleado: ");

		printf("Nombre: %s - Apellido: %s - Salario: %2.f - Sector: %d\n",
				nombreACambiar, apellidoACambiar, salarioACambiar,
				sectorACambiar);

		printf("Desea confirmar los cambios? (s/n)");
		fflush(stdin);
		scanf("%c", &confirmar);

		if (confirmar == 's')
		{
			strcpy(list[index].name, nombreACambiar);
			strcpy(list[index].lastName, apellidoACambiar);
			list[index].salary = salarioACambiar;
			list[index].sector = sectorACambiar;

			printf("\nEmpleado modificado exitosamente\n");
		}

		printf("Desea modificar otro/a empleado/a? (s/n)");
		fflush(stdin);
		scanf("%c", &respuesta);
	} while (respuesta == 's');

}

/**
 *\brief Calcula el total de salarios, el promedio
 * y la cantidad de empleados que superan el salario promedio
 * \param list Employee
 * \param len int
 * \return retorno int -1 si hay errores y 1 si no los hay
 */
int MostrarDatosSalario(Employee list[], int len)
{
	int i;
	float acumuladorSalarios;
	float promedioSalarios;
	int contadorEmpleadosSuperanPromedio;
	int retorno;

	retorno = -1;
	acumuladorSalarios = 0;
	promedioSalarios = 0;
	contadorEmpleadosSuperanPromedio = 0;

	if (list == NULL && len <= 0)
	{
		return retorno;
	}
	for (i = 0; i < len; i++)
	{
		if (list[i].isEmpty == 0)
		{
			acumuladorSalarios += list[i].salary;
		}
	}

	promedioSalarios = acumuladorSalarios / (float) len;

	for (i = 0; i < len; i++)
	{
		if (list[i].isEmpty == 0 && list[i].salary > promedioSalarios)
		{
			contadorEmpleadosSuperanPromedio++;
		}
	}

	printf("El total de salarios es: %.2f", acumuladorSalarios);
	printf("\nEl promedio de salarios es: %.2f", promedioSalarios);
	printf(
			"\nLa cantidad de empleados que superan el promedio de salarios es: %d",
			contadorEmpleadosSuperanPromedio);

	retorno = 1;

	return retorno;
}

/**
 * \brief Determina si se debe ordenar por apellido o no
 * teniendo en cuenta el orden ascendente o descendente
 * \param lastName1 char
 * \param lastName2 char
 * \param order int
 * \return retorno int 1 cuando tiene que ordenar de manera
 * ascendente o descendente y 0 si no tiene que hacerlo
 */
int tieneQueOrdenarPorApellido(char lastName1[], char lastName2[], int order)
{
	if (order == 1)
	{
		if (strcmp(lastName1, lastName2) > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	if (order == 0)
	{
		if (strcmp(lastName1, lastName2) < 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	return 0;
}

/**
 * \brief Determina si se debe ordenar por sector o no
 * teniendo en cuenta el orden ascendente o descendente
 * \param sector1 int
 * \param sector2 int
 * \param order int
 * \return retorno int 1 cuando tiene que ordenar de manera
 * ascendente o descendente y 0 si no tiene que hacerlo
 */
int tieneQueOrdenarPorSector(int sector1, int sector2, int order)
{
	if (order == 1)
	{
		if (sector1 > sector2)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	if (order == 0)
	{
		if (sector1 < sector2)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	return 0;
}

/**
 * \brief Sort the elements in the array of employees, the argument order
 * indicate UP or DOWN order
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return respuesta int (-1) if Error [Invalid length, NULL pointer, order different from 1 or 0] - (1) if Ok
 *
 */

int sortEmployees(Employee list[], int len, int order)
{

	Employee auxiliarApellidos;
	Employee auxiliarSector;

	int i;
	int j;
	int respuesta;
	respuesta = -1;

	if (order != 0 && order != 1)
	{
		return respuesta;
	}

	if (list != NULL && len > 0)
	{
		respuesta = 0;

		for (i = 0; i < len - 1; i++)
		{
			for (j = i + 1; j < len; j++)
			{
				if (tieneQueOrdenarPorApellido(list[i].lastName,
						list[j].lastName, order))
				{
					auxiliarApellidos = list[i];
					list[i] = list[j];
					list[j] = auxiliarApellidos;

				}
				else
				{
					if (strcmp(list[i].lastName, list[j].lastName) == 0
							&& tieneQueOrdenarPorSector(list[i].sector,
									list[j].sector, order))
					{
						auxiliarSector = list[i];
						list[i] = list[j];
						list[j] = auxiliarSector;
					}
				}
			}
		}

	}
	respuesta = 1;
	return respuesta;
}

/**
 * \brief print the content of employees' members
 * \param list Employee
 */

void print(Employee element)
{
	if (element.isEmpty == 0)
	{
		printf(
				"ID: %d - Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d\n",
				element.id, element.name, element.lastName, element.salary,
				element.sector);
	}
}

/**
 *  \brief print the content of employees' array
 * \param list Employee
 * \param len int
 * \return respuesta int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int printEmployees(Employee list[], int len)
{
	int i;
	int respuesta;
	respuesta = -1;

	if (list != NULL && len > 0)
	{
		respuesta = 0;
		for (i = 0; i < len; i++)
		{
			print(list[i]);
		}

	}

	return respuesta;
}
