#include <iostream>
#include "Account.h"

Account::Account()
{
    accountNumber = 37658365;
    accountBalance = 1000.0;
}

Account::Account(long number, float balance)
    : accountNumber(number), accountBalance(balance)
{
}

Account::Account(Account &account)
{
    accountNumber = account.accountNumber;
    accountBalance = account.accountBalance;
}

Account::~Account()
{
}

void Account::operator=(Account &account)
{
    accountNumber = account.accountNumber;
    accountBalance = account.accountBalance;
}

int Account::calculateInterestAmount()
{
    std::cout << "\nI am in account abstract funtion.\n";
    return 0;
}

void Account::display()
{
    std::cout << "The account details are :\n"
              << "account number = " << accountNumber
              << "\naccout balance = " << accountBalance
              << "\n";
}

void operator<<(std::ostream &out, Account &account)
{
    out << "The account details are :"
        << "account number = " << account.accountNumber
        << "accout balance = " << account.accountBalance
        << "\n";
}