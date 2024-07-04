// Tommy Yasi/toya1800
// Created by Admin on 2019-04-22.
// Definitionsfil för klassen Bank

#include "bank.h"
using namespace std;

bool Bank::deposit(string &accNum, double &ammount) {
    return customer->depositToAccount(accNum, ammount);
}

bool Bank::addAcc(string &accountNmb, double &balance, double &credit) {
    return customer->addAccount(accountNmb, balance, credit);
}

bool Bank::deleteAcc(string &accountNmb) {
    return customer->deleteAccount(accountNmb);
}

bool Bank::withdraw(string &accountNmb, double &amount) {
    return customer->withdrawal(accountNmb, amount);
}

bool Bank::changeCred(string &accountNmb, double &amount) {
    return customer->changeCredit(accountNmb, amount);
}

void Bank::saveFile() {
    customer->saveToFile();
}

bool Bank::readFile(string &pNr) {
    return customer->readFromFile(pNr);
}

bool Bank::getAccountNums(vector<std::string> &vec) const {
    return customer->getAccountNumbs(vec);
}

bool Bank::getAccountInfo(string tmpAccNum, vector<double> &vec) const {
    return customer->getAccountInfo(move(tmpAccNum), vec);
}

double Bank::getTotalAssets() const {
    return customer->getTotalAssets();
}
bool Bank::getSummery(vector<string> &aNr, vector<double> &summery) const {
    return customer->getSummery(aNr, summery);
}

void Bank::createCustomer(string &pName, string &pSecurityNumber) {
    customer.reset(new BankKund(pName, pSecurityNumber));
    customer->createCustomer(pName, pSecurityNumber);
}