#include <iostream>
#include "EmployeeManagerMeth.h"
#include "GlobalVariables.h"

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        cout << "Error: employee list is full.\n";
        return;
    }
    Employee e;
    cout << "\n=== ADD NEW EMPLOYEE ===" << endl;
    do {
        cout << "Enter Employee ID: ";
        cin >> e.id;

        if (!isEmployeeIdUnique(e.id)) {
            cout << "Error: ID already exists. Please enter a unique ID." << endl;
        }
    } while (!isEmployeeIdUnique(e.id));
    cin.ignore();
    cout << "Enter First Name: ";
    getline(cin, e.name);
    cout << "Enter Last Name: ";
    getline(cin, e.lastName);
    cout << "Enter Address: ";
    getline(cin, e.address);
    cout << "Enter Salary (TND): ";
    cin >> e.salary;
    cin.ignore();
    cout << "Enter Hire Date (DD/MM/YYYY): ";
    getline(cin, e.hireDate);
    cout << "Enter Branch Code (1 for Head Office): ";
    getline(cin, e.branchCode);
    employees[employeeCount] = e;
    employeeCount++;
    cout << "\n Employee added successfully!" << endl;
}

void deleteEmployee() {
    cout << "Enter Employee ID to delete: ";
    int id;
    cin >> id;
    int index = findEmployeeIndex(id);
    if (index == -1) {
        cout << "Error: Employee not found!" << endl;
        return;
    }
    cout << "\n Employee to be deleted:" << endl;
    displayEmployee(employees[index]);
    char confirm;
    cout << "Are you sure you want to delete this employee? (y/n): ";
    cin >> confirm;
    if (confirm != 'y' && confirm != 'Y') {
        cout << "Deletion cancelled." << endl;
        return;
    }
    for (int i = index; i < employeeCount - 1; i++) {
        employees[i] = employees[i + 1];
    }
    employeeCount--;
    cout << "\n Employee deleted successfully!" << endl;
}

void modifyEmployee() {
    int id;
    cout << "\n=== MODIFY EMPLOYEE ===" << endl;
    cout << "Enter Employee ID to modify: ";
    cin >> id;
    int index = findEmployeeIndex(id);
    if (index == -1) {
        cout << "Error: Employee not found!" << endl;
        return;
    }
    cout << "\n Current employee details:" << endl;
    displayEmployee(employees[index]);
    cin.ignore();
    cout << "\n--- Enter new details (press Enter to keep current) ---" << endl;
    string input;
    cout << "First Name [" << employees[index].name << "]: ";
    getline(cin, input);
    if (!input.empty()) employees[index].name = input; //itha l input mouch feregh ( el employee dakhal haja )bech ydabal fel employee
    cout << "Last Name [" << employees[index].lastName << "]: ";
    getline(cin, input);
    if (!input.empty()) employees[index].lastName = input;
    cout << "Address [" << employees[index].address << "]: ";
    getline(cin, input);
    if (!input.empty()) employees[index].address = input;
    cout << "Salary [" << employees[index].salary << "]: ";
    getline(cin, input);
    if (!input.empty()) employees[index].salary = stod(input);
    cout << "Hire Date [" << employees[index].hireDate << "]: ";
    getline(cin, input);
    if (!input.empty()) employees[index].hireDate = input;
    cout << "Branch Code [" << employees[index].branchCode << "]: ";
    getline(cin, input);
    if (!input.empty()) employees[index].branchCode = input;
    cout << "\n Employee modified successfully!" << endl;
}

void displayEmployeesByLastName() {
    if (employeeCount == 0) {
        cout << "No employees to display." << endl;
        return;
    }
    cout << "\n=== EMPLOYEES (ALPHABETICAL ORDER BY LAST NAME) ===" << endl;
    Employee* tempEmployees = new Employee[employeeCount];
    for (int i = 0; i < employeeCount; i++) {
        tempEmployees[i] = employees[i];
    }
    for (int i = 0; i < employeeCount - 1; i++) {
        for (int j = 0; j < employeeCount - i - 1; j++) {
            if (tempEmployees[j].lastName > tempEmployees[j + 1].lastName) {
                Employee temp = tempEmployees[j];
                tempEmployees[j] = tempEmployees[j + 1];
                tempEmployees[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < employeeCount; i++)
        displayEmployee(tempEmployees[i]);
    delete[] tempEmployees;
}

void displayEmployeesByBranch() {
    if (employeeCount == 0) {
        cout << "No employees to display." << endl;
        return;
    }
    cout << "\n=== EMPLOYEES GROUPED BY BRANCH ===" << endl;
    int branchCount = 0;
    for (int i = 0; i < employeeCount; i++) {
        bool found = false;
        for (int j = 0; j < branchCount; j++) {
            if (branches[j] == employees[i].branchCode) {
                found = true;
                break;
            }
        }
        if (!found) {
            branches[branchCount++] = employees[i].branchCode;
        }
    }
    for (int i = 0; i < branchCount; i++) {
        cout << "\n***** BRANCH: ";
        if (branches[i] == "1")
            cout << "HEAD OFFICE";
        else
            cout << branches[i];
        cout << " *****" << endl;
        for (int j = 0; j < employeeCount; j++) {
            if (employees[j].branchCode == branches[i]) {
                displayEmployee(employees[j]);
            }
        }
    }
}
void displayEarliestAndLatestHired() {
    if (employeeCount == 0) {
        cout << "No employees to display." << endl;
        return;
    }
    int earliestIndex = 0;
    int latestIndex = 0;
    for (int i = 1; i < employeeCount; i++) {
        if (employees[i].hireDate < employees[earliestIndex].hireDate) {
            earliestIndex = i;
        }
        if (employees[i].hireDate > employees[latestIndex].hireDate) {
            latestIndex = i;
        }
    }
    cout << "\n=== EARLIEST RECRUITED EMPLOYEE ===" << endl;
    displayEmployee(employees[earliestIndex]);
    cout << "\n=== MOST RECENTLY RECRUITED EMPLOYEE ===" << endl;
    displayEmployee(employees[latestIndex]);
}

void displayEmployee(const Employee& emp) {
    cout << "========================================" << endl;
    cout << "ID: " << emp.id << endl;
    cout << "Name: " << emp.name << " " << emp.lastName << endl;
    cout << "Address: " << emp.address << endl;
    cout << "Salary: " << emp.salary << " TND" << endl;
    cout << "Hire Date: " << emp.hireDate << endl;
    cout << "Branch: ";
    if (emp.branchCode == "1")
        cout << "Head Office";
    else
        cout << "Branch " + emp.branchCode;
    cout << endl;
    cout << "========================================" << endl;
}
bool isEmployeeIdUnique(int id) {
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            return false;
        }
    }
    return true;
}
int findEmployeeIndex(int id) {
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

