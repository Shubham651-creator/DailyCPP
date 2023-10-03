#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account
{
private:
    std::string _id;
    float _balance;

public:
    Account() = delete;

    Account(const Account &) = delete;

    Account &operator=(Account &) = delete;

    Account(Account &&) = delete;

    Account &operator=(Account &&) = delete;

    Account(std::string id, float balance);

    ~Account() = default;

    std::string id() const { return _id; }

    float balance() const { return _balance; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
};

#endif // ACCOUNT_H
