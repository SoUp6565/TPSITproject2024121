#include "bank.h"

bank::bank(){
    day=0;
}

void bank::createAccountList(bankAccount o){
    accountList.push_back(o);
}

bool bank::checkPersonalCode(user u){
    for (int i = 0; i < accountList.size(); i++)
    {
        if (accountList.at(i).getPersonalCodeBank()==u.getPersonalCodeUser())
        {
            return true;
        }
    }
    return false;
}

vector<bankAccount>& bank::getAccountList(){
    return accountList;
}

void bank::timeTravel(user& u){
    cout<<"day: "<<day;
    cout<<"do you want to do a timetravel(y o n). Every timetravel is 30 days long"<<endl;
    char answer;
    cin>>answer;
    while (answer=='y')
    {
        if (this->checkPersonalCode(u))
        {
            u.setPersonalWallet(100.00);
            for (int i = 0; i < accountList.size(); i++)
            {
                for (int c = 0; c < accountList.at(i).getInvestmentList().size(); c++)
                {
                    if (accountList.at(i).getInvestmentList().at(c).getLimit()==0 && accountList.at(i).getInvestmentList().at(c).getIsFinish()==true)
                    {
                        accountList.at(i).setPersonalBalance(accountList.at(i).getInvestmentList().at(c).payment());
                        accountList.at(i).getInvestmentList().at(c).setIsFinish();
                    }
                    accountList.at(i).getInvestmentList().at(c).setLimit();
                }
            }
        }
        day+=30;
        cout<<"day: "<<day;
        cout<<"do you want to do another timetravel(y o n)"<<endl;
        cin>>answer;
    }
    
    
}