#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee)
{
	Employee *pAux;
	char id[50];
	char nombre[50];
	char horasTrabajadas[50];
	char sueldo[50];
	int cantVariables;
	int i;
	int retorno;
	i = 0;
	retorno = -1;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		cantVariables = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre,
				horasTrabajadas, sueldo);

		while (!feof(pFile))
		{
			cantVariables = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,
					nombre, horasTrabajadas, sueldo);
			if (cantVariables == 4)
			{
				pAux = employee_newParametros(id, nombre, horasTrabajadas,
						sueldo);
				if (ll_add(pArrayListEmployee, pAux) == -1)
				{
					//employee_delete(pAux);//o ll_remove?
				}
				else
				{
					i++;
					retorno = i;
				}

			}
			else
				break;
		}

	}

	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee)
{
	Employee *pAux;
	int retorno;
	retorno = -1;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		while (!feof(pFile))
		{
			pAux = employee_new();
			fread(pAux, sizeof(Employee), 1, pFile);
			if(feof(pFile))
			{
				break;
			}
			ll_add(pArrayListEmployee, pAux);
			retorno = 1;
		}
	}
	return retorno;
}
