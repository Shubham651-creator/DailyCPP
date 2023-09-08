#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <list>
#include <memory>
#include <functional>
#include "DebitCard.h"

class Account
{
private:
    std::string _number;
    float _min_balance_amount;
    float _current_balance;
    std::shared_ptr<DebitCard> _card;

public:
    // disable default constructor
    Account() = delete;

    // disable copy constructor
    Account(const Account &) = delete;

    // disable copy operator
    Account &operator=(Account &) = delete;

    // disable move constructor
    Account(Account &&) = delete;

    // disable move operator
    Account &operator=(Account &&) = delete;

    // parameterized constructor
    Account(std::string number, float min_balance, float current, std::shared_ptr<DebitCard> card);

    // destructor
    ~Account() = default;

    // a funcition to calculate total interest which is 6% of current balance
    void CalculateTotalInterest();

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);

    std::string number() const { return _number; }

    float minBalanceAmount() const { return _min_balance_amount; }

    float currentBalance() const { return _current_balance; }

    std::shared_ptr<DebitCard> card() const { return _card; }
};

#endif // ACCOUNT_H
