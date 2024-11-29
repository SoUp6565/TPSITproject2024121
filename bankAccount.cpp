#include "bankAccount.h"

bankAccount::bankAccount(string pC){
    personalCodeBank=pC;
    personalBalance=0;
    checkForInvestmentList=false;
}

string bankAccount::getPersonalCodeBank(){
    return personalCodeBank;
}

void bankAccount::setPersonalBalance(double z){
    personalBalance=personalBalance+z;
}

double bankAccount::getPersonalBalance(){
    return personalBalance;
}

void bankAccount::createInvesmentList(investment i){
    this->setCheckForInvestmentList();
    if(this->checkForInvestmentList==true){
        personalBalance-=i.getQInvest();
        investmentList.push_back(i);
    }else{
        cout<<"you can' t invest, your personal balance is lower or equal at 0"<<endl;
        cout<<"deposit for invest"<<endl;
    }
}

vector<investment>& bankAccount::getInvestmentList(){
    return investmentList;
}

void bankAccount::setCheckForInvestmentList(){
    if (personalBalance>0)
    {
        checkForInvestmentList=true;
    }else{
        checkForInvestmentList=false;
    }
}