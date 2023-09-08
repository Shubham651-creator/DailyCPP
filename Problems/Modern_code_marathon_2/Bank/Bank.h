#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include "Account.h"
#include "DebitCard.h"

// container which stores account instances
using accountContainer2 = std::shared_ptr<Account>;

class Bank
{
private:
    std::string _name;
    accountContainer2 _accounts_data;

public:
    // disable default constructor
    Bank() = delete;

    // disable copy constructor
    Bank(const Bank &) = delete;

    // disable copy operator
    Bank &operator=(Bank &) = delete;

    // disable move constructor
    Bank(Bank &&) = delete;

    // disable move operator
    Bank &operator=(Bank &&) = delete;

    // parameterized constructor
    Bank(std::string name, accountContainer2 accounts);

    // destructor
    ~Bank() = default;

    std::string name() const { return _name; }

    accountContainer2 accountsData() const { return _accounts_data; }

    friend std::ostream &operator<<(std::ostream &os, const Bank &rhs);
};

#endif // BANK_H
