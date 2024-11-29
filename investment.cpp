#include <ctime>
#include "investment.h"

investment::investment(double q,int d, int r){
    qInvest=q;
    duration=d;
    limit=duration+6;
    riskEarning=r;
    isFinish=true;
}

double investment::payment(){
    srand(time(NULL));

    double perCentDuration{0};
    if (duration==0)
    {
        perCentDuration=(qInvest*1)/100;
    }
    else if (duration==1)
    {
        perCentDuration=(qInvest*5)/100;
    }else if (duration==2)
    {
        perCentDuration=(qInvest*10)/100;
    }
    
    double perCentRiskEarning{0};
    int die;
    if (riskEarning==0)
    {
        die=(rand()%10)+1;
        if (die==1)
        {
            perCentRiskEarning=-1*((qInvest*1)/100);
        }
        else{
            perCentRiskEarning=((qInvest*1)/100);
        }
    }
    else if (riskEarning==1)
    {
        die=(rand()%10)+1;
        if (die<=3)
        {
            perCentRiskEarning=-1*((qInvest*5)/100);
        }
        else{
            perCentRiskEarning=((qInvest*5)/100);
        }
    }
    else if (riskEarning==2)
    {
        die=(rand()%10)+1;
        if (die<=5)
        {
            perCentRiskEarning=-1*((qInvest*10)/100);
        }
        else{
            perCentRiskEarning=((qInvest*10)/100);
        }
    }
    
    return (((qInvest)+(perCentDuration))+(perCentRiskEarning));
}

int investment::getDuration(){
    return duration;
}

int investment::getLimit(){
    return limit;
}

void investment::setLimit(){
    limit-=1;
}

bool investment::getIsFinish(){
    return isFinish;
}

void investment::setIsFinish(){
    isFinish=false;
}

double investment::getQInvest(){
    return qInvest;
}