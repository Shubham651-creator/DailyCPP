#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <functional>
#include<memory>
#include "Account.h"

using Pointer = std::shared_ptr<Account>;
using RefType = std::reference_wrapper<Pointer>;

class Customer
{
private:
    std::string _customerName{""};
    int _age{-1};
    RefType _account ;

public:
    Customer()= default;
    Customer(const Customer &) = delete;
    Customer(const Customer &&) = delete;
    Customer &operator=(Customer &) = delete;
    Customer &operator=(Customer &&) = delete;
    
    explicit Customer(std::string customerName);
    Customer(std::reference_wrapper<std::shared_ptr<Account>> account, std::string customerName, int age);
    ~Customer() = default;

    std::string customerName() const { return _customerName; }

    int age() const { return _age; }

    std::reference_wrapper<std::shared_ptr<Account>> account() const { return _account; }

    friend std::ostream &operator<<(std::ostream &os, const Customer &rhs);
};

#endif // CUSTOMER_H
