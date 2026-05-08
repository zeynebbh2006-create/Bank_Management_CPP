#include "Data.h"
#include "GlobalVariables.h"
#include "DoublyListLoans.h"

void InportData()
{
    employeeCount = 0;
    accountCount = 0;
    archivedCount = 0;
    branchCount = 0;

    QueueLoanRequests.front_Q = nullptr;
    QueueLoanRequests.tail_Q = nullptr;

    completed_loans.head_SLL = nullptr;
    completed_loans.size_SLL = 0;

    employees[0] = { 1, "emp001", "Alice", "Smith", "Tunis", 2200, "2021-01-10", "BR01" };
    employees[1] = { 2, "emp002", "Bob", "Johnson", "Sfax", 2500, "2020-03-15", "BR01" };
    employees[2] = { 3, "emp003", "Carla", "Ben", "Sousse", 2100, "2019-07-01", "BR02" };
    employees[3] = { 4, "emp004", "David", "Lee", "Ariana", 2700, "2018-11-20", "BR02" };
    employees[4] = { 5, "emp005", "Eve", "Martin", "Bizerte", 2300, "2022-02-05", "BR03" };
    employees[5] = { 6, "emp006", "Firas", "Zitoun", "Gabes", 2400, "2017-12-12", "BR03" };
    employees[6] = { 7, "emp007", "Ghada", "Ali", "Kairouan", 2600, "2016-04-30", "BR04" };
    employees[7] = { 8, "emp008", "Hichem", "Bennani", "Monastir", 2000, "2020-09-09", "BR04" };
    employees[8] = { 9, "emp009", "Iman", "Triki", "Tataouine", 2100, "2015-06-06", "BR05" };
    employees[9] = { 10, "admin", "Admin", "Root", "HeadOffice", 4000, "2010-01-01", "MAIN" };

    employeeCount = 10;

    branches[0] = "BR01";
    branches[1] = "BR02";
    branches[2] = "BR03";
    branches[3] = "BR04";
    branches[4] = "BR05";
    branches[5] = "MAIN";
    branchCount = 6;

    // ACCOUNT 1
    accounts[0].accountNumber = "ACC001";
    accounts[0].password = "cust001";
    accounts[0].accountType = "Savings";
    accounts[0].IBAN = "TN590001";
    accounts[0].branchCode = "BR01";
    accounts[0].holderName = "Amir Ben Salah";
    accounts[0].openingDate = "2023-01-10";
    accounts[0].status = "active";
    accounts[0].balance = 3200.50;
    accounts[0].PermenantTransaction.head_SLT = nullptr;
    accounts[0].PermenantTransaction.size_SLT = 0;
    accounts[0].dailyTransactions = new Stack;
    accounts[0].dailyTransactions->Top = -1;
    accounts[0].loans.head_DL = nullptr;
    accounts[0].loans.tail_DL = nullptr;
    accounts[0].loans.size_DL = 0;

    // ACCOUNT 2
    accounts[1].accountNumber = "ACC002";
    accounts[1].password = "cust002";
    accounts[1].accountType = "Checking";
    accounts[1].IBAN = "TN590002";
    accounts[1].branchCode = "BR01";
    accounts[1].holderName = "Yasmine Trabelsi";
    accounts[1].openingDate = "2022-12-01";
    accounts[1].status = "active";
    accounts[1].balance = 4100.75;
    accounts[1].PermenantTransaction.head_SLT = nullptr;
    accounts[1].PermenantTransaction.size_SLT = 0;
    accounts[1].dailyTransactions = new Stack;
    accounts[1].dailyTransactions->Top = -1;
    accounts[1].loans.head_DL = nullptr;
    accounts[1].loans.tail_DL = nullptr;
    accounts[1].loans.size_DL = 0;

    // ACCOUNT 3
    accounts[2].accountNumber = "ACC003";
    accounts[2].password = "cust003";
    accounts[2].accountType = "Savings";
    accounts[2].IBAN = "TN590003";
    accounts[2].branchCode = "BR02";
    accounts[2].holderName = "Mariem Jlassi";
    accounts[2].openingDate = "2021-11-20";
    accounts[2].status = "active";
    accounts[2].balance = 2800.00;
    accounts[2].PermenantTransaction.head_SLT = nullptr;
    accounts[2].PermenantTransaction.size_SLT = 0;
    accounts[2].dailyTransactions = new Stack;
    accounts[2].dailyTransactions->Top = -1;
    accounts[2].loans.head_DL = nullptr;
    accounts[2].loans.tail_DL = nullptr;
    accounts[2].loans.size_DL = 0;

    // ACCOUNT 4
    accounts[3].accountNumber = "ACC004";
    accounts[3].password = "cust004";
    accounts[3].accountType = "Checking";
    accounts[3].IBAN = "TN590004";
    accounts[3].branchCode = "BR02";
    accounts[3].holderName = "Omar Hachani";
    accounts[3].openingDate = "2023-02-15";
    accounts[3].status = "active";
    accounts[3].balance = 5000.30;
    accounts[3].PermenantTransaction.head_SLT = nullptr;
    accounts[3].PermenantTransaction.size_SLT = 0;
    accounts[3].dailyTransactions = new Stack;
    accounts[3].dailyTransactions->Top = -1;
    accounts[3].loans.head_DL = nullptr;
    accounts[3].loans.tail_DL = nullptr;
    accounts[3].loans.size_DL = 0;

    // ACCOUNT 5
    accounts[4].accountNumber = "ACC005";
    accounts[4].password = "cust005";
    accounts[4].accountType = "Savings";
    accounts[4].IBAN = "TN590005";
    accounts[4].branchCode = "BR03";
    accounts[4].holderName = "Nour Mhamdi";
    accounts[4].openingDate = "2020-06-18";
    accounts[4].status = "active";
    accounts[4].balance = 1500.00;
    accounts[4].PermenantTransaction.head_SLT = nullptr;
    accounts[4].PermenantTransaction.size_SLT = 0;
    accounts[4].dailyTransactions = new Stack;
    accounts[4].dailyTransactions->Top = -1;
    accounts[4].loans.head_DL = nullptr;
    accounts[4].loans.tail_DL = nullptr;
    accounts[4].loans.size_DL = 0;

    // ACCOUNT 6
    accounts[5].accountNumber = "ACC006";
    accounts[5].password = "cust006";
    accounts[5].accountType = "Checking";
    accounts[5].IBAN = "TN590006";
    accounts[5].branchCode = "BR03";
    accounts[5].holderName = "Sami Chibani";
    accounts[5].openingDate = "2022-04-11";
    accounts[5].status = "active";
    accounts[5].balance = 2300.90;
    accounts[5].PermenantTransaction.head_SLT = nullptr;
    accounts[5].PermenantTransaction.size_SLT = 0;
    accounts[5].dailyTransactions = new Stack;
    accounts[5].dailyTransactions->Top = -1;
    accounts[5].loans.head_DL = nullptr;
    accounts[5].loans.tail_DL = nullptr;
    accounts[5].loans.size_DL = 0;

    // ACCOUNT 7
    accounts[6].accountNumber = "ACC007";
    accounts[6].password = "cust007";
    accounts[6].accountType = "Savings";
    accounts[6].IBAN = "TN590007";
    accounts[6].branchCode = "BR04";
    accounts[6].holderName = "Khalil Aydi";
    accounts[6].openingDate = "2021-10-09";
    accounts[6].status = "active";
    accounts[6].balance = 3670.40;
    accounts[6].PermenantTransaction.head_SLT = nullptr;
    accounts[6].PermenantTransaction.size_SLT = 0;
    accounts[6].dailyTransactions = new Stack;
    accounts[6].dailyTransactions->Top = -1;
    accounts[6].loans.head_DL = nullptr;
    accounts[6].loans.tail_DL = nullptr;
    accounts[6].loans.size_DL = 0;

    // ACCOUNT 8
    accounts[7].accountNumber = "ACC008";
    accounts[7].password = "cust008";
    accounts[7].accountType = "Checking";
    accounts[7].IBAN = "TN590008";
    accounts[7].branchCode = "BR04";
    accounts[7].holderName = "Rania Souiden";
    accounts[7].openingDate = "2020-01-25";
    accounts[7].status = "active";
    accounts[7].balance = 1100.10;
    accounts[7].PermenantTransaction.head_SLT = nullptr;
    accounts[7].PermenantTransaction.size_SLT = 0;
    accounts[7].dailyTransactions = new Stack;
    accounts[7].dailyTransactions->Top = -1;
    accounts[7].loans.head_DL = nullptr;
    accounts[7].loans.tail_DL = nullptr;
    accounts[7].loans.size_DL = 0;

    // ACCOUNT 9
    accounts[8].accountNumber = "ACC009";
    accounts[8].password = "cust009";
    accounts[8].accountType = "Savings";
    accounts[8].IBAN = "TN590009";
    accounts[8].branchCode = "BR05";
    accounts[8].holderName = "Mahdi Abdallah";
    accounts[8].openingDate = "2023-03-03";
    accounts[8].status = "active";
    accounts[8].balance = 4400.00;
    accounts[8].PermenantTransaction.head_SLT = nullptr;
    accounts[8].PermenantTransaction.size_SLT = 0;
    accounts[8].dailyTransactions = new Stack;
    accounts[8].dailyTransactions->Top = -1;
    accounts[8].loans.head_DL = nullptr;
    accounts[8].loans.tail_DL = nullptr;
    accounts[8].loans.size_DL = 0;

    // ACCOUNT 10
    accounts[9].accountNumber = "ACC010";
    accounts[9].password = "cust010";
    accounts[9].accountType = "Checking";
    accounts[9].IBAN = "TN590010";
    accounts[9].branchCode = "BR05";
    accounts[9].holderName = "Selim Ferjani";
    accounts[9].openingDate = "2021-07-12";
    accounts[9].status = "active";
    accounts[9].balance = 1990.60;
    accounts[9].PermenantTransaction.head_SLT = nullptr;
    accounts[9].PermenantTransaction.size_SLT = 0;
    accounts[9].dailyTransactions = new Stack;
    accounts[9].dailyTransactions->Top = -1;
    accounts[9].loans.head_DL = nullptr;
    accounts[9].loans.tail_DL = nullptr;
    accounts[9].loans.size_DL = 0;

    // ACCOUNT 11
    accounts[10].accountNumber = "ACC011";
    accounts[10].password = "cust011";
    accounts[10].accountType = "Savings";
    accounts[10].IBAN = "TN590011";
    accounts[10].branchCode = "BR01";
    accounts[10].holderName = "Lina Ben Ayed";
    accounts[10].openingDate = "2022-05-14";
    accounts[10].status = "active";
    accounts[10].balance = 3050.20;
    accounts[10].PermenantTransaction.head_SLT = nullptr;
    accounts[10].PermenantTransaction.size_SLT = 0;
    accounts[10].dailyTransactions = new Stack;
    accounts[10].dailyTransactions->Top = -1;
    accounts[10].loans.head_DL = nullptr;
    accounts[10].loans.tail_DL = nullptr;
    accounts[10].loans.size_DL = 0;

    // ACCOUNT 12
    accounts[11].accountNumber = "ACC012";
    accounts[11].password = "cust012";
    accounts[11].accountType = "Checking";
    accounts[11].IBAN = "TN590012";
    accounts[11].branchCode = "BR02";
    accounts[11].holderName = "Hamdi Kefi";
    accounts[11].openingDate = "2020-09-21";
    accounts[11].status = "active";
    accounts[11].balance = 1340.90;
    accounts[11].PermenantTransaction.head_SLT = nullptr;
    accounts[11].PermenantTransaction.size_SLT = 0;
    accounts[11].dailyTransactions = new Stack;
    accounts[11].dailyTransactions->Top = -1;
    accounts[11].loans.head_DL = nullptr;
    accounts[11].loans.tail_DL = nullptr;
    accounts[11].loans.size_DL = 0;

    // ACCOUNT 13
    accounts[12].accountNumber = "ACC013";
    accounts[12].password = "cust013";
    accounts[12].accountType = "Savings";
    accounts[12].IBAN = "TN590013";
    accounts[12].branchCode = "BR03";
    accounts[12].holderName = "Salma Chouchene";
    accounts[12].openingDate = "2019-03-11";
    accounts[12].status = "active";
    accounts[12].balance = 6750.00;
    accounts[12].PermenantTransaction.head_SLT = nullptr;
    accounts[12].PermenantTransaction.size_SLT = 0;
    accounts[12].dailyTransactions = new Stack;
    accounts[12].dailyTransactions->Top = -1;
    accounts[12].loans.head_DL = nullptr;
    accounts[12].loans.tail_DL = nullptr;
    accounts[12].loans.size_DL = 0;

    // ACCOUNT 14
    accounts[13].accountNumber = "ACC014";
    accounts[13].password = "cust014";
    accounts[13].accountType = "Checking";
    accounts[13].IBAN = "TN590014";
    accounts[13].branchCode = "BR03";
    accounts[13].holderName = "Zied Mbarek";
    accounts[13].openingDate = "2021-02-02";
    accounts[13].status = "active";
    accounts[13].balance = 870.80;
    accounts[13].PermenantTransaction.head_SLT = nullptr;
    accounts[13].PermenantTransaction.size_SLT = 0;
    accounts[13].dailyTransactions = new Stack;
    accounts[13].dailyTransactions->Top = -1;
    accounts[13].loans.head_DL = nullptr;
    accounts[13].loans.tail_DL = nullptr;
    accounts[13].loans.size_DL = 0;

    // ACCOUNT 15
    accounts[14].accountNumber = "ACC015";
    accounts[14].password = "cust015";
    accounts[14].accountType = "Savings";
    accounts[14].IBAN = "TN590015";
    accounts[14].branchCode = "BR04";
    accounts[14].holderName = "Jihen Dridi";
    accounts[14].openingDate = "2022-11-17";
    accounts[14].status = "active";
    accounts[14].balance = 2500.40;
    accounts[14].PermenantTransaction.head_SLT = nullptr;
    accounts[14].PermenantTransaction.size_SLT = 0;
    accounts[14].dailyTransactions = new Stack;
    accounts[14].dailyTransactions->Top = -1;
    accounts[14].loans.head_DL = nullptr;
    accounts[14].loans.tail_DL = nullptr;
    accounts[14].loans.size_DL = 0;

    // ACCOUNT 16
    accounts[15].accountNumber = "ACC016";
    accounts[15].password = "cust016";
    accounts[15].accountType = "Checking";
    accounts[15].IBAN = "TN590016";
    accounts[15].branchCode = "BR04";
    accounts[15].holderName = "Islem Baccar";
    accounts[15].openingDate = "2023-04-20";
    accounts[15].status = "active";
    accounts[15].balance = 1900.20;
    accounts[15].PermenantTransaction.head_SLT = nullptr;
    accounts[15].PermenantTransaction.size_SLT = 0;
    accounts[15].dailyTransactions = new Stack;
    accounts[15].dailyTransactions->Top = -1;
    accounts[15].loans.head_DL = nullptr;
    accounts[15].loans.tail_DL = nullptr;
    accounts[15].loans.size_DL = 0;

    // ACCOUNT 17
    accounts[16].accountNumber = "ACC017";
    accounts[16].password = "cust017";
    accounts[16].accountType = "Savings";
    accounts[16].IBAN = "TN590017";
    accounts[16].branchCode = "BR05";
    accounts[16].holderName = "Oussama Tlili";
    accounts[16].openingDate = "2018-12-01";
    accounts[16].status = "active";
    accounts[16].balance = 5400.00;
    accounts[16].PermenantTransaction.head_SLT = nullptr;
    accounts[16].PermenantTransaction.size_SLT = 0;
    accounts[16].dailyTransactions = new Stack;
    accounts[16].dailyTransactions->Top = -1;
    accounts[16].loans.head_DL = nullptr;
    accounts[16].loans.tail_DL = nullptr;
    accounts[16].loans.size_DL = 0;

    // ACCOUNT 18
    accounts[17].accountNumber = "ACC018";
    accounts[17].password = "cust018";
    accounts[17].accountType = "Checking";
    accounts[17].IBAN = "TN590018";
    accounts[17].branchCode = "BR05";
    accounts[17].holderName = "Sarra Jouini";
    accounts[17].openingDate = "2020-10-27";
    accounts[17].status = "active";
    accounts[17].balance = 1600.70;
    accounts[17].PermenantTransaction.head_SLT = nullptr;
    accounts[17].PermenantTransaction.size_SLT = 0;
    accounts[17].dailyTransactions = new Stack;
    accounts[17].dailyTransactions->Top = -1;
    accounts[17].loans.head_DL = nullptr;
    accounts[17].loans.tail_DL = nullptr;
    accounts[17].loans.size_DL = 0;

    // ACCOUNT 19
    accounts[18].accountNumber = "ACC019";
    accounts[18].password = "cust019";
    accounts[18].accountType = "Savings";
    accounts[18].IBAN = "TN590019";
    accounts[18].branchCode = "BR01";
    accounts[18].holderName = "Walid Hannachi";
    accounts[18].openingDate = "2019-09-09";
    accounts[18].status = "active";
    accounts[18].balance = 7200.10;
    accounts[18].PermenantTransaction.head_SLT = nullptr;
    accounts[18].PermenantTransaction.size_SLT = 0;
    accounts[18].dailyTransactions = new Stack;
    accounts[18].dailyTransactions->Top = -1;
    accounts[18].loans.head_DL = nullptr;
    accounts[18].loans.tail_DL = nullptr;
    accounts[18].loans.size_DL = 0;

    // ACCOUNT 20
    accounts[19].accountNumber = "ACC020";
    accounts[19].password = "cust020";
    accounts[19].accountType = "Checking";
    accounts[19].IBAN = "TN590020";
    accounts[19].branchCode = "BR02";
    accounts[19].holderName = "Nidhal Miled";
    accounts[19].openingDate = "2021-01-19";
    accounts[19].status = "active";
    accounts[19].balance = 4800.00;
    accounts[19].PermenantTransaction.head_SLT = nullptr;
    accounts[19].PermenantTransaction.size_SLT = 0;
    accounts[19].dailyTransactions = new Stack;
    accounts[19].dailyTransactions->Top = -1;
    accounts[19].loans.head_DL = nullptr;
    accounts[19].loans.tail_DL = nullptr;
    accounts[19].loans.size_DL = 0;

    accountCount = 20;

}
