#include <iostream>
#include "CurrentAccount.h"
#include "SavingAccount.h"

SavingAccount saving1(8980, 5000, SavingAccountType::URBAN);
SavingAccount saving2(99800, 6000, SavingAccountType::SPECIAL);

CurrentAccount current1(4563, 30040, 700, CurrentAccountType::BASIC);
CurrentAccount current2(5563, 60040, 800, CurrentAccountType::BASIC);

int avergeAccountBalance()
{
    int sum = saving1.getAccountBalance() + saving2.getAccountBalance() + current1.getAccountBalance() + current2.getAccountBalance();

    return sum / 4;
}

int highAccountBalance()
{
    int high = saving1.getAccountBalance();

    if (high < saving2.getAccountBalance())
        high = saving2.getAccountBalance();
    if (high < current1.getAccountBalance())
        high = current1.getAccountBalance();
    if (high < current2.getAccountBalance())
        high = current2.getAccountBalance();

    return high;
}

int avergeMiniBalance()
{
    int sum = current1.getAccountMinBalance() + current2.getAccountMinBalance();

    return sum / 2;
}

void totalInterest()
{
    std::cout << current1.calculateInterestAmount() << "\n";
    std::cout << current2.calculateInterestAmount() << "\n";
    std::cout << saving1.calculateInterestAmount() << "\n";
    std::cout << saving2.calculateInterestAmount() << "\n";
}

int main()
{
    std::cout << "The averge of account balance = " << avergeAccountBalance()
              << "\n";

    std::cout << "\nthe hightest balance = " << highAccountBalance()
              << "\n\n";

    std::cout << "totat interest = \n";
    totalInterest();

    return 0;
}