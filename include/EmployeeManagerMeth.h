#ifndef EMPLOYEEMANAGERMETH_H
#define EMPLOYEEMANAGERMETH_H
#include "Employee.h"
#include <iostream>
#include <string>

void addEmployee();
void deleteEmployee();
void modifyEmployee();
void displayEmployeesByBranch();
void displayEarliestAndLatestHired();
void displayEmployee(const Employee& emp);
bool isEmployeeIdUnique(int id);
int findEmployeeIndex(int id);
void displayEmployeesByLastName();
#endif

