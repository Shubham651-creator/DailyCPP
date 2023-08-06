#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include <iostream>
#include "Account.h"
#include "CurrentAccountType.h"

// inheritance from account
class CurrentAccount : public Account
{
private:
    float currentAccountMinimumQuarterBalance;
    enum CurrentAccountType currentType;

public:
    CurrentAccount();
    CurrentAccount(long number, float balance, float miniBal, enum CurrentAccountType c_Type);
    ~CurrentAccount();

    void display();

    // special
    int calculateInterestAmount();

    std::string displayCurrentType(CurrentAccountType c_type);
};

#endif // CURRENTACCOUNT_H
