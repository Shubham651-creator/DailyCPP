#include <iostream>
#include "SavingAccount.h"

SavingAccount::SavingAccount()
{
    savingType = SavingAccountType::METRO;
}

SavingAccount::SavingAccount(long number, float balance, SavingAccountType sType)
    : Account(number, balance), savingType(sType)
{
}

SavingAccount::SavingAccount(SavingAccount &savingAcc)
{
    Account::setAccountNumber(savingAcc.getAccountNumber());
    Account::setAccountBalance(savingAcc.getAccountBalance());
    savingType = savingAcc.savingType;
}

SavingAccount::~SavingAccount()
{
}

void SavingAccount::operator=(SavingAccount &savingAcc)
{
    Account::setAccountNumber(savingAcc.getAccountNumber());
    Account::setAccountBalance(savingAcc.getAccountBalance());
    savingType = savingAcc.savingType;
}

int SavingAccount::calculateInterestAmount()
{
    if (savingType == SavingAccountType::SPECIAL)
    {
        return getAccountBalance() * 0.07;
    }

    return getAccountBalance() * 0.05;
}

std::string SavingAccount::displaySavingType(SavingAccountType check)
{
    if (check == SavingAccountType::METRO)
        return "METRO";
    if (check == SavingAccountType::URBAN)
        return "URBAN";

    return "SPECIAL";
}

void SavingAccount::display()
{
    Account::display();
    std::cout << "the saving account type = "
              << displaySavingType(savingType)
              << "\n";
}

void operator<<(std::ostream &out, SavingAccount &savingAcc)
{
}