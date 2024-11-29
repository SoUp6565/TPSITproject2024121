#include "bank.cpp"
#include "user.cpp"
#include "investment.cpp"
#include "bankAccount.cpp"

int main()
{

    bank SanPaolo;
    bankAccount s1("001");
    bankAccount s2("002");
    bankAccount s3("003");
    SanPaolo.createAccountList(s1);
    SanPaolo.createAccountList(s2);
    SanPaolo.createAccountList(s3);

    bank Generali;
    bankAccount g1("001");
    bankAccount g2("002");
    bankAccount g3("003");
    Generali.createAccountList(g1);
    Generali.createAccountList(g2);
    Generali.createAccountList(g3);

    cout << "hi, i will help you with your bank account." << endl;
    cout << "which bank do you want use?(San Paolo = 0 | Generali = 1)" << endl;
    int checkBank;
    cin >> checkBank;
    if (checkBank == 1 || checkBank == 0)
    {
        if (checkBank == 0)
        {
            // san
            cout << "insert your personal code bank" << endl;
            string code;
            cin >> code; // 001/002/003
            user u1(code);
            if (SanPaolo.checkPersonalCode(u1))
            {
                cout << "perfect, account found" << endl;
                cout << "now you can do these operations" << endl;
                cout << "- deposit (code 0)" << endl;
                cout << "- withdraw (code 1)" << endl;
                cout << "- look wallet (code 2)" << endl;
                cout << "- look your personal balance (code 3)" << endl;
                cout << "- do a time-travel (code 4)" << endl;
                cout << "- create an investment (codice 5)" << endl;
                cout << "- look your investment list (code 6)" << endl;
                cout << "do you want execute one of them?(y/n)" << endl;
                char answ;
                cin >> answ;
                if (answ == 'y')
                {
                    while (answ == 'y')
                    {
                        cout << "which one?" << endl;
                        int ans1;
                        cin >> ans1;
                        switch (ans1)
                        {
                        case 0:
                            u1.deposit(SanPaolo);
                            cout << "************************************" << endl;
                            break;
                        case 1:
                            u1.withdraw(SanPaolo);
                            cout << "************************************" << endl;
                            break;
                        case 2:
                            u1.lookWallet();
                            cout << "************************************" << endl;
                            break;
                        case 3:
                            u1.lookPersonalBalance(SanPaolo);
                            cout << "************************************" << endl;
                            break;
                        case 4:
                            SanPaolo.timeTravel(u1);
                            cout << "************************************" << endl;
                            break;
                        case 5:
                            cout << "how much do you want invest" << endl;
                            double qinvest;
                            cin >> qinvest;
                            cout << "duration? (short=0, mid=1, long=2)" << endl;
                            int dur;
                            cin >> dur;
                            if (dur == 0 || dur == 1 || dur == 2)
                            {
                                cout << "risk (low=0, mid=1, high=2)" << endl;
                                int ris;
                                cin >> ris;
                                if (ris == 0 || ris == 1 || ris == 2)
                                {
                                    for (int i = 0; i < SanPaolo.getAccountList().size(); i++)
                                    {
                                        if (SanPaolo.getAccountList().at(i).getPersonalCodeBank() == u1.getPersonalCodeUser())
                                        {
                                            investment invest(qinvest, dur, ris);
                                            SanPaolo.getAccountList().at(i).createInvesmentList(invest);
                                        }
                                    }
                                }
                                else
                                {
                                    cout << "wrong typer of risk " << endl;
                                    return 0;
                                }
                            }
                            else
                            {
                                cout << "wrong type of duration " << endl;
                                return 0;
                            }
                            cout << "************************************" << endl;
                            break;
                        case 6:
                            cout << "investment status:" << endl;
                            for (int i = 0; i < SanPaolo.getAccountList().size(); i++)
                            {
                                if (SanPaolo.getAccountList().at(i).getPersonalCodeBank() == u1.getPersonalCodeUser())
                                {
                                    SanPaolo.getAccountList().at(i).printInvestmentStatus();
                                }
                            }
                            cout << "************************************" << endl;
                            break;
                        default:
                            break;
                        }
                        cout << "now you can do these operations" << endl;
                        cout << "- deposit (code 0)" << endl;
                        cout << "- withdraw (code 1)" << endl;
                        cout << "- look wallet (code 2)" << endl;
                        cout << "- look your personal balance (code 3)" << endl;
                        cout << "- do a time-travel (code 4)" << endl;
                        cout << "- create an investment (codice 5)" << endl;
                        cout << "- look your investment list (code 6)" << endl;
                        cout << "do you want execute another operation?(y/n)" << endl;
                        cin >> answ;
                    }
                }
                else
                {
                    cout << "problems" << endl;
                    return 0;
                }
            }
            else
            {
                cout << "thsere is not this account on this bank" << endl;
                return 0;
            }
        }
        else
        {
            // gen
            cout << "insert your personal code bank" << endl;
            string code;
            cin >> code;
            user u1(code);
            if (Generali.checkPersonalCode(u1))
            {
                cout << "perfect, account found" << endl;
                cout << "now you can do these operations" << endl;
                cout << "- deposit (code 0)" << endl;
                cout << "- withdraw (code 1)" << endl;
                cout << "- look wallet (code 2)" << endl;
                cout << "- look your personal balance (code 3)" << endl;
                cout << "- do a time-travel (code 4)" << endl;
                cout << "- create an investment (codice 5)" << endl;
                cout << "- look your investment list (code 6)" << endl;
                cout << "do you want execute one of them?(y/n)" << endl;
                char answ;
                cin >> answ;
                if (answ == 'y')
                {
                    while (answ == 'y')
                    {
                        cout << "which one?" << endl;
                        int ans1;
                        cin >> ans1;
                        switch (ans1)
                        {
                        case 0:
                            u1.deposit(Generali);
                            cout << "************************************" << endl;
                            break;
                        case 1:
                            u1.withdraw(Generali);
                            cout << "************************************" << endl;
                            break;
                        case 2:
                            u1.lookWallet();
                            cout << "************************************" << endl;
                            break;
                        case 3:
                            u1.lookPersonalBalance(Generali);
                            cout << "************************************" << endl;
                            break;
                        case 4:
                            SanPaolo.timeTravel(u1);
                            cout << "************************************" << endl;
                            break;
                        case 5:
                            cout << "how much do you want invest" << endl;
                            double qinvest;
                            cin >> qinvest;
                            cout << "duration (short=0, mid=1, long=2)" << endl;
                            int dur;
                            cin >> dur;
                            if (dur == 0 || dur == 1 || dur == 2)
                            {
                                cout << "risk (low=0, mid1, high=2)" << endl;
                                int ris;
                                cin >> ris;
                                if (ris == 0 || ris == 1 || ris == 2)
                                {
                                    for (int i = 0; i < Generali.getAccountList().size(); i++)
                                    {
                                        if (Generali.getAccountList().at(i).getPersonalCodeBank() == u1.getPersonalCodeUser())
                                        {
                                            investment invest(qinvest, dur, ris);
                                            Generali.getAccountList().at(i).createInvesmentList(invest);
                                        }
                                    }
                                }
                                else
                                {
                                    cout << "wrong type of risk " << endl;
                                    return 0;
                                }
                            }
                            else
                            {
                                cout << "wrong type of duration " << endl;
                                return 0;
                            }
                            cout << "************************************" << endl;
                            break;
                        case 6:
                            cout << "investment status:" << endl;
                            for (int i = 0; i < SanPaolo.getAccountList().size(); i++)
                            {
                                if (SanPaolo.getAccountList().at(i).getPersonalCodeBank() == u1.getPersonalCodeUser())
                                {
                                    SanPaolo.getAccountList().at(i).printInvestmentStatus();
                                }
                            }
                            cout << "************************************" << endl;
                            break;
                        default:
                            break;
                        }
                        cout << "now you can do these operations" << endl;
                        cout << "- deposit (code 0)" << endl;
                        cout << "- withdraw (code 1)" << endl;
                        cout << "- look wallet (code 2)" << endl;
                        cout << "- look your personal balance (code 3)" << endl;
                        cout << "- do a time-travel (code 4)" << endl;
                        cout << "- create an investment (codice 5)" << endl;
                        cout << "- look your investment list (code 6)" << endl;
                        cout << "do you want execute another operation?(y/n)" << endl;
                        cin >> answ;
                    }
                }
                else
                {
                    cout << "problems" << endl;
                    return 0;
                }
            }
            else
            {
                cout << "thsere is not this account on this bank" << endl;
                return 0;
            }
        }
    }
    else
    {
        cout << "bank not fount" << endl;
    }

    return 0;
}