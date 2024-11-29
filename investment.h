#ifndef INVESTMENT_H_
#define INVESTMENT_H_

#include <iostream>
using namespace std;
#include <string>

class investment
{
private:
    double qInvest;
    int duration; // 0 1 2
    int limit;
    int riskEarning; // 0 1 2
    bool isFinish;
    double result;

public:
    investment(double q, int d, int r);
    int getDuration();
    int getLimit();
    void setLimit();
    double payment();
    bool getIsFinish();
    void setIsFinish();
    double getQInvest();
    void setResult(double b);
    double getResult();
    int getRisk();
    ~investment() {};
};
#endif
