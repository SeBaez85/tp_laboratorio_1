/*
 * parser.h
 *
 *  Created on: 11 nov. 2021
 *      Author: Seba
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "Employee.h"

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee);
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee);

#endif /* PARSER_H_ */
