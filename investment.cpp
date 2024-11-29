#include <ctime>
#include "investment.h"

investment::investment(double q, int d, int r)
{
    qInvest = q;
    duration = d;
    if (duration == 0)
    {
        limit = 12;
    }
    else if (duration == 1)
    {
        limit = 60;
    }
    else
    {
        limit = 120;
    }
    riskEarning = r;
    isFinish = true;
    result = 0;
}

double investment::payment()
{
    srand(time(NULL));

    double perCentDuration{0};
    if (duration == 0)
    {
        perCentDuration = (qInvest * 1) / 100;
    }
    else if (duration == 1)
    {
        perCentDuration = (qInvest * 5) / 100;
    }
    else if (duration == 2)
    {
        perCentDuration = (qInvest * 10) / 100;
    }

    double perCentRiskEarning{0};
    int die;
    if (riskEarning == 0)
    {
        die = (rand() % 10) + 1;
        if (die == 1)
        {
            perCentRiskEarning = -1 * ((qInvest * 10) / 100);
        }
        else
        {
            perCentRiskEarning = ((qInvest * 10) / 100);
        }
    }
    else if (riskEarning == 1)
    {
        die = (rand() % 10) + 1;
        if (die <= 3)
        {
            perCentRiskEarning = -1 * ((qInvest * 50) / 100);
        }
        else
        {
            perCentRiskEarning = ((qInvest * 50) / 100);
        }
    }
    else if (riskEarning == 2)
    {
        die = (rand() % 10) + 1;
        if (die <= 5)
        {
            perCentRiskEarning = -1 * ((qInvest * 70) / 100);
        }
        else
        {
            perCentRiskEarning = ((qInvest * 70) / 100);
        }
    }

    cout << "investment is finish" << endl;
    this->setResult((((qInvest) + (perCentDuration)) + (perCentRiskEarning)));
    return (((qInvest) + (perCentDuration)) + (perCentRiskEarning));
}

int investment::getDuration()
{
    return duration;
}

int investment::getLimit()
{
    return limit;
}

void investment::setLimit()
{
    limit -= 1;
}

bool investment::getIsFinish()
{
    return isFinish;
}

void investment::setIsFinish()
{
    isFinish = false;
}

double investment::getQInvest()
{
    return qInvest;
}

int investment::getRisk()
{
    return riskEarning;
}

void investment::setResult(double b)
{
    result = b;
}

double investment::getResult()
{
    return result;
}