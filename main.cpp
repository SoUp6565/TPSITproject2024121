#include "bank.cpp"
#include "user.cpp"
#include "investment.cpp"
#include "bankAccount.cpp"


int main(){

    bank SanPolo;
    bankAccount s1("001");
    bankAccount s2("002");
    bankAccount s3("003");

    bank Generali;
    bankAccount g1("001");
    bankAccount g2("002");
    bankAccount g3("003");

    cout<<"ciao, ti aiuterò a gestire il tuo account."<<endl;

    cout<<"in quale banca vuoi operarare?(San Paolo = 0 | Generali = 1)"<<endl;
    int checkBank;
    cin>>checkBank;
    if (checkBank==1 || checkBank==0)
    {
        
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