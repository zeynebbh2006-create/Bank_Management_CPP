#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;
struct Employee {
    int id = 0;
    string password = "";
    string name = "";
    string lastName = "";
    string address = "";
    double salary = 0.0;
    string hireDate = "";
    string branchCode = "";
};
#endif