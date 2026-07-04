#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include "AccountType.h"

class Account
{
private:
    int _id;
    std::string _name;
    AccountType _type;

public:
    Account() = delete;
    Account(const Account &) = delete;
    Account(Account &&) = delete;
    Account &operator=(Account &) = delete;
    Account &operator=(Account &&) = delete;
    explicit Account(int id);
    Account(int id, AccountType type);
    Account(int id, std::string name, AccountType type);
    ~Account() = default;

    int id() const { return _id; }

    std::string name() const { return _name; }

    AccountType type() const { return _type; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
};

std::string DisplayAcountType(AccountType type);

#endif // ACCOUNT_H
