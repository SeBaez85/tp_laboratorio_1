#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "InputsYAux.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee)
{
	FILE *pArchivo;
	int retorno;
	retorno = 0;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pArchivo = fopen(path, "r");
		parser_EmployeeFromText(pArchivo, pArrayListEmployee);
		retorno = 1;
	}
	fclose(pArchivo);
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee)
{
	FILE *pArchivo;
	int retorno;
	retorno = 0;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pArchivo = fopen(path, "rb");
		parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
		retorno = 1;
	}
	fclose(pArchivo);
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee)
{
	int retorno;
	retorno = -1;

	char ingresoNombre[51];
	char ingresoHorasTrabajadas[51];
	char ingresoSueldo[51];
	Employee *empleado;
	char *path;
	path = "ultimoIdEmployee.csv";
	char id[50];
	int idWrite = 0;
	FILE *rArchivo;
	FILE *wArchivo;

	getStringSoloLetras(ingresoNombre, "Ingrese el nombre del/la empleado/a: ",
			51);
	getStringSoloNumeros(ingresoHorasTrabajadas,
			"Ingrese las horas trabajadas del/la empleado/a: ", 51);
	getStringSoloNumeros(ingresoSueldo, "Ingrese el sueldo del/la empleado/a: ",
			51);

	if (path != NULL)
	{
		rArchivo = fopen(path, "r");
		printf("Abrii");
		fscanf(rArchivo, "%[^\n]\n", id);
		printf("Hice el scanf");
		fclose(rArchivo);

		printf("%s", id);

		empleado = employee_newParametros(id, ingresoNombre,
				ingresoHorasTrabajadas, ingresoSueldo);
		ll_add(pArrayListEmployee, empleado);

		idWrite = atoi(id);

		printf("%d", idWrite);

		idWrite++;

		wArchivo = fopen(path, "w");

		fprintf(wArchivo, "%d", idWrite);
		fclose(wArchivo);
	}

	retorno = 1;

	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee)
{
	int retorno;
	char ingresoId[50];
	int idValidado;
	int len;
	len = ll_len(pArrayListEmployee);
	Employee *pAux;
	pAux = NULL;
	int auxId;
	char auxNombre;
	char nombreACambiar[51];
	char horasACambiar[51];
	int horasValidadas;
	char sueldoACambiar[51];
	int sueldoValidado;
	char confirmar = 'n';

	controller_ListEmployee(pArrayListEmployee);

	getStringNumerica(ingresoId, "Ingrese el id del/la empleado/a: \n", 50,
			&idValidado);

	if (pArrayListEmployee != NULL)
	{

		for (int i = 0; i < len; i++)
		{
			pAux = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pAux, &auxId);

			if (idValidado == auxId)
			{
				break;
			}

			pAux = NULL;
		}
	}

	while (pAux == NULL)
	{
		getStringNumerica(ingresoId,
				"Error: Empleado no encontrado. Reingrese el id del/la empleado/a: \n",
				50, &idValidado);

		if (pArrayListEmployee != NULL)
		{
			for (int i = 0; i < len; i++)
			{
				pAux = (Employee*) ll_get(pArrayListEmployee, i);
				employee_getId(pAux, &auxId);

				if (idValidado == auxId)
				{
					break;
				}

				pAux = NULL;
			}
		}
	}

	getStringSoloLetras(nombreACambiar,
			"Ingrese el nombre de el/la emplado/a (oprima enter si no desea cambiar el nombre): ",
			51);
	if (nombreACambiar[0] == '\0')
	{
		employee_getNombre(pAux, &auxNombre);
		strcpy(nombreACambiar, &auxNombre);
	}

	getStringNumerica(horasACambiar,
			"Ingrese las horas trabajadas por el/la emplado/a (oprima enter si no desea cambiar las horas): ",
			51, &horasValidadas);
	if (horasACambiar[0] == '\0')
	{
		employee_getHorasTrabajadas(pAux, &horasValidadas);
	}

	getStringNumerica(sueldoACambiar,
			"Ingrese el sueldo de el/la emplado/a (oprima enter si no desea cambiar el sueldo): ",
			51, &sueldoValidado);
	if (sueldoACambiar[0] == '\0')
	{
		employee_getSueldo(pAux, &sueldoValidado);
	}

	printf("\nDatos modificados del empleado: ");

	printf("Nombre: %s - Horas Trabajadas: %d - Sueldo: %d\n", nombreACambiar,
			horasValidadas, sueldoValidado);

	printf("Desea confirmar los cambios? (s/n)");
	fflush(stdin);
	scanf("%c", &confirmar);

	if (confirmar == 's')
	{
		employee_setNombre(pAux, nombreACambiar);
		employee_setHorasTrabajadas(pAux, horasValidadas);
		employee_setSueldo(pAux, sueldoValidado);
		printf("\nEmpleado modificado exitosamente\n");
	}

	retorno = 1;
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee)
{
	int retorno;
	char ingresoId[50];
	int idValidado;
	int len;
	len = ll_len(pArrayListEmployee);
	Employee *pAux;
	pAux = NULL;
	int auxId;
	char nombreEmpleado[51];
	int horasEmpleado;
	int sueldoEmpleado;
	int indexEmployee;
	char confirmar = 'n';

	controller_ListEmployee(pArrayListEmployee);

	getStringNumerica(ingresoId, "Ingrese el id del/la empleado/a: \n", 50,
			&idValidado);

	if (pArrayListEmployee != NULL)
	{

		for (int i = 0; i < len; i++)
		{
			pAux = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pAux, &auxId);

			if (idValidado == auxId)
			{
				indexEmployee = i;
				break;
			}

			pAux = NULL;
		}
	}

	while (pAux == NULL)
	{
		getStringNumerica(ingresoId,
				"Error: Empleado no encontrado. Reingrese el id del/la empleado/a: \n",
				50, &idValidado);

		if (pArrayListEmployee != NULL)
		{
			for (int i = 0; i < len; i++)
			{
				pAux = (Employee*) ll_get(pArrayListEmployee, i);
				employee_getId(pAux, &auxId);

				if (idValidado == auxId)
				{
					break;
				}

				pAux = NULL;
			}
		}
	}

	employee_getNombre(pAux, nombreEmpleado);
	employee_getHorasTrabajadas(pAux, &horasEmpleado);
	employee_getSueldo(pAux, &sueldoEmpleado);

	printf("\nDatos del empleado: ");

	printf("Nombre: %s - Horas Trabajadas: %d - Sueldo: %d\n", nombreEmpleado,
			horasEmpleado, sueldoEmpleado);

	printf("Desea borrar el empleado? (s/n)");
	fflush(stdin);
	scanf("%c", &confirmar);

	if (confirmar == 's')
	{
		ll_remove(pArrayListEmployee, indexEmployee);
		printf("\nEmpleado eliminado exitosamente\n");
	}

	retorno = 1;
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee)
{
	Employee *pAux;
	int len;
	int auxId;
	char auxNombre[50];
	int auxHorasTrabajadas;
	int auxSueldo;
	int retorno;
	len = ll_len(pArrayListEmployee);
	retorno = -1;

	if (pArrayListEmployee != NULL)
	{

		for (int i = 0; i < len; i++)
		{
			pAux = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pAux, &auxId);
			employee_getNombre(pAux, auxNombre);
			employee_getHorasTrabajadas(pAux, &auxHorasTrabajadas);
			employee_getSueldo(pAux, &auxSueldo);

			printf("\nId: %d - Nombre: %s - Horas %d - Sueldo: %d\n", auxId,
					auxNombre, auxHorasTrabajadas, auxSueldo);
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee)
{
	int opcionSub;
	char ingresoOpcionSub[51];
	int retorno;

	do
	{
		printf("1. Ordenar por id ascendente\n");
		printf("2. Ordenar por id descendente.\n");
		printf("3. Ordenar por nombre ascendente\n");
		printf("4. Ordenar por nombre descendente.\n");
		printf("5. Ordenar por horas trabajadas ascendente\n");
		printf("6. Ordenar por horas trabajadas descendente.\n");
		printf("7. Ordenar por sueldo ascendente\n");
		printf("8. Ordenar por sueldo descendente.\n");
		printf("9. Salir.\n");

		getStringNumerica(ingresoOpcionSub, "Elija una opcion: \n", 51,
				&opcionSub);

		switch (opcionSub)
		{
		case 1:
			ll_sort(pArrayListEmployee, employee_CompareById, 1);
			controller_ListEmployee(pArrayListEmployee);
			break;

		case 2:
			ll_sort(pArrayListEmployee, employee_CompareById, -1);
			controller_ListEmployee(pArrayListEmployee);
			break;
		case 3:
			ll_sort(pArrayListEmployee, employee_CompareByName, 1);
			controller_ListEmployee(pArrayListEmployee);
			break;
		case 4:
			ll_sort(pArrayListEmployee, employee_CompareByName, -1);
			controller_ListEmployee(pArrayListEmployee);
			break;
		case 5:
			ll_sort(pArrayListEmployee, employee_CompareByHorasTrabajadas, 1);
			controller_ListEmployee(pArrayListEmployee);
			break;
		case 6:
			ll_sort(pArrayListEmployee, employee_CompareByHorasTrabajadas, -1);
			controller_ListEmployee(pArrayListEmployee);
			break;
		case 7:
			ll_sort(pArrayListEmployee, employee_CompareBySueldo, 1);
			controller_ListEmployee(pArrayListEmployee);
			break;
		case 8:
			ll_sort(pArrayListEmployee, employee_CompareBySueldo, -1);
			controller_ListEmployee(pArrayListEmployee);
			break;
		}
	} while (opcionSub < 9);

	retorno = 1;
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee)
{
	FILE *pArchivo;
	Employee *empleado;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int i;
	int len;
	int retorno;
	retorno = -1;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pArchivo = fopen(path, "w");
		len = ll_len(pArrayListEmployee);
		fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");
		for (i = 0; i < len; i++)
		{
			empleado = (Employee*) ll_get(pArrayListEmployee, i);
			if (empleado == NULL)
			{
				continue;
			}

			employee_getId(empleado, &id);
			employee_getNombre(empleado, nombre);
			employee_getHorasTrabajadas(empleado, &horasTrabajadas);
			employee_getSueldo(empleado, &sueldo);
			fprintf(pArchivo, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas,
					sueldo);
		}
		fclose(pArchivo);
	}

	retorno = 1;
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee)
{
	FILE *pArchivo;
	Employee *empleado;
	int i;
	int len;
	int retorno;
	retorno = -1;

	if (path != NULL && pArrayListEmployee != NULL)
	{

		pArchivo = fopen(path, "wb");
		len = ll_len(pArrayListEmployee);

		if (pArchivo != NULL)
		{
			for (i = 0; i < len; i++)
			{
				empleado = (Employee*) ll_get(pArrayListEmployee, i);
				if (empleado == NULL)
				{
					break;
				}
				fwrite(empleado, sizeof(Employee), 1, pArchivo);
			}
		}
		fclose(pArchivo);

	}

	retorno = 1;
	return retorno;

}

