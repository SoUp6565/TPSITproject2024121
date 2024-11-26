#include "bank.cpp"
#include "user.cpp"
#include "investment.cpp"
#include "bankAccount.cpp"

//il deposit fotte i soldi
int main(){

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

    cout<<"ciao, ti aiutero' a gestire il tuo account."<<endl;
    cout<<"in quale banca vuoi operarare?(San Paolo = 0 | Generali = 1)"<<endl;
    int checkBank;
    cin>>checkBank;
    if (checkBank==1 || checkBank==0)
    {
        if (checkBank==0)
        {
            //san
            cout<<"inserisci il tuo codice per l' accesso alla banca"<<endl;
            string code;
            cin>>code; // 001/002/003
            user u1(code);
            if (SanPaolo.checkPersonalCode(u1))
            {
                cout<<"perfetto, l' operazione il tuo account e' stato trovato"<<endl;
                cout<<"ecco una lista delle possibili operzioni"<<endl;
                cout<<"- deposito (codice 0)"<<endl;
                cout<<"- prelievo (codice 1)"<<endl;
                cout<<"- guardare il tuo portafoglio (codice 2)"<<endl;
                cout<<"- guardare il tuo conto in banca (codice 3)"<<endl;
                cout<<"- fare un viaggio nel tempo (codice 4)"<<endl;
                cout<<"- creare un investimento (codice 5)"<<endl;
                cout<<"vuoi eseguire uan di queste?(y/n)"<<endl;
                char answ;
                cin>>answ;
                if (answ=='y')
                {
                    while (answ=='y')
                    {
                        cout<<"quale di queste vuoi eseguire?"<<endl;
                        int ans1;
                        cin>>ans1;
                        switch (ans1)
                        {
                        case 0:
                            u1.deposit(SanPaolo);
                            break;
                        case 1:
                            u1.withdraw(SanPaolo);
                            break;
                        case 2:
                            u1.lookWallet();
                            break;
                        case 3:
                            u1.lookPersonalBalance(SanPaolo);
                            break;
                        case 4:
                            SanPaolo.timeTravel(u1);
                            break;
                        case 5:
                            cout<<"quanto vuoi investire"<<endl;
                            double qinvest;
                            cin>>qinvest;
                            cout<<"quanto vuoi che sia la durata (breve=0, media=1, lunga=2)"<<endl;
                            int dur;
                            cin>>dur;
                            if (dur==0 || dur==1 || dur==2)
                            {
                                cout<<"quanto vuoi che sia il rischio (basso=0, medio=1, alto=2)"<<endl;
                                int ris;
                                cin>>ris;
                                if (ris==0 || ris==1 || ris==2)
                                {
                                    for (int i = 0; i < SanPaolo.getAccountList().size(); i++)
                                    {
                                        if (SanPaolo.getAccountList().at(i).getPersonalCodeBank()==u1.getPersonalCodeUser())
                                        {
                                            investment invest(qinvest,dur,ris);
                                            SanPaolo.getAccountList().at(i).createInvesmentList(invest);
                                        }
                                    }
                                }else{
                                    cout<<"rischio errata "<<endl;
                                    return 0;
                                }
                            }else{
                                cout<<"duruta errata "<<endl;
                                return 0;
                            }
                            break;
                        default:
                            break;
                        }
                        cout<<"vuoi eseguire un' altra operazione?"<<endl;
                        cout<<"ecco una lista delle possibili operzioni"<<endl;
                        cout<<"- deposito (codice 0)"<<endl;
                        cout<<"- prelievo (codice 1)"<<endl;
                        cout<<"- guardare il tuo portafoglio (codice 2)"<<endl;
                        cout<<"- guardare il tuo conto in banca (codice 3)"<<endl;
                        cout<<"- fare un viaggio nel tempo (codice 4)"<<endl;
                        cout<<"- creare un investimento (codice 5)"<<endl;
                        cout<<"(y/n)"<<endl;
                        cin>>answ;
                    }
                }else{
                    cout<<"ci sono stati problemi"<<endl;
                    return 0;
                }
            }else{
                cout<<"in questa banca non e' presente questo account"<<endl;
                return 0;
            }
            
        }else{
            //gen
            cout<<"inserisci il tuo codice per l' accesso alla banca"<<endl;
            string code;
            cin>>code;
            user u1(code);
            if (Generali.checkPersonalCode(u1))
            {
                cout<<"perfetto, l' operazione il tuo account e' stato trovato"<<endl;
                cout<<"ecco una lista delle possibili operzioni";
                cout<<"- deposito (codice 0)"<<endl;
                cout<<"- prelievo (codice 1)"<<endl;
                cout<<"- guardare il tuo portafoglio (codice 2)"<<endl;
                cout<<"- guardare il tuo conto in banca (codice 3)"<<endl;
                cout<<"- fare un viaggio nel tempo (codice 4)"<<endl;
                cout<<"- creare un investimento (codice 5)"<<endl;
                cout<<"vuoi eseguire uan di queste?(y/n)"<<endl;
                char answ;
                cin>>answ;
                if (answ=='y')
                {
                    while (answ=='y')
                    {
                        cout<<"quale di queste vuoi eseguire?"<<endl;
                        int ans1;
                        cin>>ans1;
                        switch (ans1)
                        {
                        case 0:
                            u1.deposit(Generali);
                            break;
                        case 1:
                            u1.withdraw(Generali);
                            break;
                        case 2:
                            u1.lookWallet();
                            break;
                        case 3:
                            u1.lookPersonalBalance(Generali);
                            break;
                        case 4:
                            SanPaolo.timeTravel(u1);
                            break;
                        case 5:
                            cout<<"quanto vuoi investire"<<endl;
                            double qinvest;
                            cin>>qinvest;
                            cout<<"quanto vuoi che sia la durata (breve=0, media=1, lunga=2)"<<endl;
                            int dur;
                            cin>>dur;
                            if (dur==0 || dur==1 || dur==2)
                            {
                                cout<<"quanto vuoi che sia il rischio (basso=0, medio=1, alto=2)"<<endl;
                                int ris;
                                cin>>ris;
                                if (ris==0 || ris==1 || ris==2)
                                {
                                    for (int i = 0; i < Generali.getAccountList().size(); i++)
                                    {
                                        if (Generali.getAccountList().at(i).getPersonalCodeBank()==u1.getPersonalCodeUser())
                                        {
                                            investment invest(qinvest,dur,ris);
                                            Generali.getAccountList().at(i).createInvesmentList(invest);
                                        }
                                    }
                                }else{
                                    cout<<"rischio errato "<<endl;
                                    return 0;
                                }
                            }else{
                                cout<<"duruta errata "<<endl;
                                return 0;
                            }
                            break;
                        default:
                            break;
                        }
                        cout<<"vuoi eseguire un' altra operazione?"<<endl;
                        cout<<"ecco una lista delle possibili operzioni"<<endl;
                        cout<<"- deposito (codice 0)"<<endl;
                        cout<<"- prelievo (codice 1)"<<endl;
                        cout<<"- guardare il tuo portafoglio (codice 2)"<<endl;
                        cout<<"- guardare il tuo conto in banca (codice 3)"<<endl;
                        cout<<"- fare un viaggio nel tempo (codice 4)"<<endl;
                        cout<<"- creare un investimento (codice 5)"<<endl;
                        cout<<"(y/n)"<<endl;
                        cin>>answ;
                    }
                }else{
                    cout<<"ci sono stati problemi"<<endl;
                    return 0;
                }
            }else{
                cout<<"in questa banca non e' presente questo account"<<endl;
                return 0;
            }
            
        }
           
    }else{
        while (checkBank!=1 && checkBank!=0)
        {
            cout<<"errore, banca non trovata riprovare"<<endl;
            cout<<"in quale banca vuoi operarare?(San Paolo = 0 | Generali = 1)"<<endl;
            cin>>checkBank;
        }
    }
    
    

    return 0;
}