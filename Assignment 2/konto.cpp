// Tommy Yasi/toya1800
// Created by Admin on 2019-04-10.
// Definitionsfil för klassen Konto
#include "konto.h"

Konto::Konto() {
    accountNum = " ";
    balance = 0;
    credit = 0;
}
Konto::Konto(std::string pAccountName, double pBalance, double pCredit) {
    accountNum = move(pAccountName);
    balance = pBalance;
    credit = pCredit;
}
void Konto::deposit(double &amount) {
    balance += amount;
}
bool Konto::withdraw(double &amount) {
    if(amount > balance + credit) { // Om man vill ta ut mer än vad man kan
        return false;
    }
    if(balance <= 0 && amount <= credit) {
        credit -= amount;
    }
    else if(amount <= balance + credit && balance > 0) {
        double tmpBalance = balance;
        balance -= amount;
        if(balance < 0 && tmpBalance > 0) {
            credit -= tmpBalance - amount;
        }
        else if(balance < 0) {
            credit -= amount;
        }
    }
    return true;
}
void Konto::changeCredit(double &amount) {
    credit = amount;
}
double Konto::getDisBalance() const {
    if(balance > 0) {
        return balance + credit;
    }
    else {
        return credit;
    }
}

