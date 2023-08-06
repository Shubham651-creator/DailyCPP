#include <iostream>
#include "CurrentAccount.h"

CurrentAccount::CurrentAccount()
{
    currentAccountMinimumQuarterBalance = 500;
    currentType = CurrentAccountType::BASIC;
}

CurrentAccount::CurrentAccount(long number, float balance, float miniBal, CurrentAccountType c_Type)
    : Account(number, balance), currentAccountMinimumQuarterBalance(miniBal), currentType(c_Type)
{
}

CurrentAccount::~CurrentAccount()
{
}

void CurrentAccount::display()
{
    Account::display();
    std::cout << "current account type = "
              << displayCurrentType(currentType)
              << "\n";
}

int CurrentAccount::calculateInterestAmount()
{
    if (currentType == CurrentAccountType::BASIC)
        return Account::getAccountBalance() * 0.06;

    return Account::getAccountBalance() * 0.1;
}

std::string CurrentAccount::displayCurrentType(CurrentAccountType c_type)
{
    if (c_type == CurrentAccountType::BASIC)
        return "BASIC";
    else
        return "PREMIUM";
}
