// Tommy Yasi/toya1800
// Created by Admin on 2019-05-02.
// TestProgram funktionsfil

#include "testProgram.h"
using namespace std;

void TestProgram::run() {
    bool again = true;
    do {
        printPreMenu();
        int choice;
        cin >> choice;
        cin.get();
        switch (choice) {
            case 1: if(loadCustomerFromFile())
                      again = false;
                break;
            case 2:
                createNewCostumer();
                menuChoice();
                again = false;
                break;
            case 3:
                again = false;
                break;
            default:
                cout << "Invalid output!" << endl;
        }
    }while (again);
}

void TestProgram::printPreMenu() {
    cout << "1. Load customer from file." << endl;
    cout << "2. Create a new customer." << endl;
    cout << "3. quit" << endl;
}

void TestProgram::printMenu() {
    cout << "---MENU---" << endl;
    cout << "1. Customer name." << endl;
    cout << "2. Customer persnr." << endl;
    cout << "3. Number of accounts." << endl;
    cout << "4. Account numbers." << endl;
    cout << "5. Total assets." << endl;
    cout << "6. account info." << endl;
    cout << "7. Withdraw." << endl;
    cout << "8. Deposit." << endl;
    cout << "9. Set credit." << endl;
    cout << "10. Accounts summery" << endl;
    cout << "11. Create new account." << endl;
    cout << "12. Delete account." << endl;
    cout << "13. Change customer." << endl;
    cout << "14. quit" << endl;
}

bool TestProgram::loadCustomerFromFile() {
    string pNr;
    cout << "Put PersonNr: " << endl;
    getline(cin, pNr);
    if(!bank.readFile(pNr)) {
        cout << "Could not load file!" << endl;
        return false;
    }
    return true;
}

void TestProgram::createNewCostumer() {
    cout << "Name: " << endl;
    string fullName;
    getline(cin, fullName);

    cout << "PersonNr: " << endl;
    string persNr;
    getline(cin, persNr);
    bank.createCustomer(fullName, persNr);
}

void TestProgram::customerName() {
    cout << "Name: " << bank.getName() << endl;
}

void TestProgram::customerSecurityNum() {
    cout << "Security number: " << bank.getSecurityNumber() << endl;
}

void TestProgram::numOfAccs() {
    cout << "Number of accounts: " << bank.getNumOfAcc() << endl;
}

void TestProgram::printAccNums() {
    vector<string> accNums;
    if(!bank.getAccountNums(accNums)){
        cout << "You don't have any accounts" << endl;
        return;
    }
    cout << "ACCOUNT NUMBERS: " << endl;

    int i = 0;
    for(const auto &e: accNums) {
        cout << accNums[i] << endl;
        i++;
    }
}

void TestProgram::printTotalAssets() {
    cout << "Total assets: " << bank.getTotalAssets() << endl;
}

void TestProgram::printAccountInfo() {
    printAccNums();
    if(bank.getNumOfAcc() == 0) {
        return;
    }
    cout << "Insert security numbber for the account you want a summery of: " << endl;
    string persNum;
    getline(cin, persNum);

    vector<double> accInfo; // Lagra credit, balance och disbalance
    if(!bank.getAccountInfo(persNum, accInfo)) {
        cout << "Invalid input, input does not match any accounts" << endl;
    }
    cout << "Balance: " << accInfo[0] << endl;
    cout << "Credit: " << accInfo[1] << endl;
    cout << "Disposable: " << accInfo[2] << endl;
}

void TestProgram::withdraw() {
    printAccNums();
    if(bank.getNumOfAcc() == 0) {
        return;
    }
    cout << "From which account do you want to withdraw: " << endl;
    string persNum;
    getline(cin, persNum);

    cout << "Amount to withdraw: " << endl;
    double withdraw;
    cin >> withdraw;
    cin.get();
    if(!bank.withdraw(persNum, withdraw)) {
        cout << "Withdrawal failed! Either account could not be found or you can't take out that much." << endl;
        return;
    }
    cout << withdraw << " has been withdrawn." << endl;
}

void TestProgram::deposit() {
    printAccNums();
    if(bank.getNumOfAcc() == 0) {
        return;
    }
    cout << "From which account do you want to deposit: " << endl;
    string persNum;
    getline(cin, persNum);

    cout << "Amount to deposit: " << endl;
    double deposit;
    cin >> deposit;
    cin.get();
    bank.deposit(persNum, deposit);
    cout << deposit << " has been deposited to account " << persNum << endl;
}

void TestProgram::setCredit() {
    printAccNums();
    if(bank.getNumOfAcc() == 0) {
        return;
    }
    cout << "From which account do you want to change credit: " << endl;
    string persNum;
    getline(cin, persNum);

    cout << "Change credit to: " << endl;
    double credit;
    cin >> credit;
    cin.get();
    bank.changeCred(persNum, credit);
    cout << "Changed credit to " << credit << " on account " << persNum << endl;
}

void TestProgram::summary() {
    if(bank.getNumOfAcc() == 0) {
        cout << "You don't have any accounts" << endl;
        return;
    }
    vector<string> aNr; // Lagra kontonummer
    vector<double> summery; // Lagra sumemring av credit, balance och disbalance
    bank.getSummery(aNr, summery);

    for (const auto &i : aNr) {
        vector<double> accInfo; // Lagra siffror för enskilda konton
        if(!bank.getAccountInfo(i, accInfo)) {
            cout << "You don't have any accounts" << endl;
            return;
        }
        cout << "ACCOUNT: " << i << endl;
        cout << "Balance: " << accInfo[0] << endl;
        cout << "Credit: " << accInfo[1] << endl;
        cout << "Disposable: " << accInfo[2] << endl << endl;
    }
    cout << "SUMMERY" << endl;
    cout << "Balance: " << summery[0] << endl;
    cout << "Credit: " << summery[1] << endl;
    cout << "Disposable: " << summery[2] << endl;
}

void TestProgram::createNewAccount() {
    cout << "Type account number: " << endl;
    string accNum;
    getline(cin, accNum);

    cout << "Amount of balance: " << endl;
    double balance;
    cin >> balance;
    cin.get();

    cout << "Amount of credit: " << endl;
    double credit;
    cin >> credit;
    cin.get();

    if(!bank.addAcc(accNum, balance, credit)) {
        cout << "You already have 3 accounts!" << endl;
        return;
    }
    cout << "Account has been created!" << endl;
}

void TestProgram::deleteAcc() {
    printAccNums();
    if(bank.getNumOfAcc() == 0) {
        return;
    }
    cout << "Account you want to delete: " << endl;
    string accNum;
    getline(cin, accNum);

    if(!bank.deleteAcc(accNum)) {
        cout << "Could not delete account!" << endl;
        return;
    }
    cout << "Account has been deleted!" << endl;
}

void TestProgram::menuChoice() {
    bool again = true;
    do {
        printMenu();
        int choice;
        cin >> choice;
        cin.get();
        switch(choice) {
            case 1: customerName();
                break;
            case 2: customerSecurityNum();
                break;
            case 3: numOfAccs();
                break;
            case 4: printAccNums();
                break;
            case 5: printTotalAssets();
                break;
            case 6: printAccountInfo();
                break;
            case 7: withdraw();
                break;
            case 8: deposit();
                break;
            case 9: setCredit();
                break;
            case 10: summary();
                break;
            case 11: createNewAccount();
                break;
            case 12: deleteAcc();
                break;
            case 13: run();
                break;
            case 14: again = false;
                break;
            default: cout << "Invalid input!" << endl;

        }
    }while(again);
}
