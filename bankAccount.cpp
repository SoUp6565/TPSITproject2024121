using namespace std;
#include "bankAccount.h"

bankAccount::bankAccount(string pC)
{
    personalCodeBank = pC;
    personalBalance = 0;
    checkForInvestmentList = false;
}

string bankAccount::getPersonalCodeBank()
{
    return personalCodeBank;
}

void bankAccount::setPersonalBalance(double z)
{
    personalBalance = personalBalance + z;
}

double bankAccount::getPersonalBalance()
{
    return personalBalance;
}

void bankAccount::createInvesmentList(investment i)
{
    this->setCheckForInvestmentList(i);
    if (this->checkForInvestmentList == true)
    {
        personalBalance -= i.getQInvest();
        investmentList.push_back(i);
    }
    else
    {
        cout << "you can' t invest, your personal balance is lower than money in your investment" << endl;
        cout << "deposit for invest" << endl;
    }
}

vector<investment> &bankAccount::getInvestmentList()
{
    return investmentList;
}

void bankAccount::setCheckForInvestmentList(investment i)
{
    if (personalBalance >= i.getQInvest())
    {
        checkForInvestmentList = true;
    }
    else
    {
        checkForInvestmentList = false;
    }
}

void bankAccount::printInvestmentStatus()
{
    int counter{1};
    for (size_t i = 0; i < getInvestmentList().size(); i++)
    {
        cout << "***********************" << endl;
        cout << counter << endl;
        counter++;
        cout << "tot invest: " << getInvestmentList().at(i).getQInvest() << endl;
        cout << "duration: " << getInvestmentList().at(i).getDuration() << endl;
        cout << "risk: " << getInvestmentList().at(i).getRisk() << endl;
        cout << "result: " << getInvestmentList().at(i).getResult() << endl;
        if (getInvestmentList().at(i).getLimit() < 0)
        {
            cout << "this investment is finish" << endl;
        }
        else
        {
            cout << "finish in: " << getInvestmentList().at(i).getLimit() << " month/s" << endl;
        }
    }
}