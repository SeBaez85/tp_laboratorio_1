/*
 * ArrayEmployees.h
 *
 *  Created on: 29 sep. 2021
 *      Author: Seba
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "InputsYAux.h"

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

} Employee;

int initEmployees(Employee list[], int len);
Employee addAnEmployee(int id);
int addEmployees(Employee list[], int len, int id);
int firstEmptyItem(Employee list[], int len);
int findEmployeeById(Employee list[], int len, int id);
int removeEmployee(Employee list[], int len);
void modifyEmployee(Employee list[], int len);
int sortEmployees(Employee list[], int len, int order);
void print(Employee element);
int printEmployees(Employee list[], int len);
int MostrarDatosSalario(Employee list[], int len);
int tieneQueOrdenarPorApellido(char lastName1[], char lastName2[], int order);
int tieneQueOrdenarPorSector(int sector1, int sector2, int order);


#endif /* ARRAYEMPLOYEES_H_ */
