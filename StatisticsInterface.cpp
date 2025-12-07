#include "StatisticsInterface.h"
#include "StatisticsMeth.h"
#include "GlobalVariables.h"
#include "AccountManagedByEmployeeMeth.h"
void statisticsMenu()
{
    char choice;
    do {
        cout << "\n\n===== STATISTICS MENU =====\n";
        cout << "1. Total number of loans\n";
        cout << "2. Number of loans by type\n";
        cout << "3. Number of loans by status\n";
        cout << "4. Active loans within date range\n";
        cout << "5. Customer with highest number of loans\n";
        cout << "6. Customer with highest balance\n";
        cout << "7. Customer with lowest balance\n";
        cout << "8. Total number of employees\n";
        cout << "9. Employees per branch\n";
        cout << "0. Back to Employee Menu\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "Total Loans: "
                << TotalLoansNbr(accounts, accountCount)
                << endl;
            break;

        case '2':
            LoansByTypeNbr(accounts, accountCount);
            break;

        case '3':
            getLoansByStatus(accounts, accountCount);
            break;

        case '4': {
            string start, end;
            cout << "Enter start date (DD/MM/YYYY): ";
            cin >> start;
            cout << "Enter end date (DD/MM/YYYY): ";
            cin >> end;
            cout << "Active loans: "
                << ActiveLoansInDateRange(start, end, accounts, accountCount)
                << endl;
            break;
        }

        case '5': {
            Account c = HighestLoans(accountCount, accounts);
            cout << "Customer with most loans: " << c.holderName << endl;
            break;
        }

        case '6': {
            Account c = HighestBalance(accounts, accountCount);
            cout << "Richest customer: " << c.holderName
                << " | Balance: " << c.balance << endl;
            break;
        }

        case '7': {
            Account c = LowestBalance(accountCount, accounts);
            cout << "Customer with lowest balance: " << c.holderName
                << " | Balance: " << c.balance << endl;
            break;
        }

        case '8':
            cout << "Total Employees: " << TotalEmployees(employeeCount) << endl;
            break;

        case '9': {
            string branch;
            cout << "Enter branch code: ";
            cin >> branch;
            cout << "Employees in branch " << branch << ": "
                << getEmployeesPerBranch(employees, employeeCount, branch)
                << endl;
            break;
        }

        case '0':
            cout << "Returning...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != '0');
}