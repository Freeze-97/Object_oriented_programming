// Tommy Yasi/toya1800
// Created by Admin on 2019-04-09.
// Klass som hanterar uppgofter för ett bankkonto

#ifndef OB_LABB2_KONTO_H
#define OB_LABB2_KONTO_H

#include <string>
class Konto {
private:
    std::string accountNum;
    double balance; // Saldo
    double credit; // Beviljad kredit
public:
    Konto(); // Default konstruktor
    explicit Konto(std::string pAccountNum, double pBalance, double pCredit);

    void deposit(double &amount); // Sätt in pengar
    bool withdraw(double &amount); // Ta ut pengar
    void changeCredit(double &amount); // Ändra beviljad kredit

    // Getfunktioner
    std::string getAccountNum() const {return accountNum;}
    double getBalance() const {return balance;}
    double getCredit() const {return credit;}
    double getDisBalance() const; // Disponibelt belopp
};

#endif //OB_LABB2_KONTO_H
