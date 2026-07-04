#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include <iostream>
#include "Account.h"
#include "SavingAccountType.h"

// derive class of Account
class SavingAccount : public Account
{
private:
    enum SavingAccountType savingType;

public:
    // default constructor
    SavingAccount();

    // parameterized constructor
    SavingAccount(long number, float balance, enum SavingAccountType sType);

    // copy construtor
    SavingAccount(SavingAccount &savingAcc);

    /// destructor
    ~SavingAccount();

    // operator=
    void operator=(SavingAccount &savingAcc);

    // special
    int calculateInterestAmount();

    std::string displaySavingType(SavingAccountType check);

    void display();

    enum SavingAccountType getSavingType() const { return savingType; }
    void setSavingType(const enum SavingAccountType &savingType_) { savingType = savingType_; }

    //<< overrloading
    friend void operator<<(std::ostream &out, SavingAccount &savingAcc);
};

#endif // SAVINGACCOUNT_H
