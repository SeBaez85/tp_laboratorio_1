#include <stdio.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
	Employee *empleado;

	empleado = (Employee*) malloc(sizeof(Employee));

	employee_setId(empleado, 0);
	employee_setNombre(empleado, NULL);
	employee_setHorasTrabajadas(empleado, 0);
	employee_setSueldo(empleado, 0);

	return empleado;
}

Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr)
{
	Employee *empleado;

	empleado = employee_new();

	empleado->id = atoi(idStr);
	strcpy(empleado->nombre, nombreStr);
	empleado->horasTrabajadas = atoi(horasTrabajadasStr);
	empleado->sueldo = atoi(sueldoStr);

	return empleado;

}

int employee_setId(Employee *this, int id)
{
	int retorno;

	retorno = 0;

	if (this != NULL)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}
int employee_getId(Employee *this, int *id)
{
	int retorno;

	retorno = 0;
	if (this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int employee_setNombre(Employee *this, char *nombre)
{
	int retorno;

	retorno = 0;

	if (this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);

		retorno = 1;
	}

	return retorno;
}

int employee_getNombre(Employee *this, char *nombre)
{
	int retorno;
	if (this != NULL && nombre != NULL)
		{
			strcpy(nombre, this->nombre);

			retorno = 1;
		}
	retorno = 0;
	return retorno;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas)
{
	int retorno;

	retorno = 0;

	if (this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas)
{
	int retorno;

	retorno = 0;
	if (this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_setSueldo(Employee *this, int sueldo)
{
	int retorno;

	retorno = 0;

	if (this != NULL)
	{
		this->sueldo = sueldo;
		retorno = 1;
	}

	return retorno;
}

int employee_getSueldo(Employee *this, int *sueldo)
{
	int retorno;

	retorno = 0;
	if (this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 1;
	}
	return retorno;
}

int employee_CompareByName(void *e1, void *e2)
{
	int retorno;
	retorno = 0;
	Employee *unEmpleado;
	Employee *otroEmpleado;

	unEmpleado = (Employee*) e1; //unboxing, lo desencapsulo y lo convierto en Empleado (casteo)
	otroEmpleado = (Employee*) e2;

	retorno = strcmp(unEmpleado->nombre, otroEmpleado->nombre);
	return retorno;
}

int employee_CompareById(void *e1, void *e2)
{
	int retorno;
	retorno = 0;
	Employee *unEmpleado;
	Employee *otroEmpleado;

	unEmpleado = (Employee*) e1;
	otroEmpleado = (Employee*) e2;

	if (unEmpleado->id > otroEmpleado->id)
	{
		retorno = 1;
	}
	else
	{
		if (unEmpleado->id < otroEmpleado->id)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int employee_CompareByHorasTrabajadas(void *e1, void *e2)
{
	int retorno;
	retorno = 0;
	Employee *unEmpleado;
	Employee *otroEmpleado;

	unEmpleado = (Employee*) e1;
	otroEmpleado = (Employee*) e2;

	if (unEmpleado->horasTrabajadas > otroEmpleado->horasTrabajadas)
	{
		retorno = 1;
	}
	else
	{
		if (unEmpleado->horasTrabajadas < otroEmpleado->horasTrabajadas)
		{
			retorno = -1;
		}
	}
	return retorno;
}


int employee_CompareBySueldo(void *e1, void *e2)
{
	int retorno;
	retorno = 0;
	Employee *unEmpleado;
	Employee *otroEmpleado;

	unEmpleado = (Employee*) e1;
	otroEmpleado = (Employee*) e2;

	if (unEmpleado->sueldo > otroEmpleado->sueldo)
	{
		retorno = 1;
	}
	else
	{
		if (unEmpleado->sueldo < otroEmpleado->sueldo)
		{
			retorno = -1;
		}
	}
	return retorno;
}


