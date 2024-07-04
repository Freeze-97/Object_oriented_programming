// Tommy Yasi/toya1800
// Created by Admin on 2019-04-22.
// Headerfil för klassen Bank

#ifndef OB_LABB2_BANK_H
#define OB_LABB2_BANK_H

#include "bankKund.h"
class Bank{
private:
    std::unique_ptr<BankKund> customer;
public:


    // Setfunktioner
    bool deposit(std::string &accNum, double &ammount);
    bool addAcc(std::string &accountNmb, double &balance, double &credit);
    bool deleteAcc(std::string &accountNmb);
    bool withdraw(std::string &accountNmb, double &amount);
    bool changeCred(std::string &accountNmb, double &amount);
    void createCustomer(std::string &pName, std::string &pSecurityNumber); // Skapa kund

    // File
    void saveFile();
    bool readFile(std::string &pNr);

    // Getfunktioner
    std::string getName() const {return customer->getName();}
    std::string getSecurityNumber() const {return customer->getSecurityNumber();}
    int getNumOfAcc() const {return customer->getNumOfAcc();}
    bool getAccountNums(std::vector<std::string> &vec) const;
    bool getAccountInfo(std::string tmpAccNum, std::vector<double> &vec) const;
    double getTotalAssets() const;
    bool getSummery(std::vector<std::string> &aNr, std::vector<double> &summery) const;
};
#endif //OB_LABB2_BANK_H
