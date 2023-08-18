#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include "Transaction.h"
#include <vector>

// every account should have 3 transaction

// vector takes collection of Transaction address as element
using Transactions = std::vector<Transaction *>;

class Account
{
private:
    std::string accountId;
    Transactions accountTransactionSet;
    float accountBalance;

public:
    // default constructor
    Account() = delete;

    // enable parameterized constructor
    Account(std::string id, Transactions set, float balance);

    // disable copy constructor
    Account(const Account &) = delete;

    // disable copy assignment opreator
    Account operator=(Account &) = delete;

    Account(Account &&) = delete;
    Account operator=(Account &&) = delete;

    // enable destructor
    ~Account() = default;

    // getter and setter of attributes

    std::string getAccountId() const { return accountId; }
    void setAccountId(const std::string &accountId_) { accountId = accountId_; }

    Transactions getAccountTransactionSet() const { return accountTransactionSet; }
    void setAccountTransactionSet(const Transactions &accountTransactionSet_) { accountTransactionSet = accountTransactionSet_; }

    float getAccountBalance() const { return accountBalance; }
    void setAccountBalance(float accountBalance_) { accountBalance = accountBalance_; }

    // display the account information
    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
};

#endif // ACCOUNT_H
