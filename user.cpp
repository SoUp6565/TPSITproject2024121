#include "user.h"
#include "bankAccount.h"

user::user(string pcu){
    personalCodeUser=pcu;
    personalWallet=100;
}

string user::getPersonalCodeUser(){
    return personalCodeUser;
}

void user::deposit(bank b){
    if (b.checkPersonalCode(*this))
    {
        cout<<"your wallet: "<<personalWallet<<endl;
        cout<<"how much money do you want to deposit?"<<endl;
        double money;
        cin>>money;
        if (money>personalWallet)
        {
            cout<<"you have less money in your wallet"<<endl;
        }else{
            for (int i = 0; i < b.getAccountList().size(); i++)
            {
                if (b.getAccountList().at(i).getPersonalCodeBank()==personalCodeUser)
                {
                    personalWallet-=money;
                    b.getAccountList().at(i).setPersonalBalance(money);
                }
            }
        }
    }
}

void user::withdraw(bank b){
    if (b.checkPersonalCode(*this))
    {
        cout<<"how much money do you want to withdraw?"<<endl;
        double money;
        cin>>money;
        for (int i = 0; i < b.getAccountList().size(); i++)
        {
            if (b.getAccountList().at(i).getPersonalCodeBank()==personalCodeUser)
            {
                if (money>b.getAccountList().at(i).getPersonalBalance())
                {
                    cout<<"you have less money in your personal balance"<<endl;
                    break;
                }else{
                    personalWallet+=money;
                    b.getAccountList().at(i).setPersonalBalance(-1*(money));
                    break;
                }
            }
        }
    }
}

void user::lookWallet(){
    cout<<"in your wallet there are: "<<personalWallet<<'$'<<endl;
}

void user::lookPersonalBalance(bank b){
    if (b.checkPersonalCode(*this))
    {
        for (int i = 0; i < b.getAccountList().size(); i++)
        {
            if (b.getAccountList().at(i).getPersonalCodeBank()==personalCodeUser)
            {
                cout<<"in your bank account there are: "<<b.getAccountList().at(i).getPersonalBalance()<<'$'<<endl;
                break;
            }
        }
    }
}

void user::setPersonalWallet(double w){
    personalWallet+=w;
}