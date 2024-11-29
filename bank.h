#ifndef BANK_H_
#define BANK_H_

#include <iostream>
using namespace std;
#include <string>
#include <vector>

#include "bankAccount.h"
#include "user.h"

class bank
{
private:
    vector<bankAccount> accountList;
    int day;

public:
    bank();
    void createAccountList(bankAccount o);
    bool checkPersonalCode(user u);
    vector<bankAccount> &getAccountList();
    void timeTravel(user &u);
    ~bank() {};
};

#endif
