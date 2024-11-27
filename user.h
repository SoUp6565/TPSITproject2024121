
#ifndef USER_H_
#define USER_H_
    #include <iostream>
    #include <string>
    #include <vector>
    using namespace std;

    class bank;
    class user
    {
    private:
        string personalCodeUser;
        double personalWallet;
    public:
        user(string pcu);
        string getPersonalCodeUser();
        void deposit(bank& b);
        void withdraw(bank& b);
        void lookWallet();
        void setPersonalWallet(double);
        void lookPersonalBalance(bank b);
        ~user(){};
    };
    
#endif