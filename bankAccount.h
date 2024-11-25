
#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include <iostream>
using namespace std;
#include <string>
#include <vector>

#include "investment.h"

    class bankAccount
    {
    private:
        string personalCodeBank;
        double personalBalance;
        vector<investment> investmentList;
        bool checkForInvestmentList;
    public:
        bankAccount(string pC);
        void createInvesmentList(investment i);//m
        string getPersonalCodeBank();
        void setPersonalBalance(double b);
        vector<investment> getInvestmentList();
        double getPersonalBalance();
        void setCheckForInvestmentList();
        ~bankAccount(){};
    };
    
#endif