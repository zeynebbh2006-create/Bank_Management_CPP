#include <iostream>
#include "EmployeeInterface.h"
#include "CustomerInterface.h"
#include "Data.h"
using namespace std;

void GlobalMenu() {
    char choice;
    while (true) {
        cout << "\n=====================================\n";
        cout << "             GLOBAL MENU             \n";
        cout << "=====================================\n";
        cout << "1. Employee Management\n";
        cout << "2. Customer Management\n";
        cout << "0. Exit\n";
        cout << "-------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case '1':
            cout << "\n>>> Opening Employee Management...\n";
            EmployeeMenu();
            break;

        case '2':
            cout << "\n>>> Opening Customer Management...\n";
            CustomerMenu();
            break;

        case '0':
            cout << "\nExiting program... Goodbye!\n";
            return;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }
    }
}

int main() {
    InportData();
    GlobalMenu();
    return 0;
}
